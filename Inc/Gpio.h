#ifndef GPIO_H_
#define GPIO_H_

#include "Common.h"

typedef enum{
	GPIO_INPUT = 0,
	GPIO_OUTPUT,
	GPIO_ALT_FUNCTION,
	GPIO_ANALOG,
} GpioMode;

typedef enum{
	GPIO_PUSH_PULL = 0,
	GPIO_OPEN_DRAIN = 1 << 2,
} GpioOutputType;

typedef enum{
	GPIO_LOW_SPEED = 0,
	GPIO_MED_SPEED = 1 << 3,
	GPIO_HI_SPEED = 2 << 3,
	GPIO_VERY_HI_SPEED = 3 << 3,
} GpioOutputSpeed;

typedef enum{
	GPIO_NO_PULL = 0,
	GPIO_PULL_UP = 1 << 5,
	GPIO_PULL_DOWN = 2 << 5,
} GpioPullType;

typedef enum{
	GpioPin0 = 0x1,
	GpioPin1 = 0x2,
	GpioPin2 = 0x4,
	GpioPin3 = 0x8,
	GpioPin4 = 0x10,
	GpioPin5 = 0x20,
	GpioPin6 = 0x40,
	GpioPin7 = 0x80,
	GpioPin8 = 0x100,
	GpioPin9 = 0x200,
	GpioPin10 = 0x400,
	GpioPin11 = 0x800,
	GpioPin12 = 0x1000,
	GpioPin13 = 0x2000,
	GpioPin14 = 0x4000,
	GpioPin15 = 0x8000,
} GpioPin;

typedef struct GpioRegs GpioRegs;
struct GpioRegs{
	Io_register mode;
	Io_register driverType;
	Io_register outSpeed;
	Io_register pullType;
	Io_register inData;
	Io_register outData;
	Io_register outBits;
	Io_register pinLock;
	Io_register altFuncLow;
	Io_register altFuncHi;
};

#define gpioA ((GpioRegs *) 0x40020000)
#define gpioB ((GpioRegs *) 0x40020400)
#define gpioC ((GpioRegs *) 0x40020800)
#define gpioD ((GpioRegs *) 0x40020c00)
#define gpioE ((GpioRegs *) 0x40021000)
#define gpioF ((GpioRegs *) 0x40021400)
#define gpioG ((GpioRegs *) 0x40021800)
#define gpioH ((GpioRegs *) 0x40021c00)
#define gpioI ((GpioRegs *) 0x40022000)
#define gpioJ ((GpioRegs *) 0x40022400)
#define gpioK ((GpioRegs *) 0x40022800)

#define writeRegisterBits(regRef, dataBits, dataLength, bitPos)



#endif /* GPIO_H_ */
