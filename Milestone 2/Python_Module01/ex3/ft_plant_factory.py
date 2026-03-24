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
    Plant("Oak", 200, 365),
    Plant("Cactus", 5, 90),
    Plant("Sunflower", 80, 45),
    Plant("Fern", 15, 120),
]


if __name__ == "__main__":

    print("=== Plant Factory Output ===")
    for plant in garden:
        plant.show("Created: ")
