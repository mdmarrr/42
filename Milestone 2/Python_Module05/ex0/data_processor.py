#!/usr/bin/env python3


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


def main() -> None:
    print("=== Code Nexus - Data Processor ===")

    print()
    numeric = NumericProcessor()
    print("Testing Numeric Processor...")
    print(f" Trying to validate input '42': {numeric.validate(42)}")
    print(f" Trying to validate input 'Hello': {numeric.validate('Hello')}")
    print(" Test invalid ingestion of string 'foo' without prior validation:")
    try:
        numeric.ingest("foo")
    except ValueError as e:
        print(e)
    nums: List[Union[int, float]] = [1, 2, 3, 4, 5]
    print(f" Processing data: {nums}")
    numeric.ingest(nums)
    print(" Extracting 3 values...")
    for i in range(3):
        _, val = numeric.output()
        print(f" Numeric value {i}: {val}")

    print()
    text = TextProcessor()
    print("Testing text processor...")
    print(f" Trying to validate input '42': {text.validate('42')}")
    words = ['Hello', 'Nexus', 'World']
    print(f" Processing data: {words}")
    text.ingest(words)
    print(" Extracting 1 value...")
    _, val = text.output()
    print(f" Text value 0: {val}")

    print()
    log = LogProcessor()
    print("Testing Log Processor...")
    print(f" Trying to validate input 'Hello: {log.validate('Hello')}")
    logs = [
        {"log_level": "NOTICE", "log_message": "Connection to server"},
        {"log_level": "ERROR", "log_message": "Unauthorized access!!"}
    ]
    print(f" Processing data: {logs}")
    log.ingest(logs)
    print(" Extracting 2 values...")
    for i in range(2):
        _, val = log.output()
        print(f" Log entry {i}: {val}")


if __name__ == "__main__":
    main()
