from collections.abc import Callable


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    return lambda target, power: (
        spell1(target, power),
        spell2(target, power)
    )


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    return lambda target, power: (
        base_spell(target, power * multiplier)
    )


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    return lambda target, power: (
        spell(target, power)
        if condition(target, power)
        else "Spell fizzled"
    )


def spell_sequence(spells: list[Callable]) -> Callable:
    return lambda target, power: [
        spell(target, power) for spell in spells
    ]


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} for {power} damage"


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def strong_enough(target: str, power: int) -> bool:
    return power >= 10


def main() -> None:
    print()
    print("Testing spell combiner...")
    combined = spell_combiner(fireball, heal)
    result1, result2 = combined("Dragon", 10)
    print(f"Combined spell result: {result1}, {result2}")
    print()
    print("Testing power amplifier...")
    mega_fireball = power_amplifier(fireball, 3)
    print("Original:", fireball("Dragon", 10))
    print("Amplified:", mega_fireball("Dragon", 10))
    print()
    print("Testing conditional caster...")
    caster = conditional_caster(strong_enough, fireball)
    print(caster("Dragon", 5))
    print(caster("Dragon", 15))
    print()
    print("Testing spell sequence...")
    sequence = spell_sequence([fireball, heal])
    result1, result2 = sequence("Dragon", 10)
    print(f"Spell sequence result: {result1}, {result2}")


if __name__ == "__main__":
    main()
