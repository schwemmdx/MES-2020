
#include "sdram.h"
#include "board_cortex7.h"

void sdramc_init(void)
{
	//SDRAMC ->SDRAMC_CR &= 0;
	PMC_EnablePeripheral(ID_SDRAMC);
	MATRIX->CCFG_SMCNFCS = CCFG_SMCNFCS_SDRAMEN;
	
	//delayus(1);
	SDRAMC->SDRAMC_CR |= (SDRAM_CR_NC_COL9 << SDRAM_CR_NC)
						|(SDRAM_CR_NR_ROW13 << SDRAM_CR_NR)
						|(SDRAM_CR_CAS_LATENCY_3 << SDRAM_CR_CAS)
						|(SDRAM_CR_NB_BANK4 << SDRAM_CR_NB)
						|(SDRAM_CR_TWR_2 << SDRAM_CR_TWR)
						|(SDRAM_CR_TRC_TRFC_9 << SDRAM_CR_TRC_TRFC)
						|(SDRAM_CR_TRP_3 << SDRAM_CR_TRP)
						|(SDRAM_CR_TRCD_3 << SDRAM_CR_TRCD)
						|(SDRAM_CR_TRAS_7 << SDRAM_CR_TRAS)
						|(SDRAM_CR_TXSR_10 << SDRAM_CR_TXSR) ;
						
	SDRAMC->SDRAMC_MDR |= (SDRAM_MDR_SDRAM << SDRAM_MDR_MD);
	delayus(200);
	sdram_ll_init();
	SDRAMC->SDRAMC_TR = 782;
	SDRAMC->SDRAMC_CFR1 |= SDRAMC_CFR1_UNAL;
	
}

void sdram_ll_init()
{
	volatile uint8_t *pSdram = (uint8_t *) SDRAM_CS_ADDR;
	SDRAMC->SDRAMC_MR = SDRAMC_MR_MODE_NOP;
	*pSdram = 0;
	delayus(1);
	SDRAMC->SDRAMC_MR = SDRAMC_MR_MODE_ALLBANKS_PRECHARGE;
	*pSdram = 0;
	delayus(1);
	for(int i=0;i<8 ;i++)
	{
		SDRAMC->SDRAMC_MR = SDRAMC_MR_MODE_AUTO_REFRESH;
		*pSdram = 0;
		delayus(1);
	}
	SDRAMC->SDRAMC_MR = SDRAMC_MR_MODE_LOAD_MODEREG;
	*pSdram = 0;
	delayus(1);
	SDRAMC->SDRAMC_MR = SDRAMC_MR_MODE_NORMAL;
	*pSdram = 0;
	delayus(1);

}
