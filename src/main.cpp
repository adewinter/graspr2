#include <Arduino.h>
#include <SPI.h>
#include <byte_ops.h>

#ifdef DEBUG
 #define DEBUG_PRINT(fmt, ...)  printf(fmt, ##__VA_ARGS__)
#else
 #define DEBUG_PRINT(x)
#endif

#define DEBUG



/* PIN DEFS  
  Graspr_1:DIN <-> Teensy_9:GPIO
  Graspr_2:SCLK <-> Teensy_13:SCK0
  Graspr_3:DOUT <-> Teensy_12:MISO0
  Graspr_4:CONVST <-> Teensy_10:CS0
*/
#define CS 10
#define MISO 12
#define ADC_DIN 9
#define SCK 13

/* Settings/Constants */
#define SPI_FREQ 16000000 //16 mhz is "typical" for the ADS8866 ADC according to the datasheet.
SPISettings ADCSPISettings(SPI_FREQ, MSBFIRST, SPI_MODE0);

void setup_adc_spi() {
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
  SPI.begin();
}

void setup_adc() {
  pinMode(ADC_DIN, OUTPUT);
  digitalWrite(ADC_DIN, HIGH); //leave high per `Notes.md`
}

void setup() {
  setup_adc();
  setup_adc_spi();
}

void loop() {
  // put your main code here, to run repeatedly:
}