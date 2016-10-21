# Números Aleatorios

## Enunciado

Se desea generar 10 números aleatorios entre 0 y 999, cada número debe ser generado en un hilo diferente, luego en el programa principal debe tomar estos números, ordenarlos de acuerdo al hilo y listar el número generado.

## Compilación

```
gcc -Wall random.c -o random.out
```

## Ejecución

```
./random.out
```

## Resultado

```
Hilo 1 -> 12
Hilo 3 -> 100
Hilo 4 -> 103
Hilo 8 -> 65
Hilo 5 -> 2
Hilo 9 -> 2
Hilo 2 -> 54
Hilo 6 -> 5
Hilo 7 -> 24
Hilo 10 -> 54

Hilo 1 -> 12
Hilo 2 -> 54
Hilo 3 -> 100
Hilo 4 -> 103
Hilo 5 -> 2
Hilo 6 -> 5
Hilo 7 -> 24
Hilo 8 -> 65
Hilo 9 -> 2
Hilo 0 -> 54
```