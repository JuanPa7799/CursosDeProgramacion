
/******************************************************************************
 * *Ejemplo de servidor de puerto serie con FreeRTOS
 *
 * Este ejemplo espera recibir comandos por medio del puerto serie y los envia
 * otras tareas para que sean ejecutados
 *
 * Incluye una pantalla LED multiplexada de 7 segmentos
 * La pantalla se conecta - anodos de los segmentos a P3.0 - P3.7,
 * catodos de los digitos a P5.0 - P5.2
 *
 * Hecho por Miguelangel Fraga Aguilar
 * Mayo de 2022
 */

// mp430.h se incluye en las cabeceras del port
#include <FreeRTOS.h>
#include <queue.h>
#include <semphr.h>
#include <task.h>

#include <ctype.h>
#include <stdio.h>

#include "driverlib.h"
#include "serieRTOS.h"

#define pxPort_MS_TICS(MS) ( MS / portTICK_PERIOD_MS )

/*Cabecera de la rutina de configuracion de hardware para la aplicacion*/
static void prvSetupHardware(void);

/* Prototypes for the standard FreeRTOS callback/hook functions implemented
within this file. */
void vApplicationMallocFailedHook( void );
void vApplicationIdleHook( void );
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vApplicationTickHook( void );

//Cabecera de las funciones
void initHW();
char explora();

//Constantes globales
const unsigned char tabla7s[17]={0x3f,0x06,0x5b,0x4f,0x66,
0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x7b,0x71,0};

const unsigned char tabla6s[17]={0xbf,0x86,0xdb,0xcf,0xe6,
0xed,0xfd,0x87,0xff,0xe7,0xef,0xf9,0xb1,0x5e,0x7b,0x72,0};

int digitos[3]={16,16,0};
int cont=0, cont2=0, minutos=0, minutos2=0; segundos=0, dsegundos=0, valor=0, incrementa=0, decrementa=0, cont3=0, stopb=0, led=0;
int mins=0, dsecs=0, secs=0, contecla, int serial[4];

//Semaforo binario para la interrupcion
SemaphoreHandle_t xBinarySemaphore;
//Cola para comunicar los eventos de teclado
QueueHandle_t xFilaTeclado;

/* The heap is allocated here so the "persistent" qualifier can be used.  This
requires configAPPLICATION_ALLOCATED_HEAP to be set to 1 in FreeRTOSConfig.h.
See http://www.freertos.org/a00111.html for more information. */
#ifdef __ICC430__
    __persistent                    /* IAR version. */
#else
    #pragma PERSISTENT( ucHeap );   /* CCS version. */
#endif
uint8_t ucHeap[ configTOTAL_HEAP_SIZE ] = { 0 };

/*rutina para configrar los puertos*/
void initHW()
{
     // El teclado se conecta - Renglones (entradas con pull-up) a P6.0-P6.3
     // columnas (salidas en uno) a P8.0 - P8.3
    P6DIR&=0xF0;
    P6OUT|=0x0F;
    P6REN|=0x0F;

    P8DIR|=0x0F;
    P8OUT|=0x0F;
     // La pantalla se conecta - anodos de los segmentos a P3.0 - P3.7,
     // catodos de los digitos a P5.0 - P5.2
    P3DIR=0xFF;
    P3OUT=0;
    P5DIR|=0x07;
    P5OUT|=0x07;
    
    P1DIR |= BIT0;
    P1OUT &= BIT0;

    //Exhibe el digito 0
    P3OUT=tabla7s[digitos[0]];
    
    P5DIR&=~(BIT6|BIT5);//Configura P1.1 y P1.2 como entrada
    P5REN|=(BIT6|BIT5); //Activa las resistencias internas
    P5OUT|=(BIT6|BIT5); //Las configura como Pull-Ups
}


/*rutina para explorar un teclado matricial e indicar si una tecla esta
  presionada y que tecla es la que se presiona*/
