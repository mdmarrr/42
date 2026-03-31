#!/usr/bin/env python3


import sys

print("=== Player Score Analytics ===")

if len(sys.argv) == 1:
    print("No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...")
    sys.exit()

scores = []

for arg in sys.argv[1:]:
    try:
        value = int(arg)
        scores.append(value)
    except:
        print(f"Invalid parameter: '{arg}'")

if len(scores) == 0:
    print("No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...")
    sys.exit()

total_players = len(scores)
total_score = sum(scores)
average = total_score / total_players
high_score = max(scores)
low_score = min(scores)
score_range = high_score - low_score

print(f"Scores processed: {scores}")
print(f"Total players: {total_players}")
print(f"Total score: {total_score}")
print(f"Average score: {average}")
print(f"High score: {high_score}")
print(f"Low score: {low_score}")
print(f"Score range: {score_range}")