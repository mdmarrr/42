#!/usr/bin/env python3

from ex1.ft_garden_data import Plant


print("=== Garden Security System ===")

plant = Plant("Rose", 15, 10)

if __name__ == "__main__":

    plant.show("Plant created: ")
    print()
    plant.set_height(25)
    plant.set_age(30)
    print()
    plant.set_height(-25)
    plant.set_age(-30)
    print()
    print("Current state:", end=" ")
    plant.show()
