#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 500

typedef struct {
  char name[20];
  int quantity;
} structure_name;

void validateArgs(int argc, char *argv[]);
FILE *openFile(char *filename, char *mode);
void readFile(FILE *file, structure_name *my_structure);
void lineProcess(char *line, structure_name *my_structure);
void printData(structure_name *my_structure);

int main (int argc, char *argv[]) {
  FILE *file;
  structure_name *my_structure;

  validateArgs(argc, argv);

  file = openFile(argv[1], "r");

  my_structure = malloc(sizeof(my_structure) * 2);

  readFile(file, my_structure);

  printData(my_structure);

  fclose(file);

  return 0;
}

void validateArgs(int argc, char *argv[]) {
  if (argc != 2) {
    puts("Error al ejecutar, debes hacerlo de la siguiente forma");
    printf("%s data.csv\n", argv[0]);
    exit(1);
  }
}

FILE *openFile(char *filename, char *mode) {
  FILE *file;

  file = fopen(filename, mode);

  if (!file) {
    printf("Error al abrir el archivo: %s\n", filename);
    exit(1);
  }

  return file;
}

void readFile(FILE *file, structure_name *my_structure) {
  int i = 0;
  char line[MAX];

  while (fgets(line, MAX, file)) {
    lineProcess(line, my_structure + i);

    i++;
  }
}

void lineProcess(char *line, structure_name *my_structure) {
  char *pch;
  char sep[] = ",";

  pch = strtok(line, sep);
  strcpy(my_structure->name, pch);

  pch = strtok (NULL, sep);
  my_structure->quantity = atoi(pch);
}

void printData(structure_name *my_structure) {
  int i;

  for (i = 0; i < 2; i++) {
    printf("Nombre: %s\n", (my_structure + i)->name);
    printf("Cantidad: %d\n", (my_structure + i)->quantity);
  }
}
