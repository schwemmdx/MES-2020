/*
** sdram.h
*/

#define BOARD_SDRAM_SIZE  (2*1024*1024)

#define SDRAM_SIZE  0x02000000
#define SDRAM_BASE  0x70000000

//INKONSISTENT !! SDRAM und SRDAMC .... wtf
#define SDRAM_TWR	2   //2*10ns
#define SDRAM_TRC	7	//7*10ns
#define SDRAM_TRP	5	//5*10ns
#define SDRAM_TRCD	2	//2*10ns
#define SDRAM_TRAS	5	//5*10ns
#define SDRAM_TXSR	8	//8*10ns

#define SDRAM_TR	7 * MCK/1000000  // Refresh time [us] * MCK [MHz]

//Macros related to the SRAM Controller configuration
/*BIT POSITIONS in Register CR*/
#define SDRAM_CR_NC				0
#define SDRAM_CR_NR				2
#define SDRAM_CR_NB				4
#define SDRAM_CR_CAS			5
#define SDRAM_CR_DBW			7
#define SDRAM_CR_TWR			8
#define SDRAM_CR_TRC_TRFC		12
#define SDRAM_CR_TRP			16
#define SDRAM_CR_TRCD			20
#define SDRAM_CR_TRAS			24
#define SDRAM_CR_TXSR			28

#define SDRAM_CR_NC_COL8			0
#define SDRAM_CR_NC_COL9			1
#define SDRAM_CR_NC_COL10			2
#define SDRAM_CR_NC_COL11			3
#define SDRAM_CR_NR_ROW11			0
#define SDRAM_CR_NR_ROW12			1
#define SDRAM_CR_NR_ROW13			2
#define SDRAM_CR_NB_BANK2			0
#define SDRAM_CR_NB_BANK4			1
#define SDRAM_CR_CAS_LATENCY_1		1
#define SDRAM_CR_CAS_LATENCY_2		2
#define SDRAM_CR_CAS_LATENCY_3		3
#define SDRAM_CR_DBW_BUS_WIDTH_16	1

//@todo wie genau soll man das dann implementieren? verodern ist dann ja richiger Käse
#define SDRAM_CR_TWR_0			0
#define SDRAM_CR_TWR_1			1
#define SDRAM_CR_TWR_2			2
#define SDRAM_CR_TWR_3			3
#define SDRAM_CR_TWR_4			4
#define SDRAM_CR_TWR_5			5
#define SDRAM_CR_TWR_6			6
#define SDRAM_CR_TWR_7			7
#define SDRAM_CR_TWR_8			8
#define SDRAM_CR_TWR_9			9
#define SDRAM_CR_TWR_10		10
#define SDRAM_CR_TWR_11		11
#define SDRAM_CR_TWR_12		12
#define SDRAM_CR_TWR_13		13
#define SDRAM_CR_TWR_14		14
#define SDRAM_CR_TWR_15		15

//SDRAMC Memory Device Register Bit Positions
#define SDRAM_MDR_MD		0

//SDRAMC Memory Device Register Values
#define SDRAM_MDR_SDRAM		0
#define SDRAM_MDR_LPSDRAM	1

//SDRAM TR_RFC Bit masks (Row Cycle Delay and Row Refresh Cycle)
#define SDRAM_CR_TRC_TRFC_0			0
#define SDRAM_CR_TRC_TRFC_1			1
#define SDRAM_CR_TRC_TRFC_2			2
#define SDRAM_CR_TRC_TRFC_3			3
#define SDRAM_CR_TRC_TRFC_4			4
#define SDRAM_CR_TRC_TRFC_5			5
#define SDRAM_CR_TRC_TRFC_6			6
#define SDRAM_CR_TRC_TRFC_7			7
#define SDRAM_CR_TRC_TRFC_8			8
#define SDRAM_CR_TRC_TRFC_9			9
#define SDRAM_CR_TRC_TRFC_10			10
#define SDRAM_CR_TRC_TRFC_11			11
#define SDRAM_CR_TRC_TRFC_12			12
#define SDRAM_CR_TRC_TRFC_13			13
#define SDRAM_CR_TRC_TRFC_14			14
#define SDRAM_CR_TRC_TRFC_15			15

