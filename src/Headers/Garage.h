/*
 * Garage.h
 *
 * Created: 4/12/2023 11:24:34 AM
 *  Author: drago
 */ 
typedef struct garage* garage_t;

garage_t garage_create(int garageSpots);
void garage_destroy(garage_t);
bool add_car(garage_t);
bool remove_car(garage_t);
int get_number_of_cars(garage_t);