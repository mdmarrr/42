class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def display_info(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")


plant1 = Plant("Rose", 25, 30)
plant2 = Plant("Sunflower", 80, 45)
plant3 = Plant("Cactus", 15, 120)

garden = [plant1, plant2, plant3]

print("=== Garden Plant Registry ===")

for plant in garden:
    plant.display_info()
