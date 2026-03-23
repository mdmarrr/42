#!/usr/bin/env python3

class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self._height = 0
        self._age = 0
        self.set_height(height, verbose=False)
        self.set_age(age, verbose=False)

    def grow(self):
        self._height += 0.8

    def age_a_day(self):
        self._age += 1

    def set_height(self, height, verbose=True):
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            if verbose:
                print(f"Height updated: {self._height}cm")

    def set_age(self, age, verbose=True):
        if age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = age
            if verbose:
                print(f"Age updated: {self._age} days")

    def get_height(self):
        return self._height

    def get_age(self):
        return self._age

    def show(self, prefix=""):
        print(f"{prefix}{self.name}:", end=" ")
        print(f"{self._height:.1f}cm, {self._age} days old")


if __name__ == "__main__":
    plant1 = Plant("Rose", 25, 30)
    plant2 = Plant("Sunflower", 80, 45)
    plant3 = Plant("Cactus", 15, 120)

    garden = [plant1, plant2, plant3]

    print("=== Garden Plant Registry ===")

    for plant in garden:
        plant.show()
