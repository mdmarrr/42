#!/usr/bin/env python3

class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def grow(self):
        self.height += 1

    def age_one_day(self):
        self.age += 1

    def get_info(self):
        return f"{self.name}: {self.height}cm, {self.age} days old"


if __name__ == "__main__":
    plant1 = Plant("Rose", 25, 30)
    plant2 = Plant("Sunflower", 80, 45)
    plant3 = Plant("Cactus", 15, 120)

    garden = [plant1, plant2, plant3]

    print("=== Garden Plant Registry ===")

    for plant in garden:
        print(plant.get_info())
