#!/usr/bin/env python3


from abc import ABC, abstractmethod
from typing import Any, Dict, List, Union, Tuple, Protocol


class DataProcessor(ABC):
    def __init__(self):
        self._data_queue: List[tuple[int, str]] = []
        self._counter = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self._data_queue:
            return 0, ""
        rank, value = self._data_queue.pop(0)
        return rank, value


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            return all(isinstance(x, (int, float)) for x in data)
        return False

    def ingest(self, data: Union[int, float, List[Union[int, float]]]) -> None:
        if not self.validate(data):
            raise ValueError(" Got exception: Improper numeric data")
        if isinstance(data, (int, float)):
            data = [data]
        for x in data:
            self._counter += 1
            self._data_queue.append((self._counter, str(x)))


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return not data.isdigit()
        elif isinstance(data, list):
            return all(isinstance(x, str) and not x.isdigit() for x in data)
        return False

    def ingest(self, data: Union[str, List[str]]) -> None:
        if not self.validate(data):
            raise ValueError(" Got exception: Improper text data")
        if isinstance(data, str):
            data = [data]
        for x in data:
            self._counter += 1
            self._data_queue.append((self._counter, str(x)))


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return all(isinstance(k, str)
                       and isinstance(v, str) for k, v in data.items())
        elif isinstance(data, list):
            return all(isinstance(d, dict)
                       and all(isinstance(k, str)
                               and isinstance(v, str)
                               for k, v in d.items()) for d in data)
        return False

    def ingest(
            self, data: Union[Dict[str, str], List[Dict[str, str]]]
            ) -> None:
        if not self.validate(data):
            raise ValueError(" Got exception: Improper dict data")
        if isinstance(data, dict):
            data = [data]
        for entry in data:
            self._counter += 1
            log_level = entry.get('log_level', '')
            log_message = entry.get('log_message', '')
            formatted = f"{log_level}: {log_message}"
            self._data_queue.append((self._counter, formatted))


class ExportPlugin(Protocol):
    def process_output(self, data: List[Tuple[int, str]]) -> None:
        ...


class CSVExportPlugin:
    def process_output(self, data: List[Tuple[int, str]]) -> None:
        # Join all values in the batch into a comma-separated string
        csv_line = ",".join(str(value) for _, value in data)
        print("CSV Output:")
        print(csv_line)


class JSONExportPlugin:
    def process_output(self, data: List[Tuple[int, str]]) -> None:
        # Build a JSON-like string manually
        items = [f'"item_{rank}": "{value}"' for rank, value in data]
        json_str = "{" + ", ".join(items) + "}"
        print("JSON Output:")
        print(json_str)


class DataStream(ABC):
    def __init__(self):
        self._processors: List[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for element in stream:
            processed = False
            for proc in self._processors:
                if proc.validate(element):
                    proc.ingest(element)
                    processed = True
                    break
            if not processed:
                print(f"DataStream error - "
                      f"Can't process element in stream: {element}")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self._processors:
            batch = []
            for _ in range(nb):
                if proc._data_queue:
                    batch.append(proc.output())
            if batch:
                plugin.process_output(batch)

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
        for proc in self._processors:
            remaining = len(proc._data_queue)
            print(f"{proc.__class__.__name__}: total {proc._counter} "
                  f"items processed, remaining {remaining} on processor")


def main():
    print("=== Code Nexus - Data Pipeline ===")
    print()
    print("Initialize Data Stream...")
    print()
    ds = DataStream()
    ds.print_processors_stats()
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    print()
    print("Registering Processors")
    print()
    ds.register_processor(numeric)
    ds.register_processor(text)
    ds.register_processor(log)
    batch1 = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {
                'log_level': 'WARNING',
                'log_message': 'Telnet access! Use ssh instead'
            },
            {
                'log_level': 'INFO',
                'log_message': 'User wil is connected'
            }
        ],
        42,
        ['Hi', 'five']
    ]
    print(f"Send first batch of data on stream: {batch1}")
    ds.process_stream(batch1)
    print()
    ds.print_processors_stats()
    print()
    print("Send 3 processed data from each processor to a CSV plugin:")
    csv_plugin = CSVExportPlugin()
    ds.output_pipeline(3, csv_plugin)
    print()
    ds.print_processors_stats()
    batch2 = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [
            {
                'log_level': 'ERROR',
                'log_message': '500 server crash'
            },
            {
                'log_level': 'NOTICE',
                'log_message': 'Certificate expires in 10 days'
            }
        ],
        [32, 42, 64, 84, 128, 168],
        'World hello'
    ]
    print()
    print(f"Send another batch of data: {batch2}")
    ds.process_stream(batch2)
    print()
    ds.print_processors_stats()
    print()
    print("Send 5 processed data from each processor to a JSON plugin:")
    json_plugin = JSONExportPlugin()
    ds.output_pipeline(5, json_plugin)
    print()
    ds.print_processors_stats()


if __name__ == "__main__":
    main()
