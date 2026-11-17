from zone import Zone
from connection import Connection


class Drone:
    """Represent a drone and its current position"""
    def __init__(self, drone_id: int, start_zone: Zone) -> None:
        """Initialize the drone and its starting zone"""
        self.drone_id = drone_id
        self.current_zone: Zone | None = start_zone
        self.destination: Zone | None = None
        self.connection: Connection | None = None
        self.remaining_turns: int = 0
