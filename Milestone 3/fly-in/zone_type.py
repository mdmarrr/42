from enum import Enum


class ZoneType(Enum):
    """Represents the supported zone types"""
    NORMAL = "normal"
    BLOCKED = "blocked"
    RESTRICTED = "restricted"
    PRIORITY = "priority"