//Possible Row Precharge Delays
#define SDRAM_CR_TRP_0				0
#define SDRAM_CR_TRP_1				1
#define SDRAM_CR_TRP_2				2
#define SDRAM_CR_TRP_3				3
#define SDRAM_CR_TRP_4				4
#define SDRAM_CR_TRP_5				5
#define SDRAM_CR_TRP_6				6
#define SDRAM_CR_TRP_7				7
#define SDRAM_CR_TRP_8				8
#define SDRAM_CR_TRP_9				9
#define SDRAM_CR_TRP_10			10
#define SDRAM_CR_TRP_11			11
#define SDRAM_CR_TRP_12			12
#define SDRAM_CR_TRP_13			13
#define SDRAM_CR_TRP_14			14
#define SDRAM_CR_TRP_15			15

//Possible TRCD  Row to Column Delays
#define SDRAM_CR_TRCD_0				0
#define SDRAM_CR_TRCD_1				1
#define SDRAM_CR_TRCD_2				2
#define SDRAM_CR_TRCD_3				3
#define SDRAM_CR_TRCD_4				4
#define SDRAM_CR_TRCD_5				5
#define SDRAM_CR_TRCD_6				6
#define SDRAM_CR_TRCD_7				7
#define SDRAM_CR_TRCD_8				8
#define SDRAM_CR_TRCD_9				9
#define SDRAM_CR_TRCD_10				10
#define SDRAM_CR_TRCD_11				11
#define SDRAM_CR_TRCD_12				12
#define SDRAM_CR_TRCD_13				13
#define SDRAM_CR_TRCD_14				14
#define SDRAM_CR_TRCD_15				15

// Possible Active to Precharge Delays
#define SDRAM_CR_TRAS_0				0
#define SDRAM_CR_TRAS_1				1
#define SDRAM_CR_TRAS_2				2
#define SDRAM_CR_TRAS_3				3
#define SDRAM_CR_TRAS_4				4
#define SDRAM_CR_TRAS_5				5
#define SDRAM_CR_TRAS_6				6
#define SDRAM_CR_TRAS_7				7
#define SDRAM_CR_TRAS_8				8
#define SDRAM_CR_TRAS_9				9
#define SDRAM_CR_TRAS_10				10
#define SDRAM_CR_TRAS_11				11
#define SDRAM_CR_TRAS_12				12
#define SDRAM_CR_TRAS_13				13
#define SDRAM_CR_TRAS_14				14
#define SDRAM_CR_TRAS_15				15

//Possible Exit Self-Refresh to Active Delays
#define SDRAM_CR_TXSR_0				0
#define SDRAM_CR_TXSR_1				1
#define SDRAM_CR_TXSR_2				2
#define SDRAM_CR_TXSR_3				3
#define SDRAM_CR_TXSR_4				4
#define SDRAM_CR_TXSR_5				5
#define SDRAM_CR_TXSR_6				6
#define SDRAM_CR_TXSR_7				7
#define SDRAM_CR_TXSR_8				8
#define SDRAM_CR_TXSR_9				9
#define SDRAM_CR_TXSR_10				10
#define SDRAM_CR_TXSR_11				11
#define SDRAM_CR_TXSR_12				12
#define SDRAM_CR_TXSR_13				13
#define SDRAM_CR_TXSR_14				14
#define SDRAM_CR_TXSR_15				15



/*
** prototypes
*/

/*****************************************************************
*@fn	- sdramc_init
*@brief - Initialisiert das SDRAM auf dem MES-Board
*@param - Keine Eingangsparamter
*@return - Kein Rückgabewert
******************************************************************
*/
void sdramc_init(void);
/*****************************************************************
*@fn	- sdramc_ll_init
*@brief - Führt die Grundlegende Abfolge von Modusänderungen für die Initialisieerung durch
*@param - Keine Eingangsparamter
*@return - Kein Rückgabewert
******************************************************************
*/
void sdram_ll_init(void);


