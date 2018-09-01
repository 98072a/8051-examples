#include "delay.h"
#include "one-wire.h"
#include "ds18b20.h"


float ds18b20_get_temperature()
{
  float temperature;
  unsigned char lsb, msb;
  one_wire_init();
  one_wire_write(DS18B20_SKIP_ROM);
  one_wire_write(DS18B20_CONVERT_T);
  // wait for convert
  __delay(300);
  one_wire_init();
  one_wire_write(DS18B20_SKIP_ROM);
  one_wire_write(DS18B20_READ_SCRATCHPAD);
  lsb = one_wire_read();
  msb = one_wire_read();

  temperature = ((msb & 0x7F) << 4) + (lsb >> 4);
  temperature += (lsb & 0xF0) * 0.0625;

  if(msb & 0x80) temperature = -temperature;
  return temperature;
}
