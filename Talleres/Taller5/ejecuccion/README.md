# Examen 2016-1

## Enunciado

Se desea controlar 3 hilos para que se ejecuten en secuencia, primero el hilo 1, luego el 2 y por último el 3. El orden de creación de los hilos debe ser primero el 3, luego el 2 y por último el 1.

Implementar 2 soluciones diferentes, una con memoría compartida y otra con 2 semáforos, el resultado debe ser el mismo.

## Compilación semáforos

```
gcc -pthread semaforo.c -o semaforo.out
```

## Ejecución semáforos

```
./semaforo.out
```

## Compilación memoria compartida

```
gcc -pthread compartida.c -o compartida.out
```

## Ejecución memoria compartida

```
./compartida.out
```

## Resultado

```
Hilo 1 termino.
Hilo 2 termino.
Hilo 3 termino.
```