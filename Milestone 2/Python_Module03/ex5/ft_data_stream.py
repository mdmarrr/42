#!/usr/bin/env python3


import random


PLAYERS = ["alice", "bob", "charlie", "dylan"]
ACTIONS = ["run", "eat", "sleep", "use", "grab",
           "release", "move", "climb", "swim"]


def gen_event():
    while True:
        yield (random.choice(PLAYERS), random.choice(ACTIONS))


def consume_event(events: list[tuple[str, str]]):
    while events:
        idx = random.randrange(len(events))
        yield events.pop(idx)


def main() -> None:
    event_gen = gen_event()

    print("=== Game Data Stream Processor ===")
    for i in range(1000):
        name, action = next(event_gen)
        print(f"Event {i}: Player {name} did action {action}")

    event_gen = gen_event()
    event_list = [next(event_gen) for _ in range(10)]
    print(f"Built list of 10 events: {event_list}")

    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {event_list}")

    for event in consume_event(event_list):
        print(event)


if __name__ == "__main__":
    main()
