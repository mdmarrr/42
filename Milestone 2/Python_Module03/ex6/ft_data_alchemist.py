#!/usr/bin/env python3


import random


def main() -> None:
    print("=== Game Data Alchemist ===")
    print()
    players = ['Alice', 'bob', 'Charlie', 'dylan',
               'Emma', 'Gregory', 'john', 'kevin', 'Liam']
    print(f"Initial list of players: {players}")
    print()
    capitalized = [name.capitalize() for name in players]
    print(f"New list with all names capitalized: {capitalized}")
    print()
    capitalized_only = [name for name in players if name == name.capitalize()]
    print(f"New list of capitalized names only: {capitalized_only}")
    print()
    scores = {name: random.randint(50, 1000) for name in capitalized}
    print(f"Score dict: {scores}")
    print()
    avg = sum(scores.values()) / len(scores)
    print(f"Score average is {avg:.2f}")
    print()
    high_scores = {name: score for name,
                   score in scores.items() if score > avg}
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    main()
