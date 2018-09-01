#ifndef __PS2X_H__
#define __PS2X_H__

void ps2x_init();

char ps2x_read_while_write_data(char data);

char ps2x_write_while_read_data(char data);

#endif
