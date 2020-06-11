/*
 *
 * board_leds.c
 *
 * function_file for LED APIs for handling varios interaction with onboard LEDs
 *  Author: Sven Prigann
 */ 

#include "board_leds.h"
void decoder_init(void)
{
	ATSAME70_PIO_CfgOutput(DECODER_A_PORT,DECODER_A_PIN);
	ATSAME70_PIO_CfgOutput(DECODER_B_PORT,DECODER_B_PIN);
	ATSAME70_PIO_CfgOutput(DECODER_C_PORT,DECODER_C_PIN);
	ATSAME70_PIO_CfgOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
	
}
// Api for enabling or disabling a specific LED with their Pseudonym led0, led1,...
void led_mgr(unsigned long led_num, int EnorDI)
{
	Pio *led_port = 0;
	switch (led_num)
	{
	case LED0:
	led_port = LED0_PORT;
	dbgu_puts("LED0\n");
	break;
	case LED1:
	led_port = LED1_PORT;
	dbgu_puts("LED1\n");
	break;
	case LED2 :
	led_port = LED2_PORT;
	dbgu_puts("LED2\n");
	break;
	case LED3 : 
	if(EnorDI == ENABLE)
	{
		//Not attached
		ATSAME70_PIO_ClearOutput(DECODER_A_PORT, DECODER_A_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_B_PORT, DECODER_B_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_C_PORT, DECODER_C_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED3-ON- not attached\n");
	}
	else
	{
		ATSAME70_PIO_SetOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED3-OFF- not attached\n");
	}
	break;
	case LED4 :
	if(EnorDI == ENABLE)
	{
		
		ATSAME70_PIO_SetOutput(DECODER_A_PORT, DECODER_A_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_B_PORT, DECODER_B_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_C_PORT, DECODER_C_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED4-ON\n");
		
	}
	else
	{
		ATSAME70_PIO_SetOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED4-OFF\n");
	}
	break;
	case LED5 :
	if(EnorDI == ENABLE)
	{
		
		ATSAME70_PIO_ClearOutput(DECODER_A_PORT, DECODER_A_PIN);
		ATSAME70_PIO_SetOutput(DECODER_B_PORT, DECODER_B_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_C_PORT, DECODER_C_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED5-ON\n");
	}
	else
	{
		ATSAME70_PIO_SetOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED5-OFF\n");
	}
	break;
	case LED6 :
	if(EnorDI == ENABLE)
	{
		
		ATSAME70_PIO_SetOutput(DECODER_A_PORT, DECODER_A_PIN);
		ATSAME70_PIO_SetOutput(DECODER_B_PORT, DECODER_B_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_C_PORT, DECODER_C_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED6-ON\n");
	}
	else
	{
		ATSAME70_PIO_SetOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED6-OFF\n");
	}
	break;
	case LED7 :
	if(EnorDI == ENABLE)
	{
		
		
		ATSAME70_PIO_ClearOutput(DECODER_B_PORT, DECODER_B_PIN);
		ATSAME70_PIO_SetOutput(DECODER_C_PORT, DECODER_C_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_A_PORT, DECODER_A_PIN);
		dbgu_puts("LED7-ON\n");
	}
	else
	{
		ATSAME70_PIO_SetOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED7-OFF\n");
	}
	break;
	case LED8 :
	if(EnorDI == ENABLE)
	{
		
		ATSAME70_PIO_SetOutput(DECODER_A_PORT, DECODER_A_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_B_PORT, DECODER_B_PIN);
		ATSAME70_PIO_SetOutput(DECODER_C_PORT, DECODER_C_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED8-ON\n");
		
	}
	else
	{
		ATSAME70_PIO_SetOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED8-OFF\n");
	}
	break;
	case LED9 :
	if(EnorDI == ENABLE)
	{
		
		ATSAME70_PIO_SetOutput(DECODER_A_PORT, DECODER_A_PIN);
		ATSAME70_PIO_SetOutput(DECODER_B_PORT, DECODER_B_PIN);
		ATSAME70_PIO_SetOutput(DECODER_C_PORT, DECODER_C_PIN);
		ATSAME70_PIO_ClearOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED9-ON\n");
	}
	else
	{
		ATSAME70_PIO_SetOutput(DECODER_NEN_PORT,DECODER_NEN_PIN);
		dbgu_puts("LED9-OFF\n");
	}
	break;
	}
	
	
	if (EnorDI && led_port !=0)
	{
		ATSAME70_PIO_SetOutput(led_port,led_num);
	} 
	else
	{
		ATSAME70_PIO_ClearOutput(led_port,led_num);
	}
	
	
}

//depricated !!!!!
// APIs for enabling specific LEDs
/*
void led0_on (void)
{
	ATSAME70_PIO_SetOutput(LED0_PORT,LED0);
}
void led1_on (void);
{
	ATSAME70_PIO_SetOutput(LED0_PORT,LED0);
}
void led2_on (void);
{
	ATSAME70_PIO_SetOutput(LED0_PORT,LED0);
}
void led3_on (void);
{
	ATSAME70_PIO_SetOutput(LED0_PORT,LED0);
}
void led4_on (void);
{
	ATSAME70_PIO_SetOutput(LED0_PORT,LED0);
}
void led5_on (void);
{
	ATSAME70_PIO_SetOutput(LED0_PORT,LED0);
}
void led6_on (void);
void led7_on (void);
void led8_on (void);
void led9_on (void);
void led10_on (void);
// Off API's for disabling specific LEDs
void led0_off (void);
void led1_off(void);
void led2_off (void);
void led3_off (void);
void led4_off (void);
void led5_off (void);
void led6_off (void);
void led7_off (void);
void led8_off (void);
void led9_off (void);
void led10_off (void);
*/


