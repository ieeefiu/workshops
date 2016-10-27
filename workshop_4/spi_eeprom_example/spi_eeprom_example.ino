/* uses the SPIEEPROM library from:
 *  https://github.com/david-beaudette/spieeprom
 */

#include <SPI.h>
#include "spieeprom.h"

byte buffer[256];
long address;

SPIEEPROM disk;

void setup() {
    Serial.begin(9600);

    disk.setup(2);

    char message[10] = "hello\n";
    disk.write(0, (byte *)message, strlen(message));
}

void loop() {
    char data[10];
    disk.read_byte_array(0, (byte *)data, 6);
    Serial.println(data);
    delay(1000);
}
