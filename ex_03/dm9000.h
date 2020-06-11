/*
 * dm9000.h
 *
 * Created: 10.06.2020 10:47:57
 *  Author: Sven
 */ 
#include "sam.h"
#include "stdint.h"

#ifndef DM9000_H_
#define DM9000_H_

#define ETHERNET_DATA_ADDRESS		0x60000004 //adr A2 == CMD!
#define ETHERNET_CMD_ADDRESS		0x60000000

#define ETHERNET_SRAM_CHIP_SELECT 0
#define ET_CSWR_SETUP				1 //setup time for CS, WR: N clock cycles
#define ET_WR_SETUP					1 //setup time for CS, WR: N clock cycles
#define ET_CSWR_PULSE				4 //active time for CS, WR: N clock cycles
#define ET_WR_PULSE					4 //active time for CS, WR: N clock cycles
#define ET_WR_CYCLE					15 //cycle time for CS, WR: N clock cycles
#define ET_CSRD_SETUP				1 //setup time for CS, RD: N clock cycles
#define ET_RD_SETUP					1 //setup time for CS, RD: N clock cycles
#define ET_RD_PULSE					5 //active time for CS, RD: N clock cycles
#define ET_CSRD_PULSE				5 //active time for CS, RD: N clock cycles
#define ET_RD_CYCLE					19 //cycle time for CS, RD: N clock cycles


void dm9000_init(void);
void dm9000_write_reg(uint16_t reg_number, uint16_t data);
uint16_t dm9000_read_reg(uint16_t reg_number);
void dm9000_read_table(unsigned long start_addr,uint32_t num_of_addr );

#endif /* DM9000_H_ */