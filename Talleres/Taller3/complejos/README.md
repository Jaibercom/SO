# Números Complejos

## Enunciado

Se desea realizar la suma, resta y multiplicación de n números complejos, que se encuentran en el archivo ```complejos.csv```, se deben tomar por parejas y realizar las tres operaciones mencionadas en un proceso, los procesos deben correr de forma paralela.

## Compilación

```
gcc -Wall complex.c -o complex.out
```

## Ejecución

```
./complex.out complejos.csv
```

## Resultado

El orden del resultado puede variar dependiendo del procesamiento

```
PID X -> Suma: real + imaginario
PID Y -> Suma: real + imaginario
PID Z -> Suma: real + imaginario
PID Z -> Resta: real + imaginario
PID Z -> Multiplicación: real + imaginario
PID X -> Resta: real + imaginario
PID Y -> Resta: real + imaginario
PID Y -> Multiplicación real + imaginario
PID X -> Multiplicación real + imaginario
```
