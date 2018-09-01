#ifndef __delay_h__
#define __delay_h__

#define __nop()     __asm nop __endasm
#define __nop_2()   __nop();    __nop()
#define __nop_3()   __nop_2();  __nop()
#define __nop_4()   __nop_3();  __nop()
#define __nop_5()   __nop_4();  __nop()
#define __nop_6()   __nop_5();  __nop()
#define __nop_7()   __nop_6();  __nop()
#define __nop_8()   __nop_7();  __nop()
#define __nop_9()   __nop_8();  __nop()
#define __nop_10()  __nop_9();  __nop()

#define __delay(t) do { unsigned int i = t; while(i--); } while(0)


/**
 * ms delay
 * @param t [description]
 */
void delay(unsigned int t);

#endif
