from zone import Zone
from connection import Connection


class Network:
    """Represents the network of zones and connections"""
    def __init__(self, nb_drones: int) -> None:
        """Initialize an empty network with the given drone count"""
        self.nb_drones = nb_drones
        self.zones: dict[str, Zone] = {}
        self.connection: list[Connection] = []
        self.start_zone: Zone | None = None
        self.end_zone: Zone | None = None

    def add_zone(self, zone: Zone) -> None:
        """Add a zone, rejecting duplicate names"""
        if zone.name in self.zones:
            raise ValueError(f"Duplicate zone name: {zone.name}")
        
        self.zones[zone.name] = zone

    def add_connection(self, connection: Connection) -> None:
        """Add a connection between two zones in the network"""
        zone1 = connection.zone1
        zone2 = connection.zone2

        if (self.zones.get(zone1.name) is not zone1 or self.zones.get(zone2.name) is not zone2):
            raise ValueError("Both zones must belong to the network")
        
        for existing in self.connections:
            if ((existing.zone1 is zone1 and existing.zone2 is zone2)
                or (existing.zone1 is zone2 and existing.zone2 is zone1)):
                    raise ValueError(f"Duplicate connection {connection.name}")

        self.connections.append(connection)
        zone1.neighbors.append(connection)
        if zone2 is not zone1:
             zone2.neighbors.append(connection)

    def set_start_zone(self, zone: Zone) -> None:
        """Set the network's start zone"""
        if self.start_zone is not None:
            raise ValueError("Start zone already defined.")

        if self.zones.get(zone.name) is not zone:
            raise ValueError("Start zone must belong to the network.")

        self.start_zone = zone

    def set_end_zone(self, zone: Zone) -> None:
            """Set the network's end zone"""
            if self.end_zone is not None:
                raise ValueError("End zone already defined.")
    
            if self.zones.get(zone.name) is not zone:
                raise ValueError("End zone must belong to the network.")
    
            self.end_zone = zone

    def validate(self) -> None:
        """Check the drone count and required start and end zones"""
        if self.nb_drones <= 0:
            raise ValueError("Drone count must be positive.")

        if self.start_zone is None:
            raise ValueError("Missing start zone.")

        if self.end_zone is None:
            raise ValueError("Missing end zone.")

        if self.start_zone is self.end_zone:
            raise ValueError("Start and end zones must be different.")
