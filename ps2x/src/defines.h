#include <mcs51/8051.h>

#ifndef __DEFINES_H__
#define __DEFINES_H__

#define __nop() __asm nop __endasm

// 晶震频率
#define CRYSTAL_FREQUENCY 11.0592

#define PS2X_DATA         P0_0
#define PS2X_COMMAND      P0_1
#define PS2X_CLOCK        P2_0
#define PS2X_ENABLE       P2_1

#endif
