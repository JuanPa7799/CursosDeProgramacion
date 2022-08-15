#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c;
    a=5;
    b=c=10;

    if((a<b) && (b==c))
        printf("Se cumplieron las dos condiciones \n");
    else
        printf("NO se cumplieron las dos condiciones \n");

    if((a>b) || (b<=c))
        printf("Se cumplio minimo una de las dos condiciones \n");
    else
        printf("NO se cumplieron ninguna de las dos condiciones \n");


    return 0;
}
