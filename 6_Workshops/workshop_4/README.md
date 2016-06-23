# Taller 4 - Hilos

## A. Inclusión-Exclusión
[Archivo *inclusion_exclusion.c*]  
Diseñe un programa que calcule la suma de los multiplos de `x` e `y` en `z`:
### 1. (10%)  
El programa debe ejecutarse así:  
`./eval4 <num1> <num2> <num3>`

### 2. (60%)  
El programa debe tener la función `void *sumkn(void *),` con la cual se deben crear 3 hilos.

### 3. (30%)  
Se debe retornar el valor de cada hilo y calcular el resultado final.  

### Bonus (20%)
Calcule sumkn(n) en p hilos, donde p es el número de hilos.

### Bonus (10%)
Calcule el tiempo de ejecución de cada hilo.

## B. Desviación
[Archivo *desviacion.c*]  
Diseñe un programa que permita calcular la desviación estándar de las notas obtenidas por los estudiantes de un curso.
- El programa debe calcular el promedio con n hilos.
- Los datos deben ser leidos de un fichero con un formato separado por comas.

### Condiciones de entrega:
- Los programas deben ​`compilar sin errores`, ​`ejecutar sin problemas` y `no bloquear el equipo`. ​De lo contrario ​la nota es `cero`.

- La interpretación hace parte de la evaluación, `no se responden preguntas` durante el examen.
- Si se evidencia `algún tipo de copia` entre compañeros la nota para ambos es `cero`.
- Nombre del fichero a entregar: eval1_PrimerApellidoPrimerNombre.c.  

`No cumplir con estas condiciones influye en la calificación de su evaluación.`
