#include <fake_data_generator.h>
#include <math.h>

#ifdef TARGET_IS_NATIVE
    #define millis() fake_millis()
    #include <sys/time.h>
#endif

#define MAX_VALUE 65536 //2^16

#ifdef TARGET_IS_NATIVE
    struct timespec spec;
    long            ms; // Milliseconds
    unsigned long fake_millis() {
        clock_gettime(CLOCK_REALTIME, &spec);
        ms = round(spec.tv_nsec / 1.0e6);
        return spec.tv_nsec / 1000;
    }
#endif

/*
    Get a random number between 0 and `max_val`
*/
uint16_t get_random_between(uint16_t max_val) {
    
    float squashed_big_random = ((float)rand())/(RAND_MAX * 1.0);
    float final_rand_as_float = ((float)max_val) * squashed_big_random;
    return final_rand_as_float;
}

uint16_t generate_fake_value() {
    long noise;
    unsigned long elapsed_time_ms;
    float elapsed_time_sec;
    float sin_value;
    uint16_t fake_value;
    
    noise = get_random_between(16); //Simulate 4 bits of noise
    noise -= 8; //'shift' the value by 8 so it can be positive or negative.
    elapsed_time_ms = millis();
    elapsed_time_sec = (float)(elapsed_time_ms/1000.0);

    sin_value = (sin(elapsed_time_sec) + 1.0)/2; //transform so value is in range [0.0, 1.0]
    fake_value = (sin_value * MAX_VALUE) + noise; //transform so range is [0.0, MAX_VALUE] and add 'noise';
    
    return fake_value;
}