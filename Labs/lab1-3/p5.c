#include <stdio.h>

int main(void)
{

   int a = 3;
   int b = 3;
   int c = 8;
   int d;

   int *p1 = &a;
   int *p2;
   int *p3 = &c;

   *p1 = 2;
   p2 = p3;
   *p2 = *p1-b;
   d = (*p2)*(*p1);
   p3 =  &d;
   b = a + b + c;

   printf("Valor de a: %d\n",a);
   printf("Dir a: %x\n",(int)&a);
   printf("Valor de b: %d\n",b);
   printf("Dir b: %x\n",(int)&b);
   printf("Valor de c: %d\n",c);
   printf("Dir c: %x\n",(int)&c);
   printf("Valor de d: %d\n",d);
   printf("Dir d: %x\n",(int)&d);

   printf("Valor de p1: %x\n",(int)p1);
   printf("Valor de p2: %x\n",(int)p2);
   printf("Valor de p3: %x\n",(int)p3);
   return(0);
}

