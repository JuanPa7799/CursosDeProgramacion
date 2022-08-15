#include <stdio.h>
#include <stdlib.h>

char publicText[]={"\nTexto en una varibale global"};

void check()
{
    printf("\n Imprimir desde la funcion: check");

    printf("\nvariable global:");
    printf("%s", publicText);

    printf("\nVariable local: \n");
    printf("%s", privateText);

}


int main()
{
    printf("Variables globales.\n");
    printf("%s", publicText);

    char privateText[]={"\nTexto en una variable local. \n"};
    printf("%s", privateText);

    check();


    return 0;
}
