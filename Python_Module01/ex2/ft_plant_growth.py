#!/usr/bin/env python3

from ex1.ft_garden_data import Plant


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
