// gcc spawn_sol.c -o spawner
// ./spawner programa.c ./programa

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int spawn (char* program, char** arg_list)
{
    pid_t child_pid;
    
    child_pid = fork ();
    if (child_pid > 0){
        wait(NULL);
        printf("Mi hijo finalizo la ejecucion de: %s\n", program);
        return child_pid;
    } else {
        execvp (program, arg_list);
        fprintf (stderr, "Ocurrio un error con execvp: %s\n", program);
        abort ();
    }
}

int main (int argc, char *argv[] )
{
    printf("Inicia el programa principal\n");
    
    char* arg_list[] = {    // gcc programa.c -o ./programa
        "gcc",
        argv[1],
        "-o",
        argv[2],
        NULL
    };
    
    char* arg_list2[] = {   // ./programa
        argv[2],
        NULL
    };
    
    spawn (arg_list[0], arg_list); 
    sleep(2);
    spawn (arg_list2[0], arg_list2); 
    
    printf ("Finaliza el programa principal\n");
    
    return 0;
}
