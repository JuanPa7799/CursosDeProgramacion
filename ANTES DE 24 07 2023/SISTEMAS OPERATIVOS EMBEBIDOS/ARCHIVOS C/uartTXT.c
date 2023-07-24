#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>

int main(int argc, char **argv){
   int file, count;
   
   if(argc!=2){
       printf("Please pass a string to the program, exiting!\n");
       return -2;
   }
   if ((file = open("/dev/ttyACM1", O_RDWR | O_NOCTTY | O_DSYNC ))<0){
      perror("UART: Failed to open the device.\n");
      return -1;
   }
   struct termios options,original;
   tcgetattr(file, &original);
   options=original;
   cfmakeraw(&options);
   options.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR;// | ICRNL;
   tcflush(file, TCIFLUSH);
   tcsetattr(file, TCSANOW, &options);
   
   if ((count = write(file, argv[1], strlen(argv[1])))<0){
      perror("UART: Failed to write to the output\n");
      return -1;
   }
   //write(file, "\n", 1);
   tcdrain(file);//espera a que se vacie el buffer de tx
   usleep(20000);//Bloquea al proceso por 20 mS para asegurar se termine la Tx
   tcsetattr(file,TCSANOW,&original);
   close(file);
   return 0;
}
