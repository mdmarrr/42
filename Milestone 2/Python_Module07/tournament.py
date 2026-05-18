from typing import List, Tuple
from ex0 import FlameFactory, AquaFactory
from ex0.factory import CreatureFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    BattleStrategy,
    NormalStrategy,
    AggressiveStrategy,
    DefensiveStrategy,
    InvalidStrategyException,
)


Opponent = Tuple[CreatureFactory, BattleStrategy]


def battle(opponents: List[Opponent]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")

    creatures = []

    for factory, strategy in opponents:
        creature = factory.create_base()
        creatures.append((creature, strategy))

    for i in range(len(creatures)):
        for j in range(i + 1, len(creatures)):
            creature1, strategy1 = creatures[i]
            creature2, strategy2 = creatures[j]
            print()
            print("* Battle *")
            print(creature1.describe())
            print(" vs.")
            print(creature2.describe())
            print(" now fight!")

            try:
                strategy1.act(creature1)
                strategy2.act(creature2)
            except InvalidStrategyException as error:
                print(f"Battle error, aborting tournament: {error}")
                return


def main() -> None:
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()

    normal = NormalStrategy()
    aggressive = AggressiveStrategy()
    defensive = DefensiveStrategy()

    print("Tournament 0 (basic)")
    print("[ (Flameling+Normal), (Healing+Defensive) ]")
    battle([
        (flame_factory, normal),
        (healing_factory, defensive)
    ])
    print()
    print("Tournament 1 (error)")
    print("[ (Flameling+Aggressive), (Healing+Defensive) ]")
    battle([
        (flame_factory, aggressive),
        (healing_factory, defensive)
    ])
    print()
    print("Tournament 2 (multiple)")
    print("[ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive)]")
    battle([
        (aqua_factory, normal),
        (healing_factory, defensive),
        (transform_factory, aggressive)
    ])
    print()


if __name__ == "__main__":
    main()
