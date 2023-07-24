#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Arreglos unidimensionales\n");

    int integerList[5];
    int b;
    int mult=1;

    for(int i=0; i<5;i++){
        b=i+1;
        printf("Valor[%i]: ", b);
        scanf("%i", &integerList[i]);
        mult=mult*integerList[i];
    }

    printf("\n El resultado es: %i", mult);
    return 0;
}
