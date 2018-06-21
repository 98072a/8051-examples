#ifndef __ONE_WIRE_H__
#define __ONE_WIRE_H__

/**
 * reset and presence pulses
 * @return 1 for success and 0 for fail
 */
__bit one_wire_reset();

/**
 * one wire write function, LSB
 * @param data data
 */
void one_wire_write(unsigned char data);

/**
 * one wire read function, LSB
 * @return data
 */
unsigned char one_wire_read();

#endif
