*This project has been created as part of the 42 curriculum by magomez-*

# 42push_swap

## Table of Contents

- Description
- Installation
- Usage
- Project Structure
- Algorithm
- Operations
- Features
- Dependencies
- Error Handling
- Troubleshooting

---

## Description

push_swap is a sorting algorithm project from the 42 curriculum.
The goal is to sort a list of integers using two stacks (a and b) and a limited set of operations (swap, push, rotate and reverse rotate), while minimizing the number of moves.

This implementation handles:

- Input parsing & validation
- Duplicate detection
- Index-based sorting
- Optimized small stack sorting (3–5 numbers)
- Chunk-based algorithm for large inputs

This implementation uses:
- Linked lists to represent stacks
- Index normalization
- Chunk-based sorting for large datasets
- Dedicated optimized sorting for small stack sizes

---

## Installation

1. Clone the repository

git clone git@github.com:mdmarrr/42.git (cambiar)

cd push_swap

2. Compile the project (all source files and libft)

make

---

## Usage

Example:
./push_swap 5 1 4 2 3
The program will output a sequence of operations like:
pb
ra
pb
pa
...
To test with random numbers:
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap.a $ARG

---

## Project Structure

push_swap/
│
├── include/
│   └── push_swap.h
│
├── libft/
│   ├── libft.h
│   └── ft_*.c
│
├── src/
│   ├── main.c
│   ├── ft_parse.c
│   ├── ft_error.c
│   ├── ft_free.c
│   ├── stack_init.c
│   ├── stack_utils.c
│   ├── index.c
│   ├── ft_operations.c
│   ├── ft_operations2.c
│   ├── ft_operations3.c
│   ├── ft_sort.c
│   ├── ft_sort_three.c
│   ├── ft_sort_four.c
│   ├── ft_sort_five.c
│   └── big_sort.c
│
└── Makefile

---

## Algorithm

1. Indexing

Before sorting, each value is assigned an index based on its sorted position.
Example:
Original: 42 10 30
Sorted:   10 30 42
Indexes:   2  0  1
This allows the algorithm to sort based on relative order instead of actual values.

2. Small Stack Sorting

Special optimized functions:
ft_sort_three
ft_sort_four
ft_sort_five
These handle small cases with minimal operations.

3. Large Stack Sorting (Chunk-Based)

Implemented in big_sort.c.

Strategy:

Divide stack A into chunks:
- ≤ 100 numbers → chunk size = 15
- 100 numbers → chunk size = 35
Push indexed elements to stack B in chunks.
Rotate stack B to position the maximum index at the top.
Push elements back to stack A in sorted order.
This significantly reduces total operations compared to naive approaches.

---

## Operations

sa:	    Swap first two elements of stack A
sb:	    Swap first two elements of stack B
ss:	    sa + sb
pa:	    Push from B to A
pb:	    Push from A to B
ra:	    Rotate A upwards
rb:	    Rotate B upwards
rr:	    ra + rb
rra:    Reverse rotate A
rrb:	Reverse rotate B
rrr:	rra + rrb

Operations are implemented across:

ft_operations.c
ft_operations2.c
ft_operations3.c

---

## Features

- Robust argument parsing
- Handles quoted and space-separated input
- Duplicate detection
- Overflow-safe integer parsing
- Memory-safe (manual free management)
- Optimized for small and large datasets
- Modular structure
- Uses custom libft

---

## Dependencies

libft (included in project)
Standard C libraries
Compiled with:
    -Wall -Wextra -Werror
Compiler:
    cc

---

## Error Handling

The program prints:
    Error
When:
- Non-numeric input is detected
- Integer overflow occurs
- Duplicate numbers are provided
- Invalid format is passed
- All allocated memory is properly freed before exit.

---

## Troubleshooting

Nothing prints
Check if input is already sorted.
"Error" appears
Check for duplicates
Ensure all values are valid integers
Avoid exceeding INT range
Memory leaks
Test with:
valgrind --leak-check=full ./push_swap.a 3 2 1
🧪 Example
./push_swap.a 2 1 3 6 5 8
Output:
sa
pb
ra
...
