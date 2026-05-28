"""Exercise 0: inspect Python virtual environments."""

import os
import site
import sys


def is_virtual_environment() -> bool:
    """Return True when Python is running inside a virtual environment."""
    return sys.prefix != sys.base_prefix or hasattr(sys, "real_prefix")


def environment_name() -> str:
    """Return the active virtual environment name, if it can be inferred."""
    virtual_env_path = os.environ.get("VIRTUAL_ENV")
    if virtual_env_path:
        return os.path.basename(virtual_env_path)
    return os.path.basename(sys.prefix)


def site_package_paths() -> list[str]:
    """Return known site-packages paths for the current interpreter."""
    try:
        return site.getsitepackages()
    except AttributeError:
        return [site.getusersitepackages()]


def print_outside_matrix() -> None:
    """Print instructions for creating a virtual environment."""
    print("Outside the Matrix")
    print(f"Current Python: {sys.executable}")
    print("Virtual Environment: None detected")
    print(f"Global Prefix: {sys.base_prefix}")
    print(f"User Package Path: {site.getusersitepackages()}")
    print("WARNING: You're in the global environment!")
    print("The machines can see everything you install.")
    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate  # On Unix")
    print(r"matrix_env\Scripts\activate  # On Windows")
    print("Then run this program again.")


def print_inside_construct() -> None:
    """Print details about the active virtual environment."""
    print("Inside the Construct")
    print("MATRIX STATUS: Welcome to the construct")
    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {environment_name()}")
    print(f"Environment Path: {sys.prefix}")
    print(f"Global Python Prefix: {sys.base_prefix}")
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting the global system.")
    print("Package installation path:")
    for path in site_package_paths():
        print(path)


def main() -> None:
    """Entry point."""
    if is_virtual_environment():
        print_inside_construct()
    else:
        print_outside_matrix()


if __name__ == "__main__":
    main()
