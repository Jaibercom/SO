#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

typedef struct {
  char kind;
  char name[20];
  char gender;
  int age;
} Pet;

FILE *openFile(char *filename, char *mode); // Abre un archivo para escritura o lectura
Pet *readFile(FILE *file); // Lee y procesa un archivo
Pet *increasePets(Pet *pets); // Aumenta la memoria dinámica
void lineProcess(char *line, Pet *pet); // Procesa una línea del archivo
void writeFile(FILE *file, Pet *pets, char kind); // Escribe en un archivo separando entre especie
void printPets(Pet *pets); // Muestra todas las mascotas

int count = 0;

int main (int argc, char *argv[]) {
  FILE *input, *output1, *output2;
  Pet *pets;

  if (argc != 4) {
    puts("Error al ejecutar, debes hacerlo de la siguiente forma");
    printf("%s <archivo_entrada> <archivo_salida_perros> <archivo_salida_gatos>\n", argv[0]);
    return 1;
  }

  // Abrir los 3 archivos
  input = openFile(argv[1], "r");
  output1 = openFile(argv[2], "w+");
  output2 = openFile(argv[3], "w+");

  // Leer el archivo y guardar los datos en la estructura
  pets = readFile(input);

  // Escribir los archivos filtrados por perros y gatos
  writeFile(output1, pets, 'C');
  writeFile(output2, pets, 'F');

  // Mostrar las mascotas en consola
  printPets(pets);

  // Cerrar los archivos
  fclose(input);
  fclose(output1);
  fclose(output2);

  // Liberar memoria
  free(pets);

  return 0;
}

FILE *openFile(char *filename, char *mode) {
  FILE *file;

  file = fopen(filename, mode);

  // Validar si el archivo fue abierto
  if (!file) {
    printf("Error al abrir el archivo: %s\n", filename);
    exit(1);
  }

  return file;
}

Pet *readFile(FILE *file) {
  Pet *pets = NULL;
  char line[MAX];

  // Leer la primer linea del archivo y no realizar ninguna operación con ella
  fgets(line, MAX, file);

  // Mientras se leen las lineas, se incrementa la memoria dinamica y se guardan los datos
  while (fgets(line, MAX, file)) {
    pets = increasePets(pets);

    lineProcess(line, (pets + count - 1));
  }

  return pets;
}

Pet *increasePets(Pet *pets) {
  count++;

  pets = (Pet *)realloc(pets, sizeof(Pet) * count);

  if (pets == NULL) {
    puts("Error al incrementar la memoria.");
    exit(1);
  }

  return pets;
}

void lineProcess(char *line, Pet *pet) {
  char *pch;
  char sep[] = ",";

  pch = strtok(line, sep);
  pet->kind = *pch;

  pch = strtok(NULL, sep);
  strcpy(pet->name, pch);

  pch = strtok(NULL, sep);
  pet->gender = *pch;

  pch = strtok (NULL, sep);
  pet->age = atoi(pch);
}

void writeFile(FILE *file, Pet *pets, char kind) {
  int i;

  for (i = 0; i < count; i++) {
    if ((pets + i)->kind == kind) {
      fprintf(file, "%c|%s|%c|%d\n", (pets + i)->kind, (pets + i)->name, (pets + i)->gender, (pets + i)->age);
    }
  }
}

void printPets(Pet *pets) {
  int i;

  for (i = 0; i < count; i++) {
    printf("%c|%s|%c|%d\n", (pets + i)->kind, (pets + i)->name, (pets + i)->gender, (pets + i)->age);
  }
}
