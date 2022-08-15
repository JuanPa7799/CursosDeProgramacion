#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Arreglo bidimensional\n");

    int bidimensonalArray [4][4];

    bidimensonalArray[0][0]= 11;
    bidimensonalArray[0][1]= 12;
    bidimensonalArray[0][2]= 13;
    bidimensonalArray[0][3]= 14;

    bidimensonalArray[1][0]= 29;
    bidimensonalArray[1][1]= 28;
    bidimensonalArray[1][2]= 27;
    bidimensonalArray[1][3]= 126;

    bidimensonalArray[2][0]= 36;
    bidimensonalArray[2][1]= 35;
    bidimensonalArray[2][2]= 34;
    bidimensonalArray[2][3]= 33;

    bidimensonalArray[3][0]= 45;
    bidimensonalArray[3][1]= 46;
    bidimensonalArray[3][2]= 47;
    bidimensonalArray[3][3]= 48;

    printf("Valor den (0,0): %i \n", bidimensonalArray[0][0]);
    printf("Valor den (0,1): %i \n", bidimensonalArray[0][1]);
    printf("Valor den (0,2): %i \n", bidimensonalArray[0][2]);
    printf("Valor den (0,3): %i \n", bidimensonalArray[0][3]);

    return 0;
}
