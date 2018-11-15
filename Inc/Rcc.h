#ifndef RCC_H_
#define RCC_H_

#include "Common.h"

typedef struct RccRegs RccRegs;
struct RccRegs{
	Io_register CR;					// 0x00
	Io_register PLLCFGR;			// 0x04
	Io_register CFGR;				// 0x08
	Io_register CIR;				// 0x0c
	Io_register AHB1RSTR;			// 0x10
	Io_register AHB2RSTR;			// 0x14
	Io_register AHB3RSTR;			// 0x18
	Io_register Reserved0;			// 0x1c
	Io_register APB1RSTR;			// 0x20
	Io_register APB2RSTR;			// 0x24
	Io_register Reserved1[2];		// 0x28
	Io_register AHB1ENR;			// 0x30
	Io_register AHB2ENR;			// 0x34
	Io_register AHB3ENR;			// 0x38
	Io_register Reserved2;			// 0x3c
	Io_register APB1ENR;			// 0x40
	Io_register APB2ENR;			// 0x44
	Io_register Reserved3[2];		// 0x48
	Io_register AHB1LPENR;			// 0x50
	Io_register AHB2LPENR;			// 0x54
	Io_register AHB3LPENR;			// 0x58
	Io_register Reserved4;			// 0x5c
	Io_register APB1LPENR;			// 0x60
	Io_register APB2LPENR;			// 0x64
	Io_register Reserved5[2];		// 0x68
	Io_register BDCR;				// 0x70
	Io_register CSR;				// 0x74
	Io_register Reserved6[2];		// 0x78
	Io_register SSCGR;				// 0x80
	Io_register PLLI2SCFGR;			// 0x84
};

#define rcc		((RccRegs *)0x40023800)

#define ENABLE_TIMER_2_CLK_GATING()			rcc->APB1ENR |= (1 << 0)
#define ENABLE_TIMER_3_CLK_GATING()			rcc->APB1ENR |= (1 << 1)
#define ENABLE_TIMER_4_CLK_GATING()			rcc->APB1ENR |= (1 << 2)
#define ENABLE_TIMER_5_CLK_GATING()			rcc->APB1ENR |= (1 << 3)

#define DISABLE_TIMER_2_CLK_GATING()		rcc->APB1ENR &= ~(1 << 0)
#define DISABLE_TIMER_3_CLK_GATING()		rcc->APB1ENR &= ~(1 << 1)
#define DISABLE_TIMER_4_CLK_GATING()		rcc->APB1ENR &= ~(1 << 2)
#define DISABLE_TIMER_5_CLK_GATING()		rcc->APB1ENR &= ~(1 << 3)

#define RESET_TIMER_2()						rcc->AHB1RSTR |= (1 << 0)
#define RESET_TIMER_3()						rcc->AHB1RSTR |= (1 << 1)
#define RESET_TIMER_4()						rcc->AHB1RSTR |= (1 << 2)
#define RESET_TIMER_5()						rcc->AHB1RSTR |= (1 << 3)

#define UNRESET_TIMER_2()					rcc->AHB1RSTR &= ~(1 << 0)
#define UNRESET_TIMER_3()					rcc->AHB1RSTR &= ~(1 << 1)
#define UNRESET_TIMER_4()					rcc->AHB1RSTR &= ~(1 << 2)
#define UNRESET_TIMER_5()					rcc->AHB1RSTR &= ~(1 << 3)


#endif /* RCC_H_ */
