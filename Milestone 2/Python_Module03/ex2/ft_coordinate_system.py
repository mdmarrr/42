#!/usr/bin/env python3


import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        user_input = input("Enter new coordinates "
                           "as floats in format 'x,y,z': ")
        parts = user_input.split(",")

        if len(parts) != 3:
            print("Invalid syntax")
            continue

        coords = []
        for p in parts:
            p = p.strip()
            try:
                coords.append(float(p))
            except ValueError as e:
                print(f"Error on parameter '{p}': {e}")
                break
        else:
            x, y, z = coords
            return (x, y, z)


def main() -> None:
    print("=== Game Coordinate System ===")
    print()
    print("Get a first set of coordinates")
    pos1 = get_player_pos()
    print(f"Got a first tuple: {pos1}")
    print(f"It includes: X={pos1[0]}, Y={pos1[1]}, Z={pos1[2]}")
    dis_to_center = math.sqrt(pos1[0]**2 + pos1[1]**2 + pos1[2]**2)
    print(f"Distance to center: {dis_to_center:.4f}")
    print()
    print("Get a second set of coordinates")
    pos2 = get_player_pos()
    distance = math.sqrt(
        (pos2[0] - pos1[0])**2 +
        (pos2[1] - pos1[1])**2 +
        (pos2[2] - pos1[2])**2
    )
    print(f"Distance between the 2 sets of coordinates: {distance:.4f}")


if __name__ == "__main__":
    main()
