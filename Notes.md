Notes


SPI Mode for ADS8866
====================
Based on the timing diagram it looks like CPOL=0 and CPHA=0

Wiring/Pins
===========
Graspr_1:DIN <-> Teensy_11:MOSI0
Graspr_2:SCLK <-> Teensy_13:SCK0
Graspr_3:DOUT <-> Teensy_12:MISO0
Graspr_4:CONVST <-> Teensy_10:CS0

SPI Operation
=============
We will use CONVST as "chip select" (it's possible to use DIN as chip select, primarily when using the daisy-chain mode of the adc).

Set DIN to HIGH and leave it there.
Set CONVST to HIGH then pull LOW when ready to clock data out (MISO).
Read 16-bits on MISO.  MSB format.

Dat's pmuch it!