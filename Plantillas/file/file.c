#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 500

typedef struct {
  char name[20];
  int quantity;
} structure_name;

void lineProcess(char *line, char *sep, structure_name *my_structure);

int main (int argc, char *argv[]) {
  int i = 0;
  char sep;
  char line[MAX];
  char *fileName;
  FILE *file;
  structure_name *my_structure;

  if (argc != 2) {
    puts('Error al ejecutar, debes hacerlo de la siguiente forma');
    printf('%s archivo.csv', argv[0]);
  }

  sep = ',';
  fileName = argv[1];

  file = fopen(fileName, "r");

  my_structure = malloc(sizeof(my_structure) * 2);

  while (!feof(file)) {
    fgets(line, MAX, file);
    lineProcess(line, &sep, my_structure + i);

    printf("%s\n", (my_structure + i)->name);
    printf("%d\n", (my_structure + i)->quantity);

    i++;
  }

  fclose(file);

  return 0;
}

void lineProcess(char *line, char *sep, structure_name *my_structure) {
  char *pch;

  pch = strtok(line, sep);
  strcpy(my_structure->name, pch);

  pch = strtok (NULL, sep);
  my_structure->quantity = atoi(pch);
}
