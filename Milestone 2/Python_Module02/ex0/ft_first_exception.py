#!/usr/bin/env python3


def input_temperature(temp_str: str) -> int:
    temp_int = int(temp_str)
    return temp_int


def test_temperature() -> None:
    print("Input data is '25'")
    try:
        temperature = input_temperature("25")
        print(f"Temperature is now {temperature}ºC")
    except Exception:
        print("Caught input_temperature error")
    print()
    print("Input data is 'abc'")
    try:
        temperature = input_temperature("abc")
        print(f"Temperature is now {temperature}ºC")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("All test completed - program didn't crash!")


if __name__ == "__main__":

    print("=== Garden Temperature ===")
    print()
    test_temperature()
