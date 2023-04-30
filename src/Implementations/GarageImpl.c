/*
 * GarageImpl.c
 *
 * Created: 4/12/2023 11:49:23 AM
 *  Author: drago
 */ 
#include <stdlib.h>
#include "Garage.h"

typedef struct garage
{
	int garageSpots;
	int numberOfCarsInTheGarage;		
}garage;

garage_t garage_create(int garageSpots)
{
	garage_t _new_garage = (garage_t)calloc(1, sizeof(garage));
	if(NULL == _new_garage)
		return NULL;
		
	_new_garage->garageSpots = garageSpots;
	_new_garage->numberOfCarsInTheGarage = 0;
	
	return _new_garage;
}

void garage_destroy(garage_t self) 
{
	if (NULL != self)
		free(self);
}

bool add_car(garage_t self)
{
	if(NULL == self)
		return false;
	if(self->numberOfCarsInTheGarage >= self->garageSpots)
		return false;
	self->numberOfCarsInTheGarage++;
	return true; 
}

bool add_car(garage_t self)
{
	if(NULL == self)
	return false;
	if(self->numberOfCarsInTheGarage == 0)
	return false;
	self->numberOfCarsInTheGarage--;
	return true;
}

int get_number_of_cars(garage_t self)
{
	if(NULL == self)
		return 0;
	return self->numberOfCarsInTheGarage;
}