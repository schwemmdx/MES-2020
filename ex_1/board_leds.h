/*
 * board_leds.h
 *
 * Headerfile for LED API's
 * Author: Sven Prigann
 * eq252
 */ 


#ifndef BOARD_LEDS_H_
#define BOARD_LEDS_H_

#include "sam.h"
#include "device_startup/system_same70.h"
#include "LIB_ATSAME70.h"
#include "board_cortex7.h"
#include "mpu.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//Makro definitions:

#define ENABLE			1
#define DISABLE			0
//Already defined in ´board_cortex_init !!
//LED I/O Pins/
/*
#define LED0_PORT    	 	 ATSAME70_BASE_PIOC
#define LED0		 	 	 PIO_PC19        //pin 117  output
#define LED1_PORT    	 	 ATSAME70_BASE_PIOC
#define LED1		 	 	 PIO_PC10        //pin 90  output
#define LED2_PORT    	 	 ATSAME70_BASE_PIOB
#define LED2		 	 	 PIO_PB5         //pin 109  output TDO Output!!!
*/
//Additional macros for interfacing the GPIO Decoder
#define DECODER_A_PORT		PIOB
#define DECODER_B_PORT		PIOA
#define DECODER_C_PORT		PIOD
#define DECODER_NEN_PORT	PIOC

#define DECODER_A_PIN		PIO_PB2
#define DECODER_B_PIN		PIO_PA31
#define DECODER_C_PIN		PIO_PD27
#define DECODER_NEN_PIN		PIO_PC9 


//LED MAP
//NOTE: first digit is not relevant just for differenciation
#define LED3		10
#define LED4		11
#define LED5		12
#define LED6		13
#define LED7		14
#define LED8		15
#define LED9		16


//API for initialisation of used Pins to talk to decoder 
void decoder_init(void);
// api for enabling or disabling a specific LED with their Pseudonym led0, led1,...

void led_mgr(unsigned long led_num, int EnorDI);



//deprecated: Not used anymore !
// APIs for enabling specific LEDs
/*
void led0_on (void);
void led1_on (void);
void led2_on (void);
void led3_on (void);
void led4_on (void);
void led5_on (void);
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


#endif /* BOARD_LEDS_H_ */