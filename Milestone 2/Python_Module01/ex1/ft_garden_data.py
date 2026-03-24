#!/usr/bin/env python3

class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self._height = height
        self._age = age

    def show(self, prefix=""):
        print(f"{prefix}{self.name}:", end=" ")
        print(f"{self._height}cm, {self._age} days old")


if __name__ == "__main__":
    plant1 = Plant("Rose", 25, 30)
    plant2 = Plant("Sunflower", 80, 45)
    plant3 = Plant("Cactus", 15, 120)

    garden = [plant1, plant2, plant3]

    print("=== Garden Plant Registry ===")

    for plant in garden:
        plant.show()
