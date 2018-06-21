#ifndef __delay_h__
#define __delay_h__

#define __nop() __asm nop __endasm

/**
 * ms delay
 * @param t [description]
 */
void delay(unsigned int t);

/**
 * us delay
 * @param t [description]
 */
void delay_us(unsigned int t);

#endif
