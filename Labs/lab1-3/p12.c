#include <stdio.h>
#define NUMCHAR 20

char nombres[3][NUMCHAR] = {"fulano","mengano", "perano"};

int main(void)
{
   char i;
   char *a;
   char (*b)[NUMCHAR];

   a = (char *)&nombres[0];
   printf("el nombre es %s \n\n",a);
	a++;
	printf("el nombre es %s \n\n",a);
	
	b = (char (*)[NUMCHAR])&nombres[0];
	printf("el nombre es %s \n\n",(char *)b);	
	b++;
	printf("el nombre es %s \n\n",(char *)b);


   /*b = (char (*)[NUMCHAR])nombres[0];
   for(i = 0;i < 3; i++)
   {
      printf("el nombre[%d] es %s \n",i,(char *)(b+i));
   }*/
   return 0;
}

