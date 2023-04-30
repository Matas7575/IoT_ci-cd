#include "stdint.h"
#include "mh_z19.h"

bool threshold_surpassed();
uint16_t get_threshold();
void set_threshold(uint16_t newThreshold);
uint16_t get_average_co2();
uint16_t get_measurements();
void reset_average_co2();
void co2_initialize();
void take_measuring();
uint16_t get_value();
