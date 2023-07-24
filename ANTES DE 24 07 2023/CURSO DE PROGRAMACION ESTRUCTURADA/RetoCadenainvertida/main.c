#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Cadena de caracteres\n");

    char nameC[50];

    int size;

    printf("Ingresar el nombre que queires invertido: \n");

    gets(nameC);
    size=strlen(nameC);
    printf("\n");a

    for (int i=5;i>=1; i--)
    {
        int j=i-1;
        printf("%c",nameC[j]);
        printf("\n");
    }


    return 0;
}
