from network import Network
from zone import Zone
from zone_type import ZoneType
from connection import Connection


class MapParser:
    def __init__(self, file_path: str) -> None:
        self.file_path = file_path

    def parse(self) -> Network:
        network: Network | None = None

        with open(self.file_path, "r", encoding="utf-8") as file:
            for line_number, line in enumerate(file, start = 1):
                line = line.split("#", 1)[0].strip()

                if not line:
                    continue

                key, separator, value = line.partition(":")
                key = key.strip()
                value = value.strip()

                if not separator:
                    raise ValueError(f"Line {line_number}: missing ':'.")

                if key == "nb_drones":
                    if network is not None:
                        raise ValueError("Duplicate nb_drones.")

                    network = Network(self._parse_nb_drones(value))

                elif key in ("start_hub", "hub", "end_hub"):
                    if network is None:
                        raise ValueError("nb_drones must appear first.")

                    self._parse_zone(key, value, network)

                elif key == "connection":
                    if network is None:
                        raise ValueError("nb_drones must appear first.")
                    
                    self._parse_connection(value, network)

                else:
                    raise ValueError(f"Line {line_number}: unknown key '{key}'.")

        if network is None:
            raise ValueError("Missing nb_drones.")

        self._validate(network)
        return network

    def _parse_nb_drones(self, value: str) -> int:
        try:
            nb_drones = int(value)
        except ValueError:
            raise ValueError("nb_drones must be an integer.") from None

        if nb_drones <= 0:
            raise ValueError("nb_drones must be positive.")

        return nb_drones

    def _parse_attributes(self, text: str) -> dict[str, str]:
        attributes: dict[str, str] = {}

        for item in text.split():
            key, separator, value = item.partition("=")

            if not separator or not key or not value:
                raise ValueError("Invalid attribute: '{item}'.")

            if key in attributes:
                raise ValueError("Duplicate attribute '{key}'.")

            attributes[key] = value

        return attributes

    def _parse_zone(self, key: str, value: str, network: Network) -> None:
        data, separator, metadata = value.partition("[")
        attributes: dict[str, str] = {}

        if separator:
            if ("]" in data or not metadata.endswith("]") or "[" in metadata or "]" in metadata[:-1]):
                raise ValueError("Invalid zone attributes.")

            attributes = self._parse_attributes(metadata[:-1])

        if "]" in data:
                    raise ValueError("Unexpected ']'.")

        if attributes.keys() - {"zone", "color", "max_drones"}:
            raise ValueError("Unknown zone attribute.")

        parts = data.split()

        if len(parts) != 3:
            raise ValueError("A zone requires name, x and y.")

        name, x_text, y_text = parts

        try:
            x = int(x_text)
            y = int(y_text)
            max_drones = int(attributes.get("max_drones", "1"))
        except ValueError:
            raise ValueError("Coordinates and max_drones must be integers.") from None

        if max_drones <= 0:
            raise ValueError("max_drones must be positive.")

        zone_type = ZoneType(attributes.get("zone", "normal"))

        if key in ("start_hub", "end_hub"):
            max_drones = network.nb_drones

        zone = Zone(
            name = name,
            x = x,
            y = y,
            zone_type = zone_type,
            color = attributes.get("color"),
            max_drones = max_drones,
        )

        network.add_zone(zone)

        if key == "start_hub":
            network.set_start_zone(zone)
        elif key == "end_hub":
            network.set_end_zone(zone)

    def _parse_connection(self, value: str, network: Network) -> None:
        data, separator, metadata = value.partition("[")
        attributes: dict[str, str] = {}

        if separator:
            if ("]" in data or not metadata.endswith("]") or "[" in metadata or "]" in metadata[:-1]):
                raise ValueError("Invalid connection attributes.")

            attributes = self._parse_attributes(metadata[:-1])

        if "]" in data:
            raise ValueError("Unexpected ']'.")

        if attributes.keys() - {"max_link_capacity"}:
            raise ValueError("Unknown connection attribute.")

        parts = data.strip().split("-")

        if len(parts) != 2 or not all(parts):
            raise ValueError("A connetion requires name1 - name2.")

        name1, name2 = parts

        if name1 not in network.zones or name2 not in network.zones:
            raise ValueError("Connection references an unknown zone.")

        try:
            capacity = int(attributes.get("max_link_capacity", "1"))
        except ValueError:
            raise ValueError("max_link_capacity must be an integer.") from None

        if capacity <= 0:
            raise ValueError("max_link_capacity must be positive.")

        connection = Connection(
            zone1 = network.zones[name1],
            zone2 = network.zones[name2],
            max_link_capacity = capacity,
        )

        network.add_connection(connection)

    def _validate(self, network: Network) -> None:
        if network.start_zone is None:
            raise ValueError("Missing start_hub.")

        if network.end_zone is None:
            raise ValueError("Missing end_hub.")

        if network.start_zone is network.end_zone:
            raise ValueError("Start and end zones must be different.")

        if network.start_zone.zone_type == ZoneType.BLOCKED:
            raise ValueError("Start zone cannot be blocked.")

        if network.end_zone.zone_type == ZoneType.BLOCKED:
            raise ValueError("End zone cannot be blocked.")
