*This project has been created as part of the 42 curriculum by magomez-.*

# Codexion

## Description

Codexion is a concurrent simulation written in C in which multiple coders compete for shared resources called **dongles** in order to compile their code.

The project focuses on thread synchronization, shared-resource management, scheduling algorithms, and race-condition prevention using POSIX threads.

### Features

- Concurrent execution using `pthread`.
- Shared-resource protection using mutexes.
- Condition variables for thread synchronization.
- Dedicated monitor thread for burnout detection.
- Thread-safe access to shared state.
- Configurable dongle cooldown.
- Two scheduling policies:
  - FIFO (First In, First Out)
  - EDF (Earliest Deadline First)
- Priority queues implemented using a binary heap.
- Memory and synchronization management designed for Valgrind and Helgrind.

## Instructions

### Compilation

Compile the project with:

```bash
make
```

Other available rules:

```bash
make clean
make fclean
make re
```

### Usage

```bash
./codexion \
<number_of_coders> \
<time_to_burnout> \
<time_to_compile> \
<time_to_debug> \
<time_to_refactor> \
<number_of_compiles_required> \
<dongle_cooldown> \
<fifo|edf>
```

#### Example

```bash
./codexion 4 1200 200 100 100 3 100 fifo
```

### Arguments

- `number_of_coders`: Number of concurrent coders.
- `time_to_burnout`: Maximum time a coder can go without starting a new compilation.
- `time_to_compile`: Time required to compile.
- `time_to_debug`: Time spent debugging.
- `time_to_refactor`: Time spent refactoring.
- `number_of_compiles_required`: Number of compilations each coder must complete.
- `dongle_cooldown`: Time a dongle remains unavailable after being released.
- `fifo|edf`: Scheduling policy used to prioritize requests for dongles.

All time values are expressed in milliseconds.

### Simulation

Each coder runs in its own thread and repeatedly performs the following cycle:

```text
Acquire two dongles
Compile
Release the dongles
Debug
Refactor
```

A coder needs two dongles simultaneously in order to compile.

After a dongle is released, it cannot be reused until its configured cooldown period has expired.

The simulation stops when either:

- every coder has completed the required number of compilations, or
- a coder burns out.

### Burnout

Each coder has a deadline determined by the start time of its most recent compilation.

A dedicated monitor thread continuously checks the coders.

If a coder fails to start another compilation within `time_to_burnout`, the coder burns out and the simulation is stopped.

### Scheduling

Each dongle maintains a priority queue of pending requests.

Two scheduling policies are supported.

#### FIFO

FIFO gives priority to the request that arrived first.

```text
priority = arrival time
```

#### EDF

EDF gives priority to the request with the earliest deadline.

```text
priority = compilation deadline
```

The priority queues are implemented using binary heaps.

### Synchronization

The project uses several synchronization mechanisms:

- `pthread_mutex_t` protects shared state and dongles.
- `pthread_cond_t` is used for synchronization around dongle availability.
- Per-coder mutexes protect mutable coder state.
- A global stop mutex protects the simulation termination state.
- A print mutex prevents concurrent output from being interleaved.

## Blocking cases handled

- **Deadlock:** prevented by changing the dongle acquisition order between odd and even coders, breaking Coffman's circular-wait condition.
- **Starvation:** FIFO and EDF priority queues provide fair resource arbitration.
- **Cooldown:** released dongles remain unavailable until their cooldown expires.
- **Burnout:** a dedicated monitor checks each coder's last compilation time and stops the simulation when a deadline is missed.
- **Logging:** a dedicated mutex serializes output and prevents interleaved messages.

## Thread synchronization mechanisms

- `pthread_mutex_t` protects dongles, coder state, the global stop flag, and logging.
- `pthread_cond_t` is associated with each dongle and broadcasts availability changes to waiting coders.
- Per-coder `state_mutex` prevents races on `compiles` and `last_compile_start`.
- `stop_mutex` provides thread-safe communication between the monitor and coder threads through the shared stop flag.
- `print_mutex` guarantees serialized output.

No custom event abstraction is used; synchronization is implemented directly with POSIX threading primitives.

## Project Structure

```text
src/
├── main.c
├── init.c
├── parse.c
├── simulation.c
├── monitor.c
├── routine.c
├── dongle.c
├── heap.c
├── state.c
├── time.c
├── log.c
└── clean.c
```

The main responsibilities are separated as follows:

- `main.c`: program entry point.
- `parse.c`: argument parsing and validation.
- `init.c`: data structure and synchronization initialization.
- `simulation.c`: thread creation and simulation startup.
- `routine.c`: coder lifecycle.
- `monitor.c`: burnout detection.
- `dongle.c`: dongle acquisition and release.
- `heap.c`: FIFO/EDF priority queue implementation.
- `state.c`: synchronized access to shared state.
- `time.c`: time utilities and interruptible sleep.
- `log.c`: synchronized simulation output.
- `clean.c`: resource cleanup.

## Testing

Memory leaks can be checked with:

```bash
valgrind --leak-check=full ./codexion 4 1200 200 100 100 3 100 fifo
```

Thread synchronization and possible data races can be checked with:

```bash
valgrind --tool=helgrind ./codexion 4 1200 200 100 100 3 100 fifo
```

## Resources

- POSIX Threads documentation (`pthread_create`, `pthread_mutex_*`,
  `pthread_cond_*`).
- Valgrind documentation: Memcheck and Helgrind.
- Operating Systems: Three Easy Pieces (OSTEP), chapters on concurrency.
- General references on FIFO and Earliest Deadline First (EDF) scheduling.
- General references on binary heaps and priority queues.

AI was used as a learning and development assistant for:

- Understanding POSIX threads, mutexes, condition variables, and race conditions.
- Reviewing the concurrency design and identifying synchronization issues.
- Discussing FIFO/EDF scheduling and priority-queue implementation.
- Debugging memory leaks and data races using Valgrind and Helgrind.
- Reviewing code organization and helping document the project.

The implementation was written, tested, and validated by the author.

## Author

María del mar Gómez del Valle
