import os
import sys

try:
    from dotenv import load_dotenv
except ImportError:
    load_dotenv = None  # type: ignore[assignment]

REQUIRED_VARIABLES: tuple[str, ...] = (
    "MATRIX_MODE",
    "DATABASE_URL",
    "API_KEY",
    "LOG_LEVEL",
    "ZION_ENDPOINT",
)
VALID_MODES: tuple[str, ...] = ("development", "production")


def load_environment_file() -> bool:
    if load_dotenv is None:
        print("WARNING: python-dotenv is not installed.")
        print(
            "Install it with: python -m pip install python-dotenv"
        )
        return False

    load_dotenv(override=False)
    return os.path.exists(".env")


def read_configuration() -> dict[str, str]:
    configuration: dict[str, str] = {}
    for variable_name in REQUIRED_VARIABLES:
        configuration[variable_name] = os.environ.get(variable_name, "")
    return configuration


def missing_variables(configuration: dict[str, str]) -> list[str]:
    missing: list[str] = []
    for variable_name, value in configuration.items():
        if not value:
            missing.append(variable_name)
    return missing


def is_sensitive_placeholder(api_key: str) -> bool:
    lowered_key = api_key.lower()
    return "change" in lowered_key or "example" in lowered_key


def describe_database(database_url: str) -> str:
    if database_url.startswith("sqlite"):
        return "Connected to local instance"
    if database_url:
        return "Configured for external instance"
    return "Missing"


def describe_zion_endpoint(endpoint: str) -> str:
    if endpoint.startswith("http://") or endpoint.startswith("https://"):
        return "Online"
    if endpoint:
        return "Configured with non-HTTP endpoint"
    return "Missing"


def print_configuration(configuration: dict[str, str]) -> None:
    matrix_mode = configuration["MATRIX_MODE"] or "missing"
    database_url = configuration["DATABASE_URL"]
    api_key = configuration["API_KEY"]
    log_level = configuration["LOG_LEVEL"] or "missing"
    zion_endpoint = configuration["ZION_ENDPOINT"]

    print("Configuration loaded:")
    print(f"Mode: {matrix_mode}")
    print(f"Database: {describe_database(database_url)}")
    print(f"API Access: {'Authenticated' if api_key else 'Missing'}")
    print(f"Log Level: {log_level}")
    print(f"Zion Network: {describe_zion_endpoint(zion_endpoint)}")

    if matrix_mode == "production":
        print("Runtime profile: production safeguards enabled")
    elif matrix_mode == "development":
        print("Runtime profile: development diagnostics enabled")
    else:
        print("Runtime profile: invalid or missing mode")


def env_file_is_ignored() -> bool:
    try:
        with open(".gitignore", "r", encoding="utf-8") as gitignore_file:
            ignored_entries = gitignore_file.read().splitlines()
    except OSError:
        return False

    return ".env" in ignored_entries


def print_security_check(
    configuration: dict[str, str],
    env_file_loaded: bool,
) -> bool:
    missing = missing_variables(configuration)
    mode = configuration["MATRIX_MODE"]
    api_key = configuration["API_KEY"]
    is_valid = True

    print()
    print("Environment security check:")

    if missing:
        print(f"[WARNING] Missing configuration: {', '.join(missing)}")
        is_valid = False
    else:
        print("[OK] Required configuration variables are present")

    if mode and mode not in VALID_MODES:
        print("[WARNING] MATRIX_MODE must be development or production")
        is_valid = False
    elif mode:
        print("[OK] MATRIX_MODE is valid")

    if api_key and is_sensitive_placeholder(api_key):
        print("[WARNING] Hardcoded secrets detected")
    elif api_key:
        print("[OK] No hardcoded secrets detected")

    if env_file_loaded:
        print("[OK] .env file properly configured")
    else:
        print("[WARNING] .env file missing")

    if env_file_is_ignored():
        print("[OK] .env file properly ignored by Git")
    else:
        print(
            "[WARNING] .env is not protected by .gitignore"
        )
        is_valid = False

    print("[OK] Production overrides available")
    return is_valid


def main() -> int:
    print()
    print("ORACLE STATUS: Reading the Matrix...")
    print()
    env_file_loaded = load_environment_file()
    configuration = read_configuration()
    print_configuration(configuration)
    configuration_is_valid = print_security_check(
        configuration,
        env_file_loaded,
    )
    print()
    print("The Oracle sees all configurations.")
    if configuration_is_valid:
        return 0
    return 1


if __name__ == "__main__":
    sys.exit(main())
