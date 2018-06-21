#ifndef __DS18B20_H__
#define __DS18B20_H__

/**
 * This command can save time in a single drop bus system by allowing the bus master to access the
 * memory functions without providing the 64-bit ROM code. If more than one slave is present on the bus
 * and a Read command is issued following the Skip ROM command, data collision will occur on the bus as
 * multiple slaves transmit simultaneously (open drain pulldowns will produce a wired AND result).
 */
#define DS18B20_SKIP_ROM 0xCC

/**
 * This command begins a temperature conversion. No further data is required. The temperature
 * conversion will be performed and then the DS18B20 will remain idle. If the bus master issues read time
 * slots following this command, the DS18B20 will output 0 on the bus as long as it is busy making a
 * temperature conversion; it will return a 1 when the temperature conversion is complete. If parasite-
 * powered, the bus master has to enable a strong pullup for a period greater than t conv immediately after
 * issuing this command.
 */
#define DS18B20_CONVERT_T 0x44

/**
 * This command reads the contents of the scratchpad. Reading will commence at byte 0 and will continue
 * through the scratchpad until the ninth (byte 8, CRC) byte is read. If not all locations are to be read, the
 * master may issue a reset to terminate reading at any time.
 */
#define DS18B20_READ_SCRATCHPAD 0xBE

float ds18b20_get_temperature();

char * ds18b20_get_ids();

float ds18b20_get_temperature_by_id(unsigned char id);

#endif
