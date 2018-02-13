/*
 ============================================================================
 Nombre      : bankers_algorithm.c
 Description : Program to check if a system is in safe state 
 Compilacion : gcc -Wall bankers_algorithm.c -o bankers
 Ejecutar    : ./bankers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
 #include <pthread.h>

//Declaración de funciones
void printInitData();
void initData();
void *calculate_is_mayor(void *_params);

//Inicializando los valores iniciales
int p = 5;      //Número de procesos
int r = 3;      //Número de recuersos
int Max[10][10] = { { 7, 5, 3},
                    { 3, 2, 2},
                    { 7, 0, 2},
                    { 2, 2, 2},
                    { 4, 3, 3}};

int alloc[10][10] = { { 0, 2, 0 },
                      { 3, 0, 2 }, 
                      { 3, 0, 2 },
                      { 2, 1, 1 },
                      { 0, 0, 2 }};

int avail[10] = { 2, 2, 0 };
int need[10][10], finish[10];

int main(int argc, char* argv[]){   
    int i, j;
    int process, count, find;
    pthread_t id[10];
    int *response[10];
    int k[10];

    count = p;
    find = 1;

    initData();
    printInitData();

    //Main procedure goes below to check for unsafe state.
    while (count >= 0 && find == 1) {
        find = 0;
        printf("\nIteracion = %d", p-count+1);
        for (i = 0; i < p; i++) 
        {
            if (finish[i] == 0) 
            {
                k[i] = i;
                //printf("**calculate_is_mayor, i=%d\n", k[i]);
                pthread_create(&id[i], NULL, calculate_is_mayor, &k[i]);
            }
        }

        for (i = 0; i < p; i++) 
        {
            if (finish[i] == 0) 
            {
                pthread_join(id[i], (void **)&response[i]);
                //printf("\nresponse[%d] %d", i, *response[i]);

                if (*response[i] == 1) {
                    printf("\nProcess%d finished", i);
                    finish[i] = 1;
                    count--;
                    find = 1;

                    for (j = 0; j < r; j++) 
                    {
                        avail[j] += alloc[i][j];
                    }
                }
            }
        }

        if (find) {
            printf("\nAvailable vector:");

            for (i = 0; i < r; i++) {
                printf(" %d", avail[i]);
            }
            printf("\n");

        }else{          //No se encontró ningun i que cumpla con el criterio need < avail(i)
            if(count>0)     
                printf("\nThe processes are in unsafe state.\n");
            else
                printf("\nThe processes are in safe state.\n");
            break;
        }
    }
}


void *calculate_is_mayor(void *_param){
    
    int i = *((int *)_param);
    int j;
    int *ptr = malloc(sizeof(float));
    int exec = 1;

    //printf("calculate_is_mayor, i=%d\n", i);

    for (j = 0; j < r; j++) 
    {
        if (need[i][j] > avail[j]) 
        {
            exec = 0;
            break;
        }
    }
    *ptr = exec;
    pthread_exit(ptr);
} 


void initData(){
    int i,j;
    //Inicializando la matriz need y el vector finish
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < r; j++)
        {
            need[i][j] = Max[i][j] - alloc[i][j];
        }
        finish[i] = 0;
    }

}

//Imprimiendo los valores iniciales
void printInitData(){
   int i,j;
    printf("\n MAX\t\tAlloc\t\tNeed\t\tAvail\n");
    for(i = 0; i < p; i++)
    {
        for( j = 0; j < r; j++){
            printf("%d ", Max[i][j]);
        }
        
        printf("\t\t");
        for( j = 0; j < r; j++){
            printf("%d ", alloc[i][j]);
        }
        
        printf("\t\t");
        for( j = 0; j < r; j++){
            printf("%d ", need[i][j]);
        }

        if(i == 0){
            printf("\t\t");
            for( j = 0; j < r; j++)
            {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}


