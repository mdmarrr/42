import os
import site
import sys


def is_virtual_environment() -> bool:
    return sys.prefix != sys.base_prefix or hasattr(sys, "real_prefix")


def environment_name() -> str:
    virtual_env_path = os.environ.get("VIRTUAL_ENV")
    if virtual_env_path:
        return os.path.basename(virtual_env_path)
    return os.path.basename(sys.prefix)


def site_package_paths() -> list[str]:
    try:
        return site.getsitepackages()
    except AttributeError:
        return [site.getusersitepackages()]


def print_outside_matrix() -> None:
    print()
    print("MATRIX STATUS: You're still plugged in")
    print()
    print(f"Current Python: {sys.executable}")
    print("Virtual Environment: None detected")
    print()
    print("WARNING: You're in the global environment!")
    print("The machines can see everything you install.")
    print()
    print("To enter the construct, run:")
    print("python3 -m venv matrix_env")
    print("source matrix_env/bin/activate  # On Unix")
    print(r"matrix_env\Scripts\activate  # On Windows")
    print()
    print("Then run this program again.")


def print_inside_construct() -> None:
    print()
    print("MATRIX STATUS: Welcome to the construct")
    print()
    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {environment_name()}")
    print(f"Environment Path: {sys.prefix}")
    print()
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting the global system.")
    print("Package installation path:")
    for path in site_package_paths():
        print(path)


def main() -> None:
    if is_virtual_environment():
        print_inside_construct()
    else:
        print_outside_matrix()


if __name__ == "__main__":
    main()
