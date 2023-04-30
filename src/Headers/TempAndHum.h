/*
 * TempAndHum.h
 *
 * Created: 4/12/2023 12:29:07 PM
 *  Author: dragos
 */ 
#include "stdint-gcc.h"
typedef struct tempAndHum* tempAndHum_t;

uint16_t get_average_hum();
void reset_average_hum();
uint16_t get_average_temp();
void reset_average_temp();
tempAndHum_t tempAndHum_create();
void tempAndHum_destroy(tempAndHum_t);
bool wakeup_sensor();
bool measure_temp_hum();
float get_humidity_float();
float get_temperature_float();
uint16_t get_humidity_int();
uint16_t get_temperature_int();