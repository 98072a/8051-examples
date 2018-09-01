#include <stdio.h>
#include <mcs51/8051.h>
#include "defines.h"
#include "ps2x.h"

void putchar(char c)
{
	while(!(SCON & 0x02));
	SCON &= ~0x02;
	SBUF = c;
}

void serial_init(int baudrate)
{
  // configure serial for 8 data bits, 1 stop bit.
	TMOD |= 0x20;
  TMOD &= 0xEF;
	SCON |= 0x40;
  SCON &= 0x7F;
  TH1 = (int)(256 - CRYSTAL_FREQUENCY * 1000 * 1000 / 12 / 32 / baudrate);
  // start the timer1
	TCON |= 0x40;
  // tell putchar() the serial is ready to send
	SCON |= 0x02;
}

void setup()
{
  char data;
  serial_init(9600);

  data = ps2x_write_while_read_data(0x01);
  data = ps2x_write_while_read_data(0x42);

  printf("ID: %x", data);
}

void loop()
{

}

void main(void)
{
  setup();
  while(1) loop();
}
