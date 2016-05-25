/*
	Taller #4 - solucion de la eval4_20151
	Medida de Dispersión: el profesor de un curso desea un programa en lenguaje C que calcule la desviación estándar (símbolo σ o s) 
	de las notas obtenidas por sus estudiantes en el curso.

	A este programa le falta: 
		1.Que el calculo del promedio se haga en n hilos 
		2.Que los datos se lean de un fichero con el formato separado por comas, asi: 5.0;3.5;2.7 ......etc
*/

#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>


typedef struct {
	float *data; 
	int n;
	float average;
}str_params;

//Prototypes
float calculate_average(float *data, int n);
//float calculate_standard_deviation(float *data, int n, float average);
void *calculate_standard_deviation(void* params);
void get_data(float *data, int n);

//Main
int main(int argc, char*argv[]){

	int n;
	float data[100],average;
	float std_deviation;
	pthread_t id;
	str_params params;
	float *response[5];

	average=0,std_deviation=0;

	while(1){
		printf("Introduzca la cantidad de numeros: \n");
		scanf("%d",&n);
		if (n<2){
			printf("Debe ser mayor que 2!!!\n");
			getchar();
		}else{
			get_data(data, n);
			average = calculate_average(data,n); 
			printf("\nEl promedio es: %.2f\n",average);
		
			//std_deviation = calculate_standard_deviation(data, n, average);
			params.n = n;
			params.data = data;
			params.average = average;
		
			pthread_create(&id, NULL, calculate_standard_deviation, &params);
			//int pthread_join(pthread_t thread, void **retval)			
			pthread_join(id, (void **)response);	
		
			printf("\nLa desviacion estandar es: %.2f\n\n\n", *response[0]);
			break;
		}
	}
	free(response[0]);
	return 0;
}

//float calculate_standard_deviation(float *data, int n, float average){
void *calculate_standard_deviation(void *_params){
	
	str_params *params = (str_params *)_params;	
	int i=0;
	float tmp=0, sigma=0;
	float std_deviation=0;
	float *ptr = malloc(sizeof(float));

	while(i < params->n){
		tmp = ((params->data[i] - params->average)*(params->data[i] - params->average));
		//printf("\n: %.2f\n",tmp);
		sigma=sigma  + tmp;
		i++;
	}
	
	printf("\nSigma es: %.2f\n",sigma);
	printf("\nLa varianza es: %.2f\n",sigma/(params->n-1));
	std_deviation = sqrtf((float)sigma/(params->n-1));

	*ptr = std_deviation;
	
	//printf("\nLa desviacion estandar es: %.2f\n\n\n",std_deviation);
	//return (void *)std_deviation;
	pthread_exit(ptr);
} 

float calculate_average(float *data, int n){
	float average = 0, sum = 0; 
	int i;
	for(i=0; i<n; i++){
		sum += *data;
		data++;
	}
	average = sum/n;	
	return average;
} 

void get_data(float *data, int n){
	int i;
	for(i=0; i<n; i++){
		printf("\nIngrese Dato[%d]",i+1);
		scanf("%f",data+i);
	}
}
