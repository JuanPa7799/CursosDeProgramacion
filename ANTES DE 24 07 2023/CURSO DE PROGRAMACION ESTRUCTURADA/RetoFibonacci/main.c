#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mem1=1, mem2=1, bottomLim, fibo;

    printf("Imprimir secuendcia de Fibonacci\n");

    printf("Ingresar numero de vuieltasr;\n");
    scanf("%i", &bottomLim);

    for(int i=1; i <= bottomLim; i++)
    {
        if(i==1){
            fibo=i;
            printf("%i\n", fibo);
            mem1=fibo;
            mem2=1;
        }
        else{
            fibo=mem1+mem2;
            printf("%i\n", fibo);
            mem2=mem1;
            mem1=fibo;
        }
    }
    return 0;
}
