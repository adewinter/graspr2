#include <unistd.h>
#include <ArduinoFake.h>
#include <byte_ops.h>
#include <fake_data_generator.h>
#include <unity.h>

void test_basic_combine_bytes() {
    uint16_t combined = 0;
    uint8_t msb = 0x01;
    uint8_t lsb = 0x01;
    combined = combine_bytes(msb, lsb);
    TEST_ASSERT_EQUAL(0b0000000100000001, combined); //257
}

void test_basic_combine_bytes_only_msb() {
    uint16_t combined = 0;
    uint8_t msb = 0x11;
    uint8_t lsb = 0x00;
    combined = combine_bytes(msb, lsb);
    TEST_ASSERT_EQUAL(0b0001000100000000, combined); //4352
}

void test_basic_combine_bytes_only_lsb() {
    uint16_t combined = 0;
    uint8_t msb = 0x00;
    uint8_t lsb = 0x01;
    combined = combine_bytes(msb, lsb);
    TEST_ASSERT_EQUAL(0b0000000000000001, combined); // ... 1
}

void test_get_random_between() {
    srand(4321); //use the same starting seed every time for testing.

    TEST_ASSERT_EQUAL(6, get_random_between(16));
    TEST_ASSERT_EQUAL(9, get_random_between(16));
    TEST_ASSERT_EQUAL(5, get_random_between(16));
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_basic_combine_bytes);
    RUN_TEST(test_basic_combine_bytes_only_msb);
    RUN_TEST(test_basic_combine_bytes_only_lsb);
    RUN_TEST(test_get_random_between);
    UNITY_END();

    return 0;
}