#include <byte_ops.h>

uint16_t combine_bytes(uint8_t byte_MSB, uint8_t byte_LSB) {
  uint16_t combined = 0;
  uint16_t uint16_MSB = (uint16_t)(byte_MSB & 0xff) << 8;
  uint16_t uint16_LSB = (uint16_t)byte_LSB & 0xff;
  combined = ( uint16_MSB | uint16_LSB );
  return combined;
}