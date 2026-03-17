#!/usr/bin/env python3

from ex1.ft_garden_data import Plant


garden = [
    Plant("Rose", 25, 30),
    Plant("Oak", 200, 365),
    Plant("Cactus", 5, 90),
    Plant("Sunflower", 80, 45),
    Plant("Fern", 15, 120),
]

print("=== Plant Factory Output ===")
for plant in garden:
    print(f"Created: {plant.name} ({plant.height}cm, {plant.age} days)")

count = 0
for plant in garden:
    count += 1

print(f"\nTotal plants created: {count}")
