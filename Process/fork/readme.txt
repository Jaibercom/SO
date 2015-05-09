Ejecute en el siguiente orden:

1.ejecute fork_example.c y verifique el valor de A.
Que valor es y explique porque?

2.ejecute fork_many_process.c
Determine el numero de procesos en ejecución y porqué?

3.ejecute fork_getpid.c
Verifique las llamadas al sistema getpid y getppid para obtener los identificadores del proceso.
Ademas verifique como se puede devolver el estado al terminar el proceso hijo al padre

4.Ejecute fork_orphan.c
	En otra consola digite: ps -la y verifique el estado 
	Verifique ahora cual es el proceso padre usando "ps -aux"

5.Ejecute fork_zombie.c
	En otra consola digite: ps -aux | grep Z   	ó:	ps -la	 y verifique el estado 

6.ejecute fork_exec.c
Explique el funcionamiento del programa y del llamado "exec" y sus variantes.


Nota: no olvide el comando "man" o "help" para obtener información de las funciones en c.
ejemplo: man execpl
	execpl --help 
 
