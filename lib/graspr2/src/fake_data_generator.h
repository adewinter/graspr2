#include <stdint.h>
#include <stdlib.h>

#ifndef TARGET_IS_NATIVE
    #include <Arduino.h>
#endif

#ifndef FAKE_DATA_GENERATOR_H
#define FAKE_DATA_GENERATOR_H
    uint16_t generate_fake_value();
    uint16_t get_random_between(uint16_t max_val);
    unsigned long fake_millis();
#endif
