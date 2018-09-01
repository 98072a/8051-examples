#include "defines.h"
#include "delay.h"
#include "one-wire.h"

__bit one_wire_init()
{
  // reset pulse
  ONE_WIRE_BUS = 0;
  // delay time between 480us and 960us
  __delay(70);
  ONE_WIRE_BUS = 1;
  // delay time between 15us and 60us
  __delay(7);
  // presence pulse duration between 60us and 240us
  return !ONE_WIRE_BUS;
}

void one_wire_write(unsigned char data)
{
  unsigned char i;
  for(i=0; i<8; i++)
  {
    ONE_WIRE_BUS = 0;
    __nop();
    ONE_WIRE_BUS = (data >> i) & 0x01;
    // delay time between 15us and 60us
    __delay(7);
    ONE_WIRE_BUS = 1;
  }
}

unsigned char one_wire_read()
{
  unsigned char i, data = 0x00;
  for(i=0; i<8; i++)
  {
    ONE_WIRE_BUS = 0;
    data >>= 1;
    ONE_WIRE_BUS = 1;
    __delay(7);
    if(ONE_WIRE_BUS) {
      data |= 0x80;
    }
  }
  return data;
}
