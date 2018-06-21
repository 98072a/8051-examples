#include <stdint.h>
#include "defines.h"
#include "delay.h"

void delay(unsigned int t)
{
  uint32_t i, j;
  for(i=0; i<t; i++)
  {
    for(j=0;j<103;j++);
  }
}

void delay_us(unsigned int t)
{
  t -= 10;
  while(t--) __nop();
}
