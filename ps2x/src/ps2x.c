#include "defines.h"
#include "ps2x.h"

void ps2x_init()
{

}

char ps2x_read_while_write_data(char data)
{

  return 0xFF;
}

char ps2x_write_while_read_data(char command)
{
  char i, received;
  for(i=0; i<8; i++)
  {
    PS2X_COMMAND = (command >> i) & 0x01;
    PS2X_CLOCK = 0;
    received >= 1;
    if(PS2X_DATA) {
      received |= 0x80;
    }
    PS2X_CLOCK = 1;
  }
  PS2X_COMMAND = 1;
  return received;
}