char explora(){
    unsigned char columna,renglon,tecla,mascara,mascaraCol;

    tecla=serial[contecla];
	contecla++;
	if (contecla==2)
	{
		contecla=0;
	}
    return(tecla);
}

//BORRAR EN CASO DE NO NECESITARLO
static void vTareaNoRebotes( void *pvParameters )
{
    signed char codigo=-1,codigoInicial=-1;

    (void) pvParameters; //Para evitar advertencia del compilador sobre parametro no usado
    initHW(); //inicializa los puertos
    for(;;){
        //codigoAnterior=codigo;
        codigoInicial=explora();
        if(0!=(codigoInicial&0x80)){//si hay una tecla presionada
            vTaskDelay(pxPort_MS_TICS(10));
            codigo=explora();
            if(0==(codigo&0x80))continue;//si no hay una tecla presionada
            else if(codigo!=codigoInicial) continue;

            vTaskDelay(pxPort_MS_TICS(10));
            codigo=explora();
            if(0==(codigo&0x80)) continue;//si hay una tecla presionada
            else    if(codigo!=codigoInicial) continue;
            //pasar tecla presionada por una cola a la interfaz
            codigo&=0x7f;
            xQueueSendToBack(xColaTeclado,&codigo,0);
            for(;;){
                vTaskDelay(pxPort_MS_TICS(500));
                codigo=explora();
                if(0==(codigo&0x80))break;//si no hay una tecla presionada
                else  if(codigo!=codigoInicial)
                        break;
                //pasar tecla presionada por una cola a la interfaz
                codigo&=0x7f;//retira el indicador de tecla presionada
                xQueueSendToBack(xColaTeclado,&codigo,0);
            }
        }
        vTaskDelay(pxPort_MS_TICS(10));
    }

}


void actualizar(){
    initHW();
    segundos--;
    if (stopb==1&&segundos<0){
        segundos=9;                
        dsegundos--;
        if(dsegundos<0){
            dsegundos=9;
            minutos--;
            if (minutos<0){
                minutos=5;
                minutos2--;
                if(minutos2<0){
                    minutos2=0;
                }
            }

        }

    }

    if(stopb==1){
                            P1OUT |= BIT0; //PRENDE EL LED
                        }
    else if (stopb==2){
                   P1OUT &=~BIT0; ///APAGA EL LED
    }
    if(stopb==1){
        digitos[0]= minutos2;
                    digitos[1]= minutos;
                    digitos[2]= dsegundos; 
 }
    if(stopb==2){
                    digitos[0]= 16;
                    digitos[1]= 16;
                    digitos[2]= 16;
        }
            valor=digitos[0]*16*16+digitos[1]*16+digitos[2];
}

void vPlay(){

    for(;;){
        vTaskDelay(pxPort_MS_TICS(100));
        cont2++;
        if (cont2==4){
            segundos--;
            cont2=0;
            actualizar();
        }
    }
}

void vStop(){

    for(;;){
            digitos[0]= 16;
           digitos[1]= 16;
          digitos[2]= 16;
          vTaskDelay(pxPort_MS_TICS(250));
         valor=digitos[0]*16*16+digitos[1]*16+digitos[2];
         stopb=2;

    }

}


void vTareaPantalla( void *pvParameters ){
    TickType_t xLastWakeTime;
    int digito=0,mascara=0x01;

    (void) pvParameters; //Para evitar advertencia del compilador sobre parametro no usado
    xLastWakeTime = xTaskGetTickCount(); //obtiene el tiempo actual para hacer el evento periodico
    for(;;){
        //Muestra el digito actual por 10mS
        vTaskDelayUntil( &xLastWakeTime, pxPort_MS_TICS(1) );
        //Desactiva el digito actual
        P5OUT|=mascara;

        //Exhibe el sigiuiente digito
        digito++;
        mascara<<=1;
        if(digito>2){
            digito=0;
            mascara=0x01;
        }
        if(cont<2){
            unsigned char temp=tabla7s[digitos[digito]];
                        P3OUT=temp;

            cont++;
        }
        else if(cont>0){
            unsigned char temp=tabla6s[digitos[digito]];
                        P3OUT=temp;
            cont++;
            if (cont==3){
                cont=0; 
            }
                }

        P5OUT&=(~mascara);

    }

}

