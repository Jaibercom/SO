# Semáforos

## Enunciado

Se desea crear 2 hilos que compartan el mismo semáforo, el primer hilo debe aumentar 10 veces el semáforo cada segundo e imprimir en consola la acción realizada, el segundo hilo debe esperar el semáforo e imprimir un contador con las veces que ha incrementado el semáforo.

Implementar el mismo problema con procesos, el resultado debe ser el mismo.

## Compilación hilos

```
gcc -pthread hilos.c -o hilos.out
```

## Ejecución hilos

```
./hilos.out
```

## Compilación procesos

```
gcc -pthread procesos.c -o procesos.out
```

## Ejecución procesos

```
./procesos.out
```

## Resultado

```
Incrementando el semáforo.
El semáforo aumentó 1
Incrementando el semáforo.
El semáforo aumentó 2
Incrementando el semáforo.
El semáforo aumentó 3
Incrementando el semáforo.
El semáforo aumentó 4
Incrementando el semáforo.
El semáforo aumentó 5
Incrementando el semáforo.
El semáforo aumentó 6
Incrementando el semáforo.
El semáforo aumentó 7
Incrementando el semáforo.
El semáforo aumentó 8
Incrementando el semáforo.
El semáforo aumentó 9
Incrementando el semáforo.
El semáforo aumentó 10
```