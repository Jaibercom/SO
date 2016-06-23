# Taller 5 - Comunicación y Sincronización

## A. Dispersion
[Archivos *dispersion.c (entrega parcial) y dispersion_sol.c (solución)*]  
Diseñe un programa que calcule la dispersión estándar de las notas obtenidas en un curso.  
El programa debe ejecutarse así:  
`./eval5 <notas.csv>`  

### 1. (10%)  
El programa principal debe crear un proceso que calcule el promedio de las notas.

### 2. (10%)  
Un segundo proceso debe calcular la dispersión estándar de las notas.

### 3. (40%)  
Plantee una estrategia usando semáforos y/o mutex para asegurar que se calcule el promedio antes de iniciar el calculo de la dispersión.

### 4. (40%)
Debe utilizar memoria compartida para enviar el promedio de un proceso a otro.


### Condiciones de entrega:
- Los programas deben ​`compilar sin errores`, ​`ejecutar sin problemas` y `no bloquear el equipo`. ​De lo contrario ​la nota es `cero`.

- La interpretación hace parte de la evaluación, `no se responden preguntas` durante el examen.
- Si se evidencia `algún tipo de copia` entre compañeros la nota para ambos es `cero`.
- Nombre del fichero a entregar: eval1_PrimerApellidoPrimerNombre.c.  

`No cumplir con estas condiciones influye en la calificación de su evaluación.`
