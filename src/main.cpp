#include <Arduino.h>
#include <SPI.h>
#include <byte_ops.h>
#include <fake_data_generator.h>

#ifdef DEBUG
 #define DEBUG_PRINT(fmt, ...)  printf(fmt, ##__VA_ARGS__)
#else
 #define DEBUG_PRINT(x)
#endif

#define DEBUG

#define SEND_FAKE_DATA //for when the teensy isn't hooeked up to anything but we still want to test the client

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

/*
  The teensy disregards this value and transmits at full bandwith 
  (12 or 480 mbit/s depending on usb connection). We use 12000000,
  which is equivalent to 12 mbit/s, just in case this value is required on the PC end (windows serial is weird)
  (and this value probably doesn't mean anything).
  More info here: https://www.pjrc.com/teensy/td_serial.html
*/
#define SERIAL_BAUD 12000000

void setup_adc_spi() {
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
  SPI.begin();
}

void setup_adc() {
  pinMode(ADC_DIN, OUTPUT);
  digitalWrite(ADC_DIN, HIGH); //leave high per `Notes.md`
}

uint8_t most_sig_bit = 0;
uint8_t least_sig_bit = 0;

uint16_t read_adc() {
  most_sig_bit = 0;
  least_sig_bit = 0;

  SPI.beginTransaction(ADCSPISettings);
  digitalWrite(CS, LOW); //set chip select low to begin clocking out data from ADC;
  most_sig_bit = SPI.transfer(0);
  least_sig_bit = SPI.transfer(0);
  digitalWrite(CS, HIGH);
  SPI.endTransaction();

  return combine_bytes(most_sig_bit, least_sig_bit);
}

void write_value_to_serial(uint16_t value_to_send) {
  Serial.println(value_to_send, DEC);
}

void read_adc_and_write_to_serial() {
  uint16_t sensor_value = read_adc();
  write_value_to_serial(sensor_value);
}

void what() {
  float t = (float)(millis()/1000.0);
  float s = (sin(t) + 1.0)/2;
  float r = get_random_between(16);

  char buff[50];
  sprintf(buff, "time: %f, sine: %f, random: %f", t, s, r);
  Serial.println(buff);

}


void generate_fake_data_and_write_to_serial() {
  uint16_t fake_value = generate_fake_value();
  write_value_to_serial(fake_value);
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  setup_adc();
  setup_adc_spi();
}

void loop() {
  #ifdef SEND_FAKE_DATA
    generate_fake_data_and_write_to_serial();
    // what();
  #else
    read_adc_and_write_to_serial();
  #endif
}