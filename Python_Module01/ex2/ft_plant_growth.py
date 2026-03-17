#!/usr/bin/env python3

from ex1.ft_garden_data import Plant


garden = [
    Plant("Rose", 25, 30),
]


def simulate_growth(garden, days=7):
    initial_heights = [plant.height for plant in garden]

    for day in range(days):
        if day == 0 or day == days - 1:
            print(f"=== Day {day + 1} ===")
        for plant in garden:
            if day != 0:
                plant.grow()
                plant.age_one_day()
            if day == 0 or day == days - 1:
                print(plant.get_info())

    for i, plant in enumerate(garden):
        growth = plant.height - initial_heights[i]
        print(f"Growth this week: +{growth}cm")


if __name__ == "__main__":
    simulate_growth(garden, days=7)
