def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda artifact: artifact["power"],
                  reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda mage: mage["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda spell: f"* {spell} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    return {
        "max_power": max(mages, key=lambda mage: mage["power"])["power"],
        "min_power": min(mages, key=lambda mage: mage["power"])["power"],
        "avg_power": round(
            sum(map(lambda mage: mage["power"], mages)) / len(mages),
            2
        )
    }


def main() -> None:
    artifacts = [
        {"name": "Crystal Orb", "power": 85, "type": "Focus"},
        {"name": "Fire Staff", "power": 92, "type": "Weapon"},
    ]

    spells = ["fireball", "heal", "shield"]

    print()
    print("Testing artifact sorter...")
    sorted = artifact_sorter(artifacts)
    print(
        f"{sorted[0]['name']} ({sorted[0]['power']} power) "
        f"comes before {sorted[1]['name']} ({sorted[1]['power']} power)"
    )
    print()
    print("Testing spell transformer...")
    print(*spell_transformer(spells))


if __name__ == "__main__":
    main()
