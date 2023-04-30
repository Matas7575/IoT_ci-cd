/*
 * Light.h
 *
 * Created: 4/13/2023 1:19:34 PM
 *  Author: drago
 */ 
#include "stdint-gcc.h"
#include "tsl2591.h"

typedef struct light* light_t;

uint16_t get_average_light();
void reset_average_light();
light_t light_create();
void light_destroy(light_t);
bool power_up_sensor();
bool power_down_sensor();
void get_light_data(light_t self);
uint16_t get_tmp(light_t);
float get_lux(light_t);