//TECLAS MSP PLAY STOP
static void vTareaNoRebotes3( void *pvParameters )
{
    int ceros=0,unos=0;
    initHW();
    for(;;){
        do{
            if(0==(P5IN&BIT6)){
                ceros++;
                unos=0;
            }else{
                unos++;
                ceros=0;
            }
            vTaskDelay(pxPort_MS_TICS(10));
        }while(3>unos);
        do{
            if(0==(P5IN&BIT6)){
                ceros++;
                unos=0;
            }else{
                unos++;
                ceros=0;
            }
            vTaskDelay(pxPort_MS_TICS(10));
        }while(3>ceros);
        incrementa=1; //Se presiono la tecla
        stopb=1;
		
        vContador();
    }
}
static void vTareaNoRebotes4( void *pvParameters )
{
    int ceros=0,unos=0, ceros1=0, unos1=0;
    //initHW();
    for(;;){
        do{
            if(0==(P5IN&BIT5)){
                ceros++;
                unos=0;
            }else{
                unos++;
                ceros=0;
            }
            if(0==(P5IN&BIT6)){
                            ceros1++;
                            unos1=0;
                        }else{
                            unos++;
                            ceros=0;
                        }
            vTaskDelay(pxPort_MS_TICS(10));
        }while(3>unos&& 3>unos1);
        do{
            if(0==(P5IN&BIT5)){
                ceros++;
                unos=0;

            }else{
                unos++;
                ceros=0;
            }
            if(0==(P5IN&BIT6)){
                            ceros1++;
                            unos1=0;
                        }else{
                            unos1++;
                            ceros1=0;
                        }
            vTaskDelay(pxPort_MS_TICS(10));
            if(3<ceros1){
                incrementa=1;
            }
            vTaskDelay(pxPort_MS_TICS(10));
        }while(3>ceros);
        decrementa=1; //Se presiono la tecla
        stopb=2;
    }
}


static void vContador( void *pvParameters )
{


    for(;;){
        if(1==incrementa){//Si la tecla esta presionada
            incrementa=0; //borra la bandera
            vPlay();

        }
        if(1==decrementa){//Si la tecla esta presionada
            decrementa=0; //borra la bandera
            vStop();

        }
    }
}

