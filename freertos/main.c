/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

#define mainBUS_CLK_FULL	((unsigned char)0x01)

#define mainCHECK_TASK_PRIORITY	 (tskIDLE_PRIORITY+3)

static void vLEDTask(void* pvParameters){	
		while(1){
				IOSET0 = ( 1<< 10 );
				vTaskDelay(100);
			  IOCLR0 = ( 1<< 10 );
				vTaskDelay(100);
		}
}

static void vLEDTask1(void* pvParameters){		
		while(1){
				IOSET0 = ( 1<< 9 );
				vTaskDelay(100);
			  IOCLR0 = ( 1<< 9 );
				vTaskDelay(100);
		}
}

static void prvSetupHardware( void );

int main( void ){
	IODIR0 |= ( 1<< 9 );
	IODIR0 |= ( 1<< 10 );
	prvSetupHardware();
	xTaskCreate( vLEDTask, "LED", configMINIMAL_STACK_SIZE, NULL, mainCHECK_TASK_PRIORITY, NULL );
  xTaskCreate( vLEDTask1, "LED1", configMINIMAL_STACK_SIZE, NULL, mainCHECK_TASK_PRIORITY, NULL );
	vTaskStartScheduler();
	for( ;; );
}


static void prvSetupHardware(void){
	VPBDIV = mainBUS_CLK_FULL;//PCLK=60MHz
}




