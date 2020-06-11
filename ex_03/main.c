/*
 * Aufgabe_3
 *
 * Author : AWZ
 */

#include "sam.h"
#include "sdram.h"
#include "device_startup/system_same70.h"
#include "LIB_ATSAME70.h"
#include "board_cortex7.h"
#include "mpu.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "dbgu.h"
#include "stdint.h"

#include "board_leds.h"
#include "debug_extend.h"
#include "ascii_art.h"
#include "dm9000.h"




void WDT_Disable(Wdt *pWDT)
{
	pWDT->WDT_MR = WDT_MR_WDDIS;
}

char dat[10];

char *my_itoa(int wert, int laenge) {
	int i;

	for(i  =0; i < laenge; i++) {
		dat[laenge-i-1] = (wert % 10) + 48;
		wert = wert / 10;
	}
	dat[laenge]='\0';
	return &dat[0];
}


int main(void)
{
    /* Initialize the SAM system */
	SystemClkInit();
	SystemInit();
	soft_reset();				//reset VS1053, LCD, SI4684,  ...
	SCB_InvalidateDCache();		//after reset, you must invalidate each cache before enabling it.
	SCB_InvalidateICache();
	WDT_Disable(WDT);
	MPU_Configure();
	SCB_EnableICache();
	board_init();
	dbgu_uart_init();
	dbgu_clear();
	mes();
	serial_welcome();
	print_mcu_spec();
	calibrate_delayus();
	SCB_DisableDCache();
	sdramc_init();

/* START der AUFGABE 3
******************************************************
	//AUFGABE 3
******************************************************
*/
#define ETHERNET_TEST_REGISTER 0x60000004
//	uint16_t test_data;
	dm9000_init();
	dm9000_read_table(ETHERNET_TEST_REGISTER, 16);


	while(1)
    {


	}

}
