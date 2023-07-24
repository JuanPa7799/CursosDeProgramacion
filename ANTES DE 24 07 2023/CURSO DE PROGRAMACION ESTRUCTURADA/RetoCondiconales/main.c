#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("Dime el primer numero a comparar\n");
    scanf("%i", &a);
    printf("Dime el segundo numero a comparar\n");
    scanf("%i", &b);
    if(a < b){
        printf("El numero menor es: %i\n", a);
    }    else if (b<a)    {
        printf("El numero menor es: %i\n", b);
    }     else    {
        printf("Ambos numeros son iguales\n");
    }
    float cal;
    printf("Dime tu calificaicon alumno: \n");
    scanf("%f", &cal);
    if(cal<60)
    {
        printf("Estas reprobado");

    }
    else
    {
        if(cal<=90)
        {
            printf("Estas aprobado ");
        }
        else        {
            printf("Estas aprobado  c: 'w' ");
        }
    }

    return 0;
}
