#ifndef __TIMER_H_
#define __TIMER_H_

#include "Common.h"

typedef struct TimRegs TimRegs;
struct TimRegs{
	Io_register control1;					// 0x00
	Io_register control2;					// 0x04
	Io_register slaveModeControl;			// 0x08
	Io_register interruptEnable;			// 0x0c
	Io_register status;						// 0x10
	Io_register eventGeneration;			// 0x14
	Io_register compareOrCaptureMode1;		// 0x18
	Io_register compareOrCaptureMode2;		// 0x1c
	Io_register compareOrCaptureEnable;		// 0x20
	Io_register counter;					// 0x24
	Io_register prescaler;					// 0x28
	Io_register autoReload;					// 0x2c
	Io_register reserved0;					// 0x30
	Io_register compareOrCapture1;			// 0x34
	Io_register compareOrCapture2;			// 0x38
	Io_register compareOrCapture3;			// 0x3c
	Io_register compareOrCapture4;			// 0x40
	Io_register reserved1;					// 0x44
	Io_register DMAcontrol;					// 0x48
	Io_register DMAadsress;					// 0x4c
	Io_register option;						// 0x50
};

#define timer2	((TimRegs *) 0x40000000)
#define timer3	((TimRegs *) 0x40000400)
#define timer4	((TimRegs *) 0x40000800)
#define timer5	((TimRegs *) 0x40000c00)

#define TIM_CEN			1

//status
#define TIM_UIF			(1 << 0)
#define TIM_CC1IF		(1 << 1)
#define TIM_CC2IF		(1 << 2)
#define TIM_CC3IF		(1 << 3)
#define TIM_CC4IF		(1 << 4)
#define TIM_TIF			(1 << 6)
#define TIM_CC1OF		(1 << 9)
#define TIM_CC2OF		(1 << 10)
#define TIM_CC3OF		(1 << 11)
#define TIM_CC4OF		(1 << 12)

// DIER
#define dmaInterruptEnable		1

// CCMR: Compare Mode
#define OC_FROZEN				0
#define OC_ACTIV_ON_MATCH		1
#define OC_INACTIV_ON_MATCH		2
#define OC_TOGGLE				3
#define OC_FORCE_ACTIV			4
#define OC_FORCE_INACTIV		5
#define OC_PWM1					6
#define OC_PWM2					7
// (bit 3)
#define OC_PRELOAD_EN			1
// Compare capture 1/3 selection (bit 1:0)
#define CC_SELECT_OC			0
#define CC_SELECT_IC_DIRECT		1
#define CC_SELECT_IC_INDIRECT	2
#define CC_SELECT_IC_TRC		3

//CCER
#define OC_NORMAL_POLARITY		0
#define OC_INVERSE_POLARITY		1

// EGR
#define TIM_UG			1

// Timer Macros
#define TIM_SET_COUNTER(tim, value)			(tim)->counter = (value)
#define TIM_SET_OC_VALUE(tim, ch, value)	*(&((tim)->compareOrCapture1) + (ch) - 1) = (value)
#define TIM_SET_OC_POLARITY(tim, ch, polarity)											\
			do{																			\
				(tim)->compareOrCaptureEnable &= ~(2 << (((ch) - 1) * 4));				\
				(tim)->compareOrCaptureEnable |= polarity << ((((ch) - 1) * 4) + 1);	\
			}while(0)
#define TIM_CAPTURE_COMPARE_EN(tim, ch)			(tim)->compareOrCaptureEnable |= 1 << (((ch) - 1) * 4)
#define TIM_CAPTURE_COMPARE_DIS(tim, ch)		(tim)->compareOrCaptureEnable &= ~(1 << (((ch) - 1) * 4))

// Clear SR register of Timer. whichFlag should be one of the following:
// TIM_UIF			Update interrupt flag
// TIM_CC1IF		Capture/compare 1 interrupt flag
// TIM_CC2IF		Capture/compare 2 interrupt flag
// TIM_CC3IF		Capture/compare 3 interrupt flag
// TIM_CC4IF		Capture/compare 4 interrupt flag
// TIM_TIF			Trigger interrupt flag
// TIM_CC1OF		Capture/compare 1 overcapture flag
// TIM_CC2OF		Capture/compare 2 overcapture flag
// TIM_CC3OF		Capture/compare 3 overcapture flag
// TIM_CC4OF		Capture/compare 4 overcapture flag
#define TIM_CLEAR_FLAG(tim, whichFlag)	(tim)->status = ~(whichFlag)
#define TIM_GET_FLAG(tim, whichFlag)	(tim)->status & (whichFlag)

#define TIM_COUNTER_ENABLE(tim) 		(tim)->control1 |= TIM_CEN
#define TIM_COUNTER_DISABLE(tim) 		(tim)->control1 &= ~TIM_CEN

#define TIME_UPDATE_GEN					(tim)->eventGeneration |= TIM_UG

void timerInitOutputCompare(TimRegs *tim, int channel, int mode, int outPolarity, int compareValue);
void timerOcSetMode(TimRegs *tim, int channel, int mode);

#endif /* TIMER_H_ */
