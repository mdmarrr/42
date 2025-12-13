*This project has been created as part of the 42 curriculum by magomez-*

# get_next_line

## Table of contents

- Description
- Features
- Instructions
	- Installation
	- Usage
- Project Structure
- Algorithm
- Resources

---

## Description

Read a file descriptor line by line—safely, efficiently, and with clear memory ownership. This repository contains both the mandatory version (single FD) and the bonus version (multiple FDs using OPEN_MAX).

Function prototype:
char *get_next_line(int fd);

---

## Features

### Mandatory

Read from one file descriptor across multiple calls.
Handle arbitrarily long lines (reading in chunks of BUFFER_SIZE).
Return lines including '\n' when present.
Robust against BUFFER_SIZE = 1, large BUFFER_SIZE, empty files, files without a trailing newline, etc.

### Bonus

Support multiple file descriptors simultaneously:
static char *stash[OPEN_MAX];
The per-FD “stash” ensures calls on different FDs do not interfere.

---

## Instructions:

### Installation:

1. Clone the repository:

git clone git@vogsphere.42malaga.com:vogsphere/intra-uuid-4038c6ef-fc26-4ae8-8515-6afa326a6b5d-7124188-magomez- get_next_line

cd get_next_line

2. Compile the project:

- cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c

3. Execute the project:

- /a.out

### Usage

	#include <fcntl.h>
	#include <stdio.h>
	#include "get_next_line.h"

	int main(void)
	{
		int   fd = open("file.txt", O_RDONLY);
		char *line;
	
		if (fd < 0) 
			return (1);
	
	    while ((line = get_next_line(fd)) != NULL)
	    {
	        printf("%s", line);
	        free(line);
	    }
	    close(fd);
	    return (0);
	}

---

## Project Structure

### Mandatory

- get_next_line.h: Header file with the function prototype and includes.
- get_next_line.c: public API + single static stash (one FD).
	- read_file: read chunks into a temporary buffer; accumulate into stash until '\n' or EOF.
	- ft_line: extract the next line from stash (includes '\n' if present).
	- ft_next: compute the “remainder” (what’s left after the returned line), free old stash, and return the new one.
- get_next_line_utils.c: string helpers (ft_strchr, ft_bzero, ft_calloc, ft_strlen, ft_strjoin).

### Bonus

- get_next_line_bonus.h: Header file with the function prototype and includes.
- get_next_line_bonus.c: public API + static char *stash[OPEN_MAX]; (multi-FD).
- get_next_line_utils_bonus.c: the same helpers.

---

## Algorithm

1. Read & accumulate:

Allocate buffer of size BUFFER_SIZE + 1.
read(fd, buffer, BUFFER_SIZE) until you either see '\n' in the just-read chunk or hit EOF.
Append the chunk to stash with a safe strjoin pattern:
	tmp = stash;
	stash = ft_strjoin(tmp, buffer);
	free(tmp);
On read == -1: free buffer and (if allocated) stash; return NULL.

2. Extract the line (ft_line):

Scan stash up to '\n' (or end).
Allocate and copy that prefix (and the '\n', if present).
Return the new line (caller owns it).

3. Update the stash (ft_next):

If no '\n' was found, free stash and return NULL (no remainder).
Otherwise, allocate a new string with the content after '\n', free old stash, and return the remainder.

---

## Resources

man 2 read, man 3 malloc, man 3 free.
42 Norm

AI Usage: AI was used to understand some concepts and how to create a README. No AI was used to write the code.
