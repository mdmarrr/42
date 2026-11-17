from parser import MapParser
from pathfinder import Pathfinder
from zone_type import ZoneType
from simulation import Simulation
from network import Network
from pathfinder import Pathfinder


def main() -> None:
    network = MapParser("maps/easy/01_linear_path.txt").parse()

    print(f"Drones: {network.nb_drones}")
    print(f"Connections: {len(network.connection)}")
    print(f"Zones: {list(network.zones)}")

    if network.start_zone is None or network.end_zone is None:
        raise ValueError("Missing start or end zone.")

    print(f"Start: {network.start_zone.name}")
    print(f"End: {network.end_zone.name}")

    pathfinder = Pathfinder(network)
    path = pathfinder.find_path(network.start_zone, network.end_zone)

    if not path:
        raise ValueError("Missing path.")

    print("Path:", " -> ".join(zone.name for zone in path))

    turns = sum(
        2 if zone.zone_type == ZoneType.RESTRICTED else 1
        for zone in path[1:]
    )
    print(f"Individual path turns: {turns}")

    simulation = Simulation(network)
    simulation.run()

    for line in simulation.generate_output():
        print(line)

    print(f"Total simulation turns: {simulation.current_turn}")

if __name__ == "__main__":
    main()
