#!/usr/bin/env python3

from ex1.ft_garden_data import Plant


garden = [
    Plant("Rose", 25, 30),
    Plant("Oak", 200, 365),
    Plant("Cactus", 5, 90),
    Plant("Sunflower", 80, 45),
    Plant("Fern", 15, 120),
]


if __name__ == "__main__":

    print("=== Plant Factory Output ===")
    for plant in garden:
        plant.show("Created: ")
