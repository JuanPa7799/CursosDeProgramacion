#include <stdio.h>
#include <stdlib.h>

int main()
{
    int val = 5;
    int lect;


    printf("Ingresa un numero del 1 al 10 para adivinar\n");
    scanf("%i", &lect);
    if(lect == val)
    {
        printf("Haz adivinado el numero!!\n");
        return 0;
    }
    else
    {
        printf("Suerte la proxima. \n vuelvelo a intentar.\n");
        main();
    }
    return 0;
}
