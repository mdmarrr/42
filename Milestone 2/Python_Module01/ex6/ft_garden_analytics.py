#!/usr/bin/env python3


class Plant:
    class _Stats:
        def __init__(self):
            self.grow_calls = 0
            self.age_calls = 0
            self.show_calls = 0

        def display(self):
            print(f"Stats: {self.grow_calls} grow, "
                  f"{self.age_calls} age, {self.show_calls} show")

    def __init__(self, name, height, age):
        self.name = name
        self._height = 0
        self._age = 0
        self._stats = self._Stats()
        self.set_height(height, verbose=False)
        self.set_age(age, verbose=False)

    @staticmethod
    def is_year_old(age):
        return age > 365

    @classmethod
    def anonymous(cls):
        return cls("Unknown plant", 0, 0)

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
        self._stats.show_calls += 1

    def display_stats(self):
        self._stats.display()


class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.color = color
        self._bloomed = False

    def bloom(self):
        self._bloomed = True

    def show(self, prefix=""):
        super().show(prefix)
        print(f" Color: {self.color}")
        if self._bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        print(f"Tree {self.name} now produces a shade of {self._height:.1f}cm"
              f" long and {self.trunk_diameter:.1f}cm wide.")

    def show(self, prefix=""):
        super().show(prefix)
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")


class FlowerEx(Flower, Plant):
    def __init__(self, name, height, age, color):
        Flower.__init__(self, name, height, age, color)
        self._stats = Plant._Stats()

    def grow(self):
        self._height += 8
        self._stats.grow_calls += 1

    def age_a_day(self):
        super().age_a_day()
        self._stats.age_calls += 1

    def show(self, prefix=""):
        super().show(prefix)

    def display_stats(self):
        self._stats.display()


class TreeEx(Tree, Plant):
    def __init__(self, name, height, age, trunk_diameter):
        Tree.__init__(self, name, height, age, trunk_diameter)
        self._stats = Plant._Stats()
        self._shade_calls = 0

    def produce_shade(self):
        super().produce_shade()
        self._shade_calls += 1

    def grow(self):
        Flower.grow(self)
        self._stats.grow_calls += 1

    def age_a_day(self):
        super().age_a_day()
        self._stats.age_calls += 1

    def show(self, prefix=""):
        super().show(prefix)

    def display_stats(self):
        self._stats.display()
        print(f" {self._shade_calls} shade")


class Seed(FlowerEx):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age, color)
        self.seeds = 0

    def grow(self):
        self._height += 30
        self._stats.grow_calls += 1

    def age_a_day(self):
        self._age += 20
        self._stats.age_calls += 1

    def bloom(self):
        super().bloom()
        self.seeds = 42

    def show(self, prefix=""):
        super().show(prefix)
        print(f" Seeds: {self.seeds}")


def show_statistics(plant):
    print(f"[statistics for {plant.name}]")
    plant.display_stats()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_year_old(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_year_old(400)}")
    print()
    print("=== Flower")
    rose = FlowerEx("Rose", 15, 10, "red")
    rose.show()
    show_statistics(rose)
    print("[asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    show_statistics(rose)
    print()
    print("=== Tree")
    oak = TreeEx("Oak", 200, 365, 5)
    oak.show()
    show_statistics(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    show_statistics(oak)
    print()
    print("=== Seed")
    sunflower = Seed("Sunflower", 80, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.age_a_day()
    sunflower.bloom()
    sunflower.show()
    show_statistics(sunflower)
    print()
    print("=== Anonymous")
    anonymous = Plant("Unknown plant", 0, 0)
    anonymous.show()
    show_statistics(anonymous)
