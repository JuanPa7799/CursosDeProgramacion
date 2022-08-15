#include <stdio.h>
#include <stdlib.h>

int Pot(int a, int b)
{
    int res = 1;
    if(b==0){
    res=1;
    }

    for(int i=1;i<=b;i++){
    res=res*a;
    }

    return res;
}

int main()
{
    printf("Funciones\n");

    int numero= Pot(2,8);

    printf("Resultado es: %i", numero);

    return 0;
}
