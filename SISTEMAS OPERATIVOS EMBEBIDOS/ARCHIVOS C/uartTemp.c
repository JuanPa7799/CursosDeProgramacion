#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>

int main(int argc, char **argv){
   int file, count; //declara contadpr y archivo tipo entero	
   char cadena[100]; //crea una cadena de 100 valores

   if ((file = open("/dev/ttyACM1", O_RDWR | O_NOCTTY ))<0){       //detecta el error de abrir archivo
      perror("UART: Failed to open the device.\n");                
      return -1; // regresa un menos uno en lugar de cero.
   }
   struct termios options,original;   
   tcgetattr(file, &original);
   options=original;
   cfmakeraw(&options);
   options.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR;// | ICRNL;
   tcflush(file, TCIFLUSH);
   tcsetattr(file, TCSANOW, &options);
   cadena[0]='t'; //declara el primer argumento del arreglo como tmeperatura
   //printf("Escribiendo al puerto: %c\n",cadena[0]);
   if ((count = write(file, cadena, 1))<0){
      perror("UART: Failed to write to the output\n");
      return -1;
   }
   //write(file, "\n", 1);
   count=read(file,cadena,5);
   cadena[count]='\0';
   //printf("Se recibio: %s\n",cadena);
   printf("%s\n",cadena);
   tcsetattr(file,TCSANOW,&original);
   close(file);
   return 0;
}
