from alchemy.potions import healing_potion, strength_potion


print("=== Distillation 0 ===")
print("Direct access to alchemy/potions.py")
strength = strength_potion()
healing = healing_potion()
print(f"Testing strength_potion: {strength}")
print(f"Testing healing_potion: {healing}")
