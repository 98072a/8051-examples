#include <string.h>
#include "st7920.h"
#include "defines.h"
#include "delay.h"

void st7920_parallel_8bit_write(unsigned char data, __bit type)
{
  while(!st7920_parallel_8bit_busy_flag());
  ST7920_RS = type;
  ST7920_RW = 0;
  ST7920_EN = 1;
  __nop();
  ST7920_DATA_PORT = data;
  __nop();
  ST7920_EN = 0;
}

void st7920_serial_write(unsigned char data, __bit type)
{
  unsigned char i, temp;
  ST7920_CS = 1;
  if(type)
    temp = 0xFA;
  else
    temp = 0xF8;
  // control byte
  for(i=0; i<8; i++) {
    ST7920_CLK = 0;
    ST7920_SID = (temp << i) & 0x80;
    ST7920_CLK = 1;
  }
  // higher data
  temp = data & 0xF0;
  for(i=0; i<8; i++) {
    ST7920_CLK = 0;
    ST7920_SID = (temp << i) & 0x80;
    ST7920_CLK = 1;
  }
  // lower data
  temp = data << 4;
  for(i=0; i<8; i++) {
    ST7920_CLK = 0;
    ST7920_SID = (temp << i) & 0x80;
    ST7920_CLK = 1;
  }
  ST7920_CS = 0;
}

void st7920_write(unsigned char data, __bit type)
{
  #if defined(ST7920_PARALLEL_MODE)
    return st7920_parallel_8bit_write(data, type);
  #elif defined(ST7920_SERIAL_MODE)
    return st7920_serial_write(data, type);
  #else
    #error define ST7920 data transmission mode first
  #endif
}

__bit st7920_parallel_8bit_busy_flag()
{
  ST7920_DATA_PORT = 0xFF;
  ST7920_RS = 0;
  ST7920_RW = 1;
  ST7920_EN = 1;
  return ST7920_DATA_PORT & 0x80;
}

void st7920_parallel_8bit_clear()
{
  st7920_write(0x01, ST7920_COMMAND);
  delay(10);
}

void st7920_parallel_8bit_init()
{
  // 功能设置
  st7920_write(0x30, ST7920_COMMAND);
  delay(1);
  st7920_write(0x30, ST7920_COMMAND);
  delay(1);
  // 显示开，不显示游标和反白
  st7920_write(0x0C, ST7920_COMMAND);
  delay(1);
  // 清屏
  st7920_write(0x01, ST7920_COMMAND);
  delay(20);
  st7920_write(0x06, ST7920_COMMAND);
}

void st7920_parallel_8bit_print(unsigned char x, unsigned char y, unsigned char * content)
{
  unsigned char i;
  if(y == 1)
  {
    i = 0x80 + x;
  }
  else if(y == 2)
  {
    i = 0x90 + x;
  }
  else if(y == 3)
  {
    i = 0x88 + x;
  }
  else if(y == 4)
  {
    i = 0x98 + x;
  }
  else
  {
    return;
  }
  st7920_write(i, ST7920_COMMAND);
  for(i=0; i<strlen(content); i++)
  {
    st7920_write(content[i], ST7920_DATA);
  }
}
