# Números Aleatorios

## Enunciado

Se desea generar 10 números aleatorios entre 0 y 999 de forma paralela, luego en el proceso padre tomar estos números, ordenarlos de acuerdo al proceso y listar el número generado.

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
Proceso hijo 101 -> 12
Proceso hijo 103 -> 100
Proceso hijo 104 -> 103
Proceso hijo 108 -> 65
Proceso hijo 105 -> 2
Proceso hijo 109 -> 2
Proceso hijo 102 -> 54
Proceso hijo 106 -> 5
Proceso hijo 107 -> 24
Proceso hijo 110 -> 54

Proceso 101 -> 12
Proceso 102 -> 54
Proceso 103 -> 100
Proceso 104 -> 103
Proceso 105 -> 2
Proceso 106 -> 5
Proceso 107 -> 24
Proceso 108 -> 65
Proceso 109 -> 2
Proceso 110 -> 54
```