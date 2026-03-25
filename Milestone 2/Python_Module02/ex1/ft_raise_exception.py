#!/usr/bin/env python3


def input_temperature(temp_str: str) -> int:
    try:
        temp_int = int(temp_str)
    except ValueError as e:
        raise ValueError(str(e))

    if temp_int < 0:
        raise ValueError(f"{temp_int}ºC is too cold for plants (min 0ºC)")
    elif temp_int > 40:
        raise ValueError(f"{temp_int}ºC is too hot for plants (max 40ºC)")

    return temp_int


def test_temperature() -> None:
    test_values = ["25", "abc", "100", "-50"]

    for value in test_values:
        print(f"Input data is '{value}'")
        try:
            temperature = input_temperature(value)
            print(f"Temperature is now {temperature}ºC")
        except Exception as e:
            print(f"Caught input_temperature error: {e}")
        print()
    print("All test completed - program didn't crash!")


if __name__ == "__main__":

    print("=== Garden Temperature Checker ===")
    print()
    test_temperature()
