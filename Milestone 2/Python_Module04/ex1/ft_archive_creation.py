#!/usr/bin/env python3


import sys
from typing import TextIO


def add_hash_to_lines(content: str) -> str:
    lines = content.splitlines()
    new_content = ""

    for line in lines:
        new_content += line + "#\n"

    return new_content


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_archive_creation.py <file>")
        return

    filename = sys.argv[1]

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    content: str = ""
    file: TextIO | None = None

    try:
        file = open(filename, "r")
        content = file.read()

        print("---")
        print()
        print(content, end="")
        print()
        print("---")

    except OSError as e:
        print(f"Errror opening file '{filename}': {e}")
        return

    finally:
        if file:
            file.close()
            print(f"File '{filename}' closed.")

    new_content = add_hash_to_lines(content)

    print()
    print("Transform data:")
    print("---")
    print()
    print(new_content, end="")
    print()
    print("---")

    new_filename = input("Enter new file name (or empty): ")

    if new_filename == "":
        print("Not saving data.")
        return

    print(f"Saving data to '{new_filename}'")

    out_file: TextIO | None = None

    try:
        out_file = open(new_filename, "w")
        out_file.write(new_content)
        print(f"Data saved in file '{new_filename}'.")

    except OSError as e:
        print(f"Error saving file '{new_filename}': {e}")
        return

    finally:
        if out_file:
            out_file.close()


if __name__ == "__main__":
    main()
