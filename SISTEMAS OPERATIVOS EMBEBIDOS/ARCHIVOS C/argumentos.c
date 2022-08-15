


#include <stdio.h>

int main(int argc, char **argv)
{
	int indice;
	for(indice=0;indice<argc;indice ++){
		printf("%s\n",argv[indice]);
	}
	return 0;
}

