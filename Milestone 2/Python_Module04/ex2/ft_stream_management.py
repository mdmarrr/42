#!/usr/bin/env python3


import sys


def add_hash_to_lines(content):
    lines = content.splitlines()
    new_content = ""

    for line in lines:
        new_content += line + "#\n"

    return new_content


def main():
    if len(sys.argv) != 2:
        print("Usage: ft_stream_management.py <file>")
        return
    
    filename = sys.argv[1]

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    file = None
    try:
        file = open(filename, "r")
        content = file.read()

        print("---")
        print()
        print(content, end="")
        print()
        print("---")

    except OSError as e:
        print(f"[STDERR] Error opening file '{filename}': {e}", file=sys.stderr)
        return

    finally:
        if file:
            file.close()
            print(f"File '{filename}' closed.")
            print()

    new_content = add_hash_to_lines(content)

    print("Transform data:")
    print("---")
    print()
    print(new_content, end="")
    print()
    print("---")

    print("Enter new file name (or empty): ", end="")
    sys.stdout.flush()

    new_filename = sys.stdin.readline()

    if new_filename.endswith("\n"):
        new_filename = new_filename[:-1]

    if new_filename == "":
        print("Data not saved.")
        return
    
    print(f"Saving data to '{new_filename}'")

    out_file = None

    try:
        out_file = open(new_filename, "w")
        out_file.write(new_content)
    
    except OSError as e:
        print(f"[STDERR] Error opening file '{new_filename}': {e}", file=sys.stderr)
        print("Data not saved.")
        return
    
    finally:
        if out_file:
            out_file.close()

    print(f"Data saved in file '{new_filename}'.")


if __name__ == "__main__":
    main()
