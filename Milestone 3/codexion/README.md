*This project has been created as part of the 42 curriculum by magomez-.*

# Codexion

Codexion es un simulador concurrente desarrollado en C que modela un conjunto de coders que compiten por recursos compartidos (dongles) para realizar distintas tareas.

El proyecto implementa sincronización mediante POSIX Threads (`pthread`), exclusión mutua con mutexes, monitorización del estado de los hilos y planificación de acceso a recursos mediante los algoritmos **FIFO** y **Earliest Deadline First (EDF)**.

## Características

- Simulación concurrente mediante `pthread`.
- Sincronización mediante mutexes y variables de condición.
- Monitor dedicado para detectar *burnout*.
- Protección frente a *data races*.
- Planificación de acceso a dongles:
  - FIFO
  - EDF (Earliest Deadline First)
- Cooldown configurable para cada dongle.
- Gestión segura de memoria.
- Compatible con Valgrind y Helgrind.

## Compilación

```bash
make
```

## Ejecución

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

### Ejemplo

```bash
./codexion 4 1200 200 100 100 3 100 fifo
```

## Parámetros

| Parámetro | Descripción |
|-----------|-------------|
| number_of_coders | Número de coders. |
| time_to_burnout | Tiempo máximo sin comenzar una nueva compilación. |
| time_to_compile | Duración de la compilación. |
| time_to_debug | Duración del debugging. |
| time_to_refactor | Duración del refactoring. |
| number_of_compiles_required | Número de compilaciones requeridas para finalizar la simulación. |
| dongle_cooldown | Tiempo durante el cual un dongle permanece indisponible tras liberarse. |
| fifo / edf | Algoritmo de planificación utilizado por los dongles. |

## Arquitectura

```
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

## Sincronización

Cada coder se ejecuta en un hilo independiente.

Los recursos compartidos se protegen mediante:

- `pthread_mutex_t`
- `pthread_cond_t`

El monitor supervisa continuamente el tiempo transcurrido desde el inicio de la última compilación de cada coder para detectar situaciones de *burnout*.

## Planificación

Cada dongle mantiene una cola de peticiones.

Dependiendo del algoritmo seleccionado:

- **FIFO** prioriza la petición más antigua.
- **EDF** prioriza el coder cuyo deadline es más próximo.

## Verificación

El proyecto ha sido validado mediante:

```bash
valgrind --leak-check=full
```

y

```bash
valgrind --tool=helgrind
```

sin fugas de memoria ni condiciones de carrera detectadas.

## Autor

María del mar Gómez del Valle