//Tarea de interfaz
void vTareaServidor( void *pvParameters){
    //int indice=2;

    unsigned char c;

#define CALADC12_12V_30C  *((unsigned int *)0x1A1A)   // Temperature Sensor Calibration-30 C
                                                      //See device datasheet for TLV table memory mapping
#define CALADC12_12V_85C  *((unsigned int *)0x1A1C)   // Temperature Sensor Calibration-85 C

    configuraUART();

    // Initialize the shared reference module
    // By default, REFMSTR=1 => REFCTL is used to configure the internal reference
    while(REFCTL0 & REFGENBUSY);              // If ref generator busy, WAIT
    REFCTL0 |= REFVSEL_0 + REFON;             // Enable internal 1.2V reference

    /* Initialize ADC12_A */
    ADC12CTL0 &= ~ADC12ENC;                   // Disable ADC12
    ADC12CTL0 = ADC12SHT0_8 + ADC12ON;        // Set sample time
    ADC12CTL1 = ADC12SHP;                     // Enable sample timer
    ADC12CTL3 = ADC12TCMAP;                   // Enable internal temperature sensor
    ADC12MCTL0 = ADC12VRSEL_1 + ADC12INCH_30; // ADC input ch A30 => temp sense
    //ADC12IER0 = 0x001;                        // ADC_IFG upon conv result-ADCMEMO

    while(!(REFCTL0 & REFGENRDY));            // Wait for reference generator
                                            // to settle
    ADC12CTL0 |= ADC12ENC;
    wrcadserial("Servidor Serie\n\r");
    for(;;){
        //espera indefinidamente a recibir una byte del puerto serie
        if(!serial_vacio()){
            c=getserial();
		if((c>='0')&&(c<='9'){
			int min=c-'0';
			serial[0]=num(c);
			digitos[0]= 16;
	        	digitos[1]= 16;
	        	digitos[2]= serial[0];

		        dsegundos=serial[0];

			while(serial_vacio())vTaskDelay(1);
			if((c>='0')&&(c<='5'){
				int min=c-'0';
				serial[1]=num(c);
				digitos[1]= digitos[2];
        			digitos[2]= serial[1];

        			minutos=serial[1];
        			dsegundos=digitos[2];

				while(serial_vacio())vTaskDelay(1);
				if((c>='0')&&(c<='5'){
					int min=c-'0';
					serial[2]=num(c);
					digitos[0]= digitos[1];
        				digitos[1]= digitos[2];
        				digitos[2]= serial[2];

       					minutos=digitos[1];
       					dsegundos=digitos[2];
        				minutos2=serial[2];
					serial[3]='\0';
					valor=digitos[0]*16*16+digitos[1]*16+digitos[2];
				}
			}
		}
		
			
            if('t'==tolower(c)){
                //  Description: A single sample is made on A10 with internal reference voltage
                //  1.2V. Software manually sets ADC12SC to start sample and conversion and
                //  automatically cleared at EOC. It uses ADC12OSC to convert the sameple.
                //  The Mainloop sleeps the MSP430 in LPM4 to save power until ADC conversion
                //  is completed. ADC12_ISR forces exit from LPMx in on exit from interrupt
                //  handler so that the mainloop can execute and calculate oC and oF.
                //  ACLK = n/a, MCLK = SMCLK = default DCO ~ 1.045MHz, ADC12CLK = ADC12OSC
                //
                //  Un-calibrated temperature measured from device to device will vary due to
                //  slope and offset variance from device to device - please see datasheet.
                //  Note: This example uses the TLV calibrated temperature to calculate
                //  the temperature
                // (the TLV CALIBRATED DATA IS STORED IN THE INFORMATION SEGMENT, SEE DEVICE DATASHEET)
                //

                long temperatureDegC; //en decimas de grado


                ADC12CTL0 |= ADC12SC;                   // Sampling and conversion start

                //Espera el final de la conversion
                while(ADC12IFGR0&ADC12IFG0==0);
                ADC12IFGR0&=~ADC12IFG0;//apaga la bandera de interrupcion
                // Temperature in Celsius. See the Device Descriptor Table section in the
                // System Resets, Interrupts, and Operating Modes, System Control Module
                // chapter in the device user's guide for background information on the
                // used formula.
                temperatureDegC = (((long)ADC12MEM0 - CALADC12_12V_30C) * (85 - 30)*10) /
                        (CALADC12_12V_85C - CALADC12_12V_30C) + 300;
                char cadena[10];
                sprintf(cadena,"%ld",temperatureDegC);
                wrcadserial((unsigned char *)cadena);
            }
            while(serial_vacio())vTaskDelay(1);

        }
    }
}

/*-----------------------------------------------------------*/

int main( void )
{
    /* See http://www.FreeRTOS.org/MSP430FR5969_Free_RTOS_Demo.html */

    /* Configure the hardware ready to run the demo. */
    prvSetupHardware();

    xFilaTeclado=xQueueCreate(16,sizeof(char));
    xBinarySemaphore = xSemaphoreCreateBinary();
    if(xFilaTeclado!=NULL)  {
        xTaskCreate(
            vTareaNoRebotes //Tarea
            ,  (const portCHAR *)"NoRebote" //Nombre
            ,  256      //Tamanio de la pila
            ,  NULL
            ,  4        //Prioridad
            ,  NULL ); //
        
            vTareaPantalla
            ,  (const portCHAR *)"Pantalla" //Nombre
            ,  256      //Tamanio de la pila
            ,  NULL
            ,  4        //Prioridad
            ,  NULL ); //
        xTaskCreate(
            vTareaServidor
            ,  (const portCHAR *)"Servidor" //Nombre
            ,  256      //Tamanio de la pila
            ,  NULL
            ,  3        //Prioridad
            ,  NULL ); //
        xTaskCreate(
            VTareaInterfaz
            ,  (const portCHAR *)"Interfaz" //Nombre
            ,  256      //Tamanio de la pila
            ,  NULL
            ,  4        //Prioridad
            ,  NULL ); //
        xTaskCreate(
            vTareaNoRebotes3 //Tarea
            ,  (const portCHAR *)"NoRebote" //Nombre
            ,  configMINIMAL_STACK_SIZE      //Tamanio de la pila
            ,  NULL
            ,  4        //Prioridad
            ,  NULL ); //Manejador de tarea
        xTaskCreate(
            vTareaNoRebotes4 //Tarea
            ,  (const portCHAR *)"NoRebote2" //Nombre
            ,  configMINIMAL_STACK_SIZE      //Tamanio de la pila
            ,  NULL
            ,  4        //Prioridad
            ,  NULL ); //Manejador de tarea
        xTaskCreate(
            vContador //Tarea
            ,  (const portCHAR *)"Contador" //Nombre
            ,  configMINIMAL_STACK_SIZE      //Tamanio de la pila
            ,  NULL
            ,  4        //Prioridad
            ,  NULL ); //Manejador de tarea


    }
    //arranca el agendador
    vTaskStartScheduler();
    //este codigo no debe ejecutarse
    for(;;);

    //return 0;
}

/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
    /* Called if a call to pvPortMalloc() fails because there is insufficient
    free memory available in the FreeRTOS heap.  pvPortMalloc() is called
    internally by FreeRTOS API functions that create tasks, queues, software
    timers, and semaphores.  The size of the FreeRTOS heap is set by the
    configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */

    /* Force an assert. */
    configASSERT( ( volatile void * ) NULL );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    ( void ) pcTaskName;
    ( void ) pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected.
    See http://www.freertos.org/Stacks-and-stack-overflow-checking.html */

    /* Force an assert. */
    configASSERT( ( volatile void * ) NULL );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
    __bis_SR_register( LPM4_bits + GIE );
    __no_operation();
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
    #if( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 0 )
    {
        /* Call the periodic event group from ISR demo. */
        //vPeriodicEventGroupsProcessing();

        /* Call the code that 'gives' a task notification from an ISR. */
        //xNotifyTaskFromISR();
    }
    #endif
}
/*-----------------------------------------------------------*/

/* The MSP430X port uses this callback function to configure its tick interrupt.
This allows the application to choose the tick interrupt source.
configTICK_VECTOR must also be set in FreeRTOSConfig.h to the correct
interrupt vector for the chosen tick interrupt source.  This implementation of
vApplicationSetupTimerInterrupt() generates the tick from timer A0, so in this
case configTICK_VECTOR is set to TIMER0_A0_VECTOR. */
void vApplicationSetupTimerInterrupt( void )
{
const unsigned short usACLK_Frequency_Hz = 32768;

    /* Ensure the timer is stopped. */
    TA0CTL = 0;

    /* Run the timer from the ACLK. */
    TA0CTL = TASSEL_1;

    /* Clear everything to start with. */
    TA0CTL |= TACLR;

    /* Set the compare match value according to the tick rate we want. */
    TA0CCR0 = usACLK_Frequency_Hz / configTICK_RATE_HZ;

    /* Enable the interrupts. */
    TA0CCTL0 = CCIE;

    /* Start up clean. */
    TA0CTL |= TACLR;

    /* Up mode. */
    TA0CTL |= MC_1;
}
/*-----------------------------------------------------------*/

static void prvSetupHardware( void )
{
    /* Stop Watchdog timer. */
    WDT_A_hold( __MSP430_BASEADDRESS_WDT_A__ );

    /* Set all GPIO pins to output and low. */
    GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    GPIO_setOutputLowOnPin( GPIO_PORT_P3, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    GPIO_setOutputLowOnPin( GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    GPIO_setOutputLowOnPin( GPIO_PORT_PJ, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 | GPIO_PIN8 | GPIO_PIN9 | GPIO_PIN10 | GPIO_PIN11 | GPIO_PIN12 | GPIO_PIN13 | GPIO_PIN14 | GPIO_PIN15 );
    GPIO_setAsOutputPin( GPIO_PORT_P1, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    GPIO_setAsOutputPin( GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    GPIO_setAsOutputPin( GPIO_PORT_P3, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    GPIO_setAsOutputPin( GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 );
    GPIO_setAsOutputPin( GPIO_PORT_PJ, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 | GPIO_PIN8 | GPIO_PIN9 | GPIO_PIN10 | GPIO_PIN11 | GPIO_PIN12 | GPIO_PIN13 | GPIO_PIN14 | GPIO_PIN15 );

    /* Configure P2.0 - UCA0TXD and P2.1 - UCA0RXD. */
    GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN0 );
    GPIO_setAsOutputPin( GPIO_PORT_P2, GPIO_PIN0 );
    GPIO_setAsPeripheralModuleFunctionInputPin( GPIO_PORT_P2, GPIO_PIN1, GPIO_SECONDARY_MODULE_FUNCTION );
    GPIO_setAsPeripheralModuleFunctionOutputPin( GPIO_PORT_P2, GPIO_PIN0, GPIO_SECONDARY_MODULE_FUNCTION );

    /* Set PJ.4 and PJ.5 for LFXT. */
    GPIO_setAsPeripheralModuleFunctionInputPin(  GPIO_PORT_PJ, GPIO_PIN4 + GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION  );

    /* Set DCO frequency to 8 MHz. */
    CS_setDCOFreq( CS_DCORSEL_0, CS_DCOFSEL_6 );

    /* Set external clock frequency to 32.768 KHz. */
    CS_setExternalClockSource( 32768, 0 );

    /* Set ACLK = LFXT. */
    CS_initClockSignal( CS_ACLK, CS_LFXTCLK_SELECT, CS_CLOCK_DIVIDER_1 );

    /* Set SMCLK = DCO with frequency divider of 1. */
    CS_initClockSignal( CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );

    /* Set MCLK = DCO with frequency divider of 1. */
    CS_initClockSignal( CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );

    /* Start XT1 with no time out. */
    CS_turnOnLFXT( CS_LFXT_DRIVE_0 );

    /* Disable the GPIO power-on default high-impedance mode. */
    PMM_unlockLPM5();
}
/*-----------------------------------------------------------*/

int _system_pre_init( void )
{
    /* Stop Watchdog timer. */
    WDT_A_hold( __MSP430_BASEADDRESS_WDT_A__ );

    /* Return 1 for segments to be initialised. */
    return 1;
}


// Port 6 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT6_VECTOR
__interrupt void Port_6(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(PORT6_VECTOR))) Port_6 (void)
#else
#error Compiler not supported!
#endif
{
  BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
  __bic_SR_register_on_exit(LPM4_bits);     // Exit LPM4
  P6IFG &= 0xf0;                           // Borra P6.0 a P6.3 IFG
  P6IE &= 0xf0;                           // Dehabilita interrupciones P6.0 a P6.3
  xSemaphoreGiveFromISR( xBinarySemaphore, &xHigherPriorityTaskWoken );
  portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}