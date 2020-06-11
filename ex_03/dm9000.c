/*
 * dm9000.c
 * 
 * Created: 10.06.2020 10:47:27
 *  Author: Sven
 */ 
#include "dm9000.h"
#include "sam.h"
#include "mpu.h"
#include "board_cortex7.h"
#include "dbgu.h"
#include "debug_extend.h"

void dm9000_init(void)
{
	PMC_EnablePeripheral(ID_SMC);
	MPU_Configure();
	SMC->SMC_CS_NUMBER[ETHERNET_SRAM_CHIP_SELECT].SMC_SETUP = SMC_SETUP_NWE_SETUP(ET_WR_SETUP)
	| SMC_SETUP_NCS_WR_SETUP(ET_CSWR_SETUP)
	| SMC_SETUP_NRD_SETUP(ET_RD_SETUP)
	| SMC_SETUP_NCS_RD_SETUP(ET_CSRD_SETUP);
	SMC->SMC_CS_NUMBER[ETHERNET_SRAM_CHIP_SELECT].SMC_PULSE = SMC_PULSE_NWE_PULSE(ET_WR_PULSE)
	| SMC_PULSE_NCS_WR_PULSE(ET_CSWR_PULSE)
	| SMC_PULSE_NRD_PULSE(ET_RD_PULSE)
	| SMC_PULSE_NCS_RD_PULSE(ET_CSRD_PULSE);
	SMC->SMC_CS_NUMBER[ETHERNET_SRAM_CHIP_SELECT].SMC_CYCLE = SMC_CYCLE_NWE_CYCLE(ET_WR_CYCLE)
	| SMC_CYCLE_NRD_CYCLE(ET_RD_CYCLE);
	SMC->SMC_CS_NUMBER[ETHERNET_SRAM_CHIP_SELECT].SMC_MODE = (SMC_MODE_DBW_Msk &
	SMC_MODE_DBW_16_BIT);
	SMC->SMC_OCMS = 0;
	
}

uint16_t dm9000_read_reg(uint16_t reg_number)
{
	asm volatile ("DMB");
	*(volatile uint16_t*)ETHERNET_CMD_ADDRESS = reg_number;
	asm volatile ("DMB");
	return *(volatile uint16_t*)ETHERNET_DATA_ADDRESS;
}

void dm9000_read_table(ulong start_addr,uint32_t num_of_addr )
{
	uint16_t test_data;
	char buf[100];
	dbgu_puts("DM9000's internal registers:\n");
	dbgu_puts("-----------------------------------\n");
	dbgu_puts("  Register   |  Offset  |  Value  \n");
	dbgu_puts("-----------------------------------\n");
	
	for (uint32_t i = 0; i<=num_of_addr;i++)
	{
		test_data= dm9000_read_reg((start_addr+i));
		if (i< 10)
		{
			sprintf(buf," 0x%lx      +%lu       ",(start_addr+i),i);
		}
		else if ((i<100) && (i>=10))
		{
			sprintf(buf," 0x%lx      +%lu      ",(start_addr+i),i);
		}
		//TODO: Implementierung für vierstellige Offsets ?
		else if ((i>=100) && (i<1000))
		{
			sprintf(buf," 0x%lx      +%lu     ",(start_addr+i),i);
		}
		dbgu_puts(buf);
		print_reg((ulong)test_data);
		
	}
	dbgu_puts("-----------------------------------\n");
}