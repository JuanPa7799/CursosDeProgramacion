#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Arreglo bidimensional\n");

    int bidimensonalArray [3][4]={{1, 0, 2, 1},
                                  {3, 4, 2, 1},
                                  {10, 9, 3, 4}};
    int suma[3]={0,0,0};
    int j, i;

    for(i =0; i<3; i++)
    {
        for (j = 0; j<4; j++)
        {
            suma[i]=(suma[i]+bidimensonalArray[i][j]);
        }
        printf("La suma de la primer fila es: %i \n", suma[i]);
    }




    return 0;
}
