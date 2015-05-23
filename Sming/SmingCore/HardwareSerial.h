/****
 * Sming Framework Project - Open Source framework for high efficiency native ESP8266 development.
 * Created 2015 by Skurydin Alexey
 * http://github.com/anakod/Sming
 * All files of the Sming Core are provided under the LGPL v3 license.
 ****/

#ifndef _HARDWARESERIAL_H_
#define _HARDWARESERIAL_H_

#include "../Wiring/WiringFrameworkDependencies.h"
#include "../Wiring/Stream.h"

#define UART_ID_0   0
#define UART_ID_1   1

/**
 * Implementation of serial hardware.
 *
 * @ingroup SmingCore
 */
class HardwareSerial : public Stream
{
public:
	HardwareSerial(const int uartPort);

	void begin(const uint32_t baud = 9600);

  /**
   * Checks if data is available at uart rx buffer.
   * @return Number of available characters.
   */
	int available();

  /**
   * Reads one byte from uart rx buffer.
   * @return Either character or -1 if no data available.
   */
	int read();

  /**
   * Reads up to defined number of byts from uart rx buffer at once.
   * @param buf Pointer to Buffer where data shall be written to.
   * @param max_len Lenght of Buffer where data shall be written to.
   */
	int readMemoryBlock(char* buf, int max_len);

  /**
   * Reads one byte from uart rx buffer but does not remove it.
   * This means that next read command will return same character again.
   * @return Either character or -1 if no data available.
   */
	int peek();

  /**
   * @note Not yet implemented! Calling this method has no effect.
   */
	void flush();

  /**
   * Write one byte to uart tx buffer.
   * @param oneChar Byte to write.
   * @return Number of written bytes.
   */
	size_t write(uint8_t oneChar);

	//void printf(const char *fmt, ...);
  
  /**
   * Disables or enables debug output of system to be printed.
   * @param enabled Output enabled.
   */
	void systemDebugOutput(bool enabled);

	static void IRAM_ATTR uart0_rx_intr_handler(void *para);

private:
	int uart;
};

extern HardwareSerial Serial;

#endif /* _HARDWARESERIAL_H_ */
