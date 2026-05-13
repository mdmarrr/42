#!/usr/bin/env python3


import typing
from abc import ABC, abstractmethod
from typing import Any, Dict, List, Union


class DataProcessor(ABC):
    def __init__(self) -> None:
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


class DataStream:
    def __init__(self) -> None:
        self._processors: List[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
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

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
        for proc in self._processors:
            remaining = len(proc._data_queue)
            print(f"{proc.__class__.__name__}: total {proc._counter} "
                  f"items processed, remaining {remaining} on processor")


def main() -> None:
    print("=== Code Nexus - Data Stream ===")
    print()
    print("Initialize Data Stream...")
    ds = DataStream()
    ds.print_processors_stats()
    batch = [
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
    print()
    print("Registering Numeric Processor")
    numeric = NumericProcessor()
    ds.register_processor(numeric)
    print()
    print(f"Send first batch of data on stream: {batch}")
    ds.process_stream(batch)
    ds.print_processors_stats()
    print()
    print("Registering other data processors")
    text = TextProcessor()
    log = LogProcessor()
    ds.register_processor(text)
    ds.register_processor(log)
    print("Send the same batch again")
    ds.process_stream(batch)
    ds.print_processors_stats()
    print()
    print("Consume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1")
    for _ in range(3):
        numeric.output()
    for _ in range(2):
        text.output()
    log.output()
    ds.print_processors_stats()


if __name__ == "__main__":
    main()
