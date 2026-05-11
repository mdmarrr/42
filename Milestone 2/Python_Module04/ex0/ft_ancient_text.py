#!/usr/bin/env python3


import sys
from typing import TextIO


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return

    filename = sys.argv[1]

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    file: TextIO | None = None

    try:
        file = open(filename, "r")
        print("---")
        print()
        print(file.read(), end="")
        print()
        print("---")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
    finally:
        if file:
            file.close()
            print(f"File '{filename}' closed.")


if __name__ == "__main__":
    main()
