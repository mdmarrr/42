import importlib.metadata
import importlib.util
import sys

REQUIRED_PACKAGES: dict[str, str] = {
    "pandas": "Data manipulation ready",
    "numpy": "Numerical computation ready",
    "matplotlib": "Visualization ready",
}

OUTPUT_FILE = "matrix_analysis.png"
DATA_POINTS = 1000


def package_is_available(package_name: str) -> bool:
    return importlib.util.find_spec(package_name) is not None


def package_version(package_name: str) -> str:
    try:
        return importlib.metadata.version(package_name)
    except importlib.metadata.PackageNotFoundError:
        return "unknown"


def check_dependencies() -> bool:
    missing_packages: list[str] = []

    print("Checking dependencies:")
    for package_name, purpose in REQUIRED_PACKAGES.items():
        if package_is_available(package_name):
            version = package_version(package_name)
            print(f"[OK] {package_name} ({version}) - {purpose}")
        else:
            print(f"[MISSING] {package_name} - {purpose}")
            missing_packages.append(package_name)

    if not missing_packages:
        return True

    print()
    print("Missing dependencies detected.")
    print("Install them with pip:")
    print("pip install -r requirements.txt")
    print()
    print("Or install them with Poetry:")
    print("poetry install")
    return False


def print_dependency_management_comparison() -> None:
    print()
    print("pip and Poetry dependency management differences:")
    print("pip: reads requirements.txt as a direct installation list.")
    print("Poetry: reads pyproject.toml as project metadata and dependencies.")
    print("pip command: python -m pip install -r requirements.txt")
    print("Poetry command: poetry install && poetry run python loading.py")


def run_analysis() -> None:
    import matplotlib.pyplot as plt
    import numpy as np
    import pandas as pd

    print()
    print("Analyzing Matrix data...")

    random_generator = np.random.default_rng(seed=42)
    anomaly_score = random_generator.normal(
        loc=50.0,
        scale=12.0,
        size=DATA_POINTS,
    )
    signal_strength = random_generator.normal(
        loc=100.0,
        scale=20.0,
        size=DATA_POINTS,
    )
    time_index = np.arange(DATA_POINTS)

    matrix_data = pd.DataFrame(
        {
            "time_index": time_index,
            "anomaly_score": anomaly_score,
            "signal_strength": signal_strength,
        }
    )
    matrix_data["rolling_anomaly"] = (
        matrix_data["anomaly_score"].rolling(window=25).mean()
    )

    print(f"Processing {len(matrix_data)} data points...")
    print("Generating visualization...")

    plt.figure(figsize=(10, 6))
    plt.plot(
        matrix_data["time_index"],
        matrix_data["anomaly_score"],
        alpha=0.35,
    )
    plt.plot(matrix_data["time_index"], matrix_data["rolling_anomaly"])
    plt.title("Matrix Anomaly Signal")
    plt.xlabel("Time index")
    plt.ylabel("Anomaly score")
    plt.tight_layout()
    plt.savefig(OUTPUT_FILE)
    plt.close()
    print()
    print("Analysis complete!")
    print(f"Results saved to: {OUTPUT_FILE}")


def main() -> int:
    print()
    print("LOADING STATUS: Loading programs...")
    print()
    dependencies_ready = check_dependencies()
    print_dependency_management_comparison()

    if not dependencies_ready:
        return 1

    try:
        run_analysis()
    except Exception as error:
        print(f"ERROR: Matrix data stream failed safely: {error}")
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())
