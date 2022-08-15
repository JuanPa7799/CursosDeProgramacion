#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Arreglos unidimensionales\n");

    int integerList[3];
    integerList[0]=4;
    integerList[1]=5;
    integerList[2]=6;

    float floatList[]= {23.4, 34.5, 45.5, 21.8, 56.7};

    char charList[4];
    charList[0]='D';
    charList[1]='a';
    charList[2]='n';
    charList[3]='i';

    printf("\n Pimer entero: \t\t %i", integerList[0]);
    printf("\nMi Ultimo flotante: \t\t %f", floatList[4]);
    printf("\nLista de caracteres: \t\t %c%c%c%c",charList[0],charList[1],charList[2],charList[3]);

    return 0;
}
