#!/usr/bin/env python3


import sys

print("=== Command Quest ===")

print(f"Program name: {sys.argv[0]}")

num_args = len(sys.argv) - 1

if num_args == 0:
    print("No arguments provided!")
else:
    print(f"Arguments received: {num_args}")
    for i in range(1, len(sys.argv)):
        print(f"Argument {i}: {sys.argv[i]}")

print(f"Total arguments: {len(sys.argv)}")
