/*
 * MotionSensorImpl.c
 *
 * Created: 4/16/2023 1:09:27 PM
 *  Author: drago
 */ 
#include "hcSr501.h"
#include "../Headers/MotionSensor.h"
#include <stdlib.h>
#include <avr/io.h>

typedef struct motion
{
	hcsr501_p hcsr501Inst;
}motion;

motion_t motion_create()
{
	motion_t _new_motion = (motion_t)calloc(1,sizeof(motion));
	if (NULL == _new_motion)
	return NULL;
	_new_motion->hcsr501Inst = NULL;
	_new_motion->hcsr501Inst = hcsr501_create(&PORTE, PE5);
	if ( NULL == _new_motion->hcsr501Inst )
		return NULL;
	return _new_motion;
}

void motion_destroy(motion_t self)
{
	if (NULL != self)
	free(self);
}

bool detecting(motion_t self)
{
	if ( hcsr501_isDetecting(self->hcsr501Inst) )
	{
		return true;
	}
	else
	{
		return false;
	}
}