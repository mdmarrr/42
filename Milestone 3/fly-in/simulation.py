from connection import Connection
from drone import Drone
from network import Network
from pathfinder import Pathfinder
from visualization import TerminalColors
from zone import Zone
from zone_type import ZoneType


class Simulation:
    """Move all drones along one route, respecting capacities."""

    def __init__(self, network: Network) -> None:
        if network.start_zone is None or network.end_zone is None:
            raise ValueError("Map must have a start and end zone.")

        self.network = network
        self.start_zone = network.start_zone
        self.end_zone = network.end_zone

        self.drones = [
            Drone(drone_id, self.start_zone)
            for drone_id in range(1, network.nb_drones + 1)
        ]

        self.current_turn = 0
        self.path: list[Zone] = []
        self.path_links: list[Connection] = []
        self.path_indices = {drone.drone_id: 0 for drone in self.drones}

        self.zone_occupancy: dict[Zone, int] = {
            self.start_zone: len(self.drones),
        }
        self.connection_occupancy: dict[Connection, int] = {}
        self.connection_releases: dict[int, list[Connection]] = {}
        self.in_transit: dict[int, int] = {}
        self.arrival_turns: dict[int, int] = {}

        self.movement_log: dict[int, list[str]] = {}
        self.movement_colors: dict[int, list[str | None]] = {}

    def calculate_path(self) -> None:
        """Find the shared route and its connections."""
        pathfinder = Pathfinder(self.network)
        path = pathfinder.find_path(self.start_zone, self.end_zone)

        if not path:
            raise ValueError("No route from start to goal.")

        self.path = path
        self.path_links = [
            self.get_link(origin, destination)
            for origin, destination in zip(path, path[1:])
        ]

    def get_link(self, origin: Zone, destination: Zone) -> Connection:
        """Return the connection between two consecutive zones."""
        for link in origin.neighbors:
            if link.zone1 is origin and link.zone2 is destination:
                return link
            if link.zone2 is origin and link.zone1 is destination:
                return link

        raise ValueError("Missing connection between consecutive zones.")

    def has_zone_capacity(self, zone: Zone) -> bool:
        if zone is self.start_zone or zone is self.end_zone:
            return True

        return self.zone_occupancy.get(zone, 0) < zone.max_drones

    def record_movement(
        self, drone_id: int, location: str, color: str | None,
    ) -> None:
        self.movement_log.setdefault(self.current_turn, []).append(
            f"D{drone_id}-{location}"
        )
        self.movement_colors.setdefault(self.current_turn, []).append(color)

    def land(self, drone: Drone, zone: Zone) -> None:
        """Finish a move into a zone whose capacity was reserved."""
        drone_id = drone.drone_id
        drone.current_zone = zone
        self.path_indices[drone_id] += 1
        self.record_movement(drone_id, zone.name, zone.color)

        if zone is self.end_zone:
            self.arrival_turns[drone_id] = self.current_turn

    def try_move_drone(self, drone: Drone) -> None:
        drone_id = drone.drone_id

        if drone_id in self.arrival_turns or drone_id in self.in_transit:
            return

        index = self.path_indices[drone_id]
        origin = self.path[index]
        destination = self.path[index + 1]
        link = self.path_links[index]

        if not self.has_zone_capacity(destination):
            return

        link_usage = self.connection_occupancy.get(link, 0)
        if link_usage >= link.max_link_capacity:
            return

        restricted = destination.zone_type == ZoneType.RESTRICTED
        duration = 2 if restricted else 1

        self.zone_occupancy[origin] -= 1
        self.zone_occupancy[destination] = (
            self.zone_occupancy.get(destination, 0) + 1
        )
        self.connection_occupancy[link] = link_usage + 1

        release_turn = self.current_turn + duration
        self.connection_releases.setdefault(release_turn, []).append(link)

        if restricted:
            drone.current_zone = None
            self.in_transit[drone_id] = self.current_turn + 1
            self.record_movement(drone_id, link.name, destination.color)
        else:
            self.land(drone, destination)

    def release_connections(self) -> None:
        for link in self.connection_releases.pop(self.current_turn, []):
            self.connection_occupancy[link] -= 1

    def complete_transits(self) -> None:
        for drone in self.drones:
            drone_id = drone.drone_id
            if self.in_transit.get(drone_id) != self.current_turn:
                continue

            del self.in_transit[drone_id]
            destination = self.path[self.path_indices[drone_id] + 1]
            self.land(drone, destination)

    def run_turn(self) -> None:
        ordered_drones = sorted(
            self.drones,
            key=lambda drone: self.path_indices[drone.drone_id],
            reverse=True,
        )

        for drone in ordered_drones:
            self.try_move_drone(drone)

    def run(self) -> None:
        if self.start_zone is self.end_zone:
            self.arrival_turns.update(
                (drone.drone_id, 0) for drone in self.drones
            )
            return

        self.calculate_path()

        while len(self.arrival_turns) < len(self.drones):
            self.current_turn += 1
            self.release_connections()
            self.run_turn()
            self.complete_transits()

            if (
                not self.movement_log.get(self.current_turn)
                and not self.in_transit
            ):
                raise ValueError("No drone can advance on the chosen route.")

    def generate_output(self) -> list[str]:
        return [
            " ".join(self.movement_log.get(turn, []))
            for turn in range(1, self.current_turn + 1)
        ]

    def generate_colored_output(self, colors: TerminalColors) -> list[str]:
        return [
            " ".join(
                colors.colorize(text, color)
                for text, color in zip(
                    self.movement_log.get(turn, []),
                    self.movement_colors.get(turn, []),
                )
            )
            for turn in range(1, self.current_turn + 1)
        ]

    def generate_summary(self) -> str:
        summary = (
            f"Total turns: {self.current_turn}\n"
            f"Drones delivered: {len(self.arrival_turns)}/{len(self.drones)}"
        )

        if not self.arrival_turns:
            return summary

        turns = self.arrival_turns.values()
        return (
            f"{summary}\n"
            f"Turns per drone - min: {min(turns)}, max: {max(turns)}, "
            f"avg: {sum(turns) / len(turns):.1f}"
        )