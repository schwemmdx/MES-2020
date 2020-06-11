/*
 * debug_extend.c
 *
 * Created: 07.06.2020 20:29:05
 *  Author: Sven
 */

#include "debug_extend.h"

#define ONE_MEG		1000000

void serial_welcome(void)
{
	dbgu_puts("************************************************\n");
	dbgu_puts("System Up @ (" __DATE__ " " __TIME__ ")\n");
	dbgu_puts("************************************************\n");
}

void print_mcu_spec(void)
{
	printf("f_bus		: %lu MHz\n",(int32_t) BOARD_MCK/ONE_MEG);
	printf("f_cpu		: %lu MHz\n", (int32_t) CPU_CLK/ONE_MEG);
	printf("f_crystal	: %lu MHz\n\n", (int32_t) CRYSTAL_FREQUENCY/ONE_MEG);
}

void print_reg(ulong reg)
{
	char buf[100];
	sprintf(buf,"0x%lx\n",reg);
	dbgu_puts(buf);
}

void print_reg_table(ulong start_addr, uint8_t num_addr)
{
	char buf[100];
	dbgu_puts("  Register   |  Offset  |  Inhalt  \n");
	dbgu_puts("-----------------------------------\n");
	
	for (uint32_t i = 0; i < num_addr;i++)
	{
		sprintf(buf," 0x%lx      +0x%lu       ",(start_addr+i),i);
		dbgu_puts(buf);
		print_reg((ulong*)(start_addr+i));
		
	}
	dbgu_puts("-----------------------------------\n");
	
}
