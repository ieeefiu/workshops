#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725();
uint16_t color_data[4];

void print_color_data(uint16_t *data);

void setup() {
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("Sensor initialized");
  }
  else {
    Serial.println("Sensor not found");
    while (1);
  }
}

void loop() {
  tcs.getRawData(&color_data[0], &color_data[1], &color_data[2], &color_data[3]);
  print_color_data(color_data);
  delay(1000);
}

void print_color_data(uint16_t *data) {
  Serial.print("R: ");
  Serial.print(data[0], DEC);
  Serial.print(" ");
  Serial.print("G: ");
  Serial.print(data[1], DEC);
  Serial.print(" ");
  Serial.print("B: ");
  Serial.print(data[2], DEC);
  Serial.print(" ");
  Serial.print("C: ");
  Serial.print(data[3], DEC);
  Serial.println(" ");
}
