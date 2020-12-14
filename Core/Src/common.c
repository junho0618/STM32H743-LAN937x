/*************************************************************
* NOTE : common.c
*      bootloader, application ... common function define
* Author : Lee junho
* Since : 2020.03.16
**************************************************************/
#include "main.h"
#include "usart.h"
#include "adc.h"

#include "common.h"

/*----------------------------------------------------------------------
 *   Defines
 *--------------------------------------------------------------------*/
#ifdef __GNUC__
	#define PUTCHAR_PROTOTYPE int __io_putchar( int ch )
#else
	#define PUTCHAR_PROTOTYPE int fputc( int ch, FILE *f )
#endif

/*----------------------------------------------------------------------
 *   Functions declaration
 *--------------------------------------------------------------------*/
u8		getBoardID( void );
void	jumpToBootloader( void );
void	jumpToBootloaderReset( uint32_t mscnt );
void	printCLKs( void );
u32		readBatteryValue( void );

/*----------------------------------------------------------------------
 *   Variables
 *--------------------------------------------------------------------*/
uint8_t		gDBGFlag	= 0xFF;

/*----------------------------------------------------------------------
 *   Functions
 *--------------------------------------------------------------------*/
#if 0
void HAL_Delay( uint32_t milliseconds )
{
	/* Initially clear flag */
	(void)SysTick->CTRL;

	while( milliseconds != 0 )
	{
		/* COUNTFLAG returns 1 if timer counted to 0 since the last flag read */
		milliseconds -= (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) >> SysTick_CTRL_COUNTFLAG_Pos;
	}
}
#endif

#if( USE_DWT_DELAY )
uint32_t DWT_Delay_Init( void )
{
	/* Disable TRC */
	CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk;	// ~0x01000000;

	/* Enable TRC */
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;		// 0x01000000;

	/* Disable clock cycle counter */
	DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;				// ~0x00000001;

	/* Enable clock cycle counter */
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;				// 0x00000001;

	/* Reset the clock cycle counter value */
	DWT->CYCCNT = 0;

	/* 3 NO OPERATION instructions */
	asm( "NOP" );
	asm( "NOP" );
	asm( "NOP" );

	/* Check if clock cycle counter has started */
	if(DWT->CYCCNT)			return 0;					/*clock cycle counter started*/
	else					return 1;					/*clock cycle counter not started*/
}

/**
 * @brief This function provides a delay (in microseconds)
 * @param microseconds: delay in microseconds
 */
void DWT_Delay_us( volatile uint32_t microseconds )
{
	uint32_t clk_cycle_start = DWT->CYCCNT;
	uint32_t delay;

	/* Go to number of cycles for system */
	delay = microseconds * (HAL_RCC_GetSysClockFreq() / 1000000);

	/* Delay till end */
	while((DWT->CYCCNT - clk_cycle_start) < delay);
}

void DWT_Delay_ms( volatile uint32_t miliseconds )
{
	DWT_Delay_us( miliseconds * 1000 );
}
#endif	// USE_DWT_DELAY

/*---------------------------------------------------------------------------------------------
	Print
---------------------------------------------------------------------------------------------*/
PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit( &PRINTF_UART_PORT, (uint8_t *)&ch, 1, 0xFFFF );

	return ch;
}

/*---------------------------------------------------------------------------------------------
	Common Function
---------------------------------------------------------------------------------------------*/
u8 getBoardID( void )
{
	u8	ucBoardID = 0;

#if( USE_BOARD_ID1 )
	ucBoardID  = HAL_GPIO_ReadPin( BD_ID1_GPIO_Port, BD_ID1_Pin ) << 1;
#endif
	ucBoardID += HAL_GPIO_ReadPin( BD_ID0_GPIO_Port, BD_ID0_Pin );

	switch( ucBoardID )
	{
		case 3 :			GLogI( "Board ID : 0x11\r\n" );			break;
		case 2 :			GLogI( "Board ID : 0x10\r\n" );			break;
		case 1 :			GLogI( "Board ID : 0x01\r\n" );			break;
		case 0 :
		default :			GLogI( "Board ID : 0x00\r\n" );			break;
	}

	return ucBoardID;
}

void printCLKs( void )
{
#ifdef STM32H743xx	
	PLL1_ClocksTypeDef PLL1_Clocks;
	PLL2_ClocksTypeDef PLL2_Clocks;
	int ck = SDMMC1->CLKCR & 0x3FF;

	GLogI( "==================================================\r\n" );
	GLogI( "CORE      = %9d, %6.2lf MHz\r\n", SystemCoreClock, (double)SystemCoreClock*1e-6 );
	GLogI( "HCLK      = %9d\r\n", HAL_RCC_GetHCLKFreq() );
	GLogI( "APB1      = %9d\r\n", HAL_RCC_GetPCLK1Freq() );
	GLogI( "APB2      = %9d\r\n", HAL_RCC_GetPCLK2Freq() );

	HAL_RCCEx_GetPLL1ClockFreq(&PLL1_Clocks);
	GLogI( "PLL1_Q_CK = %9d, %6.2lf MHz\r\n", PLL1_Clocks.PLL1_Q_Frequency, (double)PLL1_Clocks.PLL1_Q_Frequency*1e-6 );

	HAL_RCCEx_GetPLL2ClockFreq(&PLL2_Clocks);
	GLogI( "PLL2_R_CK = %9d, %6.2lf MHz\r\n", PLL2_Clocks.PLL2_R_Frequency, (double)PLL2_Clocks.PLL2_R_Frequency*1e-6 );

#if 1		// sdmmc clock use PLL1Q
	HAL_RCCEx_GetPLL1ClockFreq(&PLL1_Clocks);
	GLogI( "SDMMC_CK  = %9d, %6.2lf MHz\r\n", ck, ((double)PLL1_Clocks.PLL1_Q_Frequency * 1e-6) / (double)(2.0 * ck) );
#else		// sdmmc clock use PLL2R
	HAL_RCCEx_GetPLL1ClockFreq(&PLL2_Clocks);
	GLogI( "SDMMC_CK  = %9d, %6.2lf MHz\r\n", ck, ((double)PLL2_Clocks.PLL2_R_Frequency * 1e-6) / (double)(2.0 * ck) );
#endif
	GLogI( "==================================================\r\n" );
#endif	// STM32H743xx

#ifdef STM32F427xx
	GLogI( "==================================================\r\n" );
	GLogI( "CORE      = %9d, %6.2lf MHz\r\n", SystemCoreClock, (double)SystemCoreClock*1e-6 );
	GLogI( "HCLK      = %9d, %6.2lf MHz\r\n", HAL_RCC_GetHCLKFreq(), (double)HAL_RCC_GetHCLKFreq()*1e-6 );
	GLogI( "APB1      = %9d, %6.2lf MHz\r\n", HAL_RCC_GetPCLK1Freq(), (double)HAL_RCC_GetPCLK1Freq()*1e-6 );
	GLogI( "APB2      = %9d, %6.2lf MHz\r\n", HAL_RCC_GetPCLK2Freq(), (double)HAL_RCC_GetPCLK2Freq()*1e-6 );
	GLogI( "==================================================\r\n" );
#endif	// STM32F427xx	
}