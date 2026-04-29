#!/usr/bin/env python3


from typing import Tuple


def secure_archive(
        file_name: str, action: str = "read", content: str | None = None
        ) -> Tuple[bool, str]:

    if action in (0, "read"):
        mode = "r"
    elif action in (1, "write"):
        mode = "w"
    else:
        return (False, "Invalid action. Use 'read/write' or '0/1'")

    try:
        if mode == "r":
            with open(file_name, mode) as f:
                data = f.read()
            return (True, data)

        elif mode == "w":
            if content is None:
                return (False, 'No content provided for writing')
            with open(file_name, mode) as f:
                f.write(content)
            return (True, 'Content successfully written to file')

    except Exception as e:
        return (False, str(e))

    return (False, "Unexpected error")


def main():
    print("=== Cyber Archives Security ===")
    print()
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file"))
    print()
    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/shadow"))
    print()
    print("Using 'secure_archive' to read from a regular file:")
    content = secure_archive("ancient_fragment.txt")
    print(content)
    print()
    print("Using 'secure_archive' to write previous content to a new file:")
    if content[0]:
        print(secure_archive("new_fragment.txt", "write", content[1]))
    else:
        print("No content to write.")


if __name__ == "__main__":
    main()
