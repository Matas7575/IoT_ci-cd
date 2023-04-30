/*
 * TempAndHumImpl.c
 *
 * Created: 4/12/2023 12:45:41 PM
 *  Author: drago
 */ 
#include "hih8120.h"
#include "../Headers/TempAndHum.h"
#include <stdlib.h>
#include "../Headers/Average.h"

typedef struct tempAndHum
{
}tempAndHum;

Average average_hum = {0,0};
Average average_temp = {0,0};
	
void update_average_hum(){
	average_hum.measurements += 1;
	uint16_t newVal = hih8120_getHumidityPercent_x10();
	average_hum.current_average = (uint16_t)(float)((average_hum.current_average * (average_hum.measurements-1)) + newVal) / average_hum.measurements;
}

void update_average_temp(){
	average_temp.measurements += 1;
	uint16_t newVal = hih8120_getTemperature_x10();
	average_temp.current_average = (uint16_t)(float)((average_temp.current_average) * (average_temp.measurements-1) + newVal) / average_temp.measurements;
}

uint16_t get_average_temp(){
	return average_temp.current_average;
}

uint16_t get_average_hum(){
	return average_hum.current_average;
}

void reset_average_temp(){
	average_temp.measurements = 0;
	average_temp.current_average = 0;
}

void reset_average_hum(){
	average_hum.measurements = 0;
	average_hum.current_average = 0;
}

tempAndHum_t tempAndHum_create()
{
	tempAndHum_t _new_tempAndHum = (tempAndHum_t)calloc(1,sizeof(tempAndHum));
	if (NULL == _new_tempAndHum)
		return NULL;
	if (HIH8120_OK != hih8120_initialise())
		return NULL;
	return _new_tempAndHum;
}

void tempAndHum_destroy(tempAndHum_t self)
{
	if (NULL != self)
	free(self);
}

bool wakeup_sensor()
{
	if ( HIH8120_OK != hih8120_wakeup() )
	{
		return false;
	}
	return true;
}

bool measure_temp_hum()
{
	if ( HIH8120_OK !=  hih8120_measure() )
	{
		
		return false;
	}
	update_average_temp();
	update_average_hum();
	return true;
}

float get_humidity_float()
{
	return hih8120_getHumidity();
}
float get_temperature_float()
{
	return hih8120_getTemperature();
}
uint16_t get_humidity_int()
{
	return hih8120_getHumidityPercent_x10();
}
uint16_t get_temperature_int()
{
	return hih8120_getTemperature_x10();
}