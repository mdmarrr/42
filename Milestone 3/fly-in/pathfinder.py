from network import Network
from zone import Zone
from zone_type import ZoneType
from heapq import heappop, heappush
from itertools import count


class Pathfinder:
    """Find routes through the drone network"""

    def __init__(self, network: Network) -> None:
        """Store the network used to search for routes"""

        self.network = network

    def find_path(self, start: Zone, end: Zone) -> list[Zone]:
        """Find a path with the fewest connections, avoiding blocked zones"""
        if start.zone_type == ZoneType.BLOCKED or end.zone_type == ZoneType.BLOCKED:
            return []

        order = count()
        queue: list[tuple[int, int, int, Zone]] = [(0, 0, next(order), start)]
        distances: dict[Zone, tuple[int, int]] = {start: (0, 0)}
        previous: dict[Zone, Zone | None] = {start: None}

        while queue:
            turns, preference, _, current = heappop(queue)

            if (turns, preference) != distances[current]:
                continue

            if current is end:
                path: list[Zone] = []
                zone: Zone | None = end

                while zone is not None:
                    path.append(zone)
                    zone = previous[zone]

                path.reverse()
                return path

            for neighbor in current.get_neighboring_zones():
                if neighbor.zone_type == ZoneType.BLOCKED:
                    continue

                movement_cost = (
                    2 if neighbor.zone_type == ZoneType.RESTRICTED else 1
                )

                priority_bonus = (
                    1 if neighbor.zone_type == ZoneType.PRIORITY else 0
                )

                new_cost = (
                    turns + movement_cost,
                    preference - priority_bonus
                )

                old_cost = distances.get(neighbor)

                if old_cost is None or new_cost < old_cost:
                    distances[neighbor] = new_cost
                    previous[neighbor] = current
                    heappush(queue, (*new_cost, next(order), neighbor))

        return []
