#!/usr/bin/env python3


import sys


def parse_inventory(args: list[str]) -> dict[str, int]:
    inventory = {}

    for arg in args:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue

        item, quantity = arg.split(":", 1)
        item = item.strip()
        quantity = quantity.strip()

        if not item or not quantity:
            print(f"Invalid parameter: {arg}")
            continue

        if item in inventory:
            print(f"Redundant item '{item}' - discarding")
            continue

        try:
            inventory[item] = int(quantity)
        except ValueError as e:
            print(f"Quantity error for '{item}': {e}")

    return inventory


def print_report(inventory: dict[str, int]) -> None:
    items = list(inventory.keys())
    total = sum(inventory.values())

    if total == 0:
        print("Error: inventory is empty after parsing")
        return

    print(f"Item list: {items}")
    print(f"Total quantity of the {len(items)} items: {total}")

    for item, quantity in inventory.items():
        percentage = (quantity / total) * 100
        print(f"Item {item} represents {percentage:.1f}%")

    items_order = list(inventory.keys())
    most = max(items_order, key=lambda k: inventory[k])
    least = min(items_order, key=lambda k: inventory[k])

    print(f"Item most abundant: {most} with quantity {inventory[most]}")
    print(f"Item least abundant: {least} with quantity {inventory[least]}")


def main() -> None:
    args = sys.argv[1:]

    if not args:
        print("Error: no inventory items provided")
        print("Usage: python3 ft_inventory_system.py item:quantity ...")
        return

    inventory = parse_inventory(args)

    if not inventory:
        print("Error: no valid inventory items")
        return

    print(f"Got inventory: {inventory}")

    print_report(inventory)

    inventory.update({"magic_item": 1})

    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
