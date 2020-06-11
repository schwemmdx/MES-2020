#ifndef DEBUG_EXTEND_H_
#define DEBUG_EXTEND_H_

#include "stdlib.h"
#include "sam.h"
#include "device_startup/system_same70.h"
#include "LIB_ATSAME70.h"
#include "board_cortex7.h"
#include "mpu.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


void serial_welcome(void);
void print_reg(ulong reg);
void print_reg_table(ulong start_addr, uint8_t num_addr);
void penrose(void);
void print_mcu_spec(void);

#endif 