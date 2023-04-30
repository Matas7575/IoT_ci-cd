/*
 * MotionSensor.h
 *
 * Created: 4/14/2023 9:54:14 PM
 *  Author: drago
 */ 
typedef struct motion* motion_t;

motion_t motion_create();
void motion_destroy(motion_t self);
bool detecting(motion_t self);