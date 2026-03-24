#!/usr/bin/env python3

class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self._height = height
        self._age = age

    def grow(self):
        self._height += 0.8

    def age_a_day(self):
        self._age += 1

    def show(self, prefix=""):
        print(f"{prefix}{self.name}:", end=" ")
        print(f"{self._height:.1f}cm, {self._age} days old")


garden = [
    Plant("Rose", 25, 30),
]


def simulate_growth(garden, days=7):
    initial_heights = [plant._height for plant in garden]

    print("=== Garden Plant Growth ===")

    for day in range(days):
        print(f"=== Day {day + 1} ===")
        for plant in garden:
            plant.show()
            plant.grow()
            plant.age_a_day()

    for i, plant in enumerate(garden):
        growth = plant._height - initial_heights[i]
        print(f"Growth this week: {round(growth)}cm")


if __name__ == "__main__":
    simulate_growth(garden, days=7)
