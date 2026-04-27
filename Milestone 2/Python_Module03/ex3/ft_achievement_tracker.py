#!/usr/bin/env python3


import random


ACHIEVEMENTS = [
    "Crafting Genius",
    "Strategist",
    "World Savior",
    "Speed Runner",
    "Survivor",
    "Master Explorer",
    "Treasure Hunter",
    "Unstoppable",
    "First Steps",
    "Collector Supreme",
    "Untouchable",
    "Sharp Mind",
    "Boss Slayer",
    "Hidden Path Finder",
]


def gen_player_achievement() -> set[str]:
    count = random.randint(5, len(ACHIEVEMENTS) - 5)

    return set(random.sample(ACHIEVEMENTS, count))


players = {
    "Alice": gen_player_achievement(),
    "Bob": gen_player_achievement(),
    "Charlie": gen_player_achievement(),
    "Dylan": gen_player_achievement()
}


def main() -> None:
    print("=== Achievement Tracker System ===")
    print()
    for name, ach in players.items():
        print(f"Player {name}: {ach}")
    print()
    all_achievements = set().union(*players.values())
    print(f"All distinct achievements: {all_achievements}")
    print()
    common_achievements = set.intersection(*players.values())
    print(f"Common achievements: {common_achievements}")
    print()
    for name, ach in players.items():
        others = set().union(*(v for k, v in players.items() if k != name))
        only = ach - others
        print(f"Only {name} has: {only}")
    print()
    for name, ach in players.items():
        missing = all_achievements - ach
        print(f"{name} is missing: {missing}")


if __name__ == "__main__":
    main()
