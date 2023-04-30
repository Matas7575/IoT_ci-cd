/*
 * SoundImpl.c
 *
 * Created: 4/27/2023 1:18:26 PM
 *  Author: Jagerinho
 */ 

#include "../Headers/Sound.h"

typedef struct sound
{
	uint16_t _sound;
}sound;

sound_t sound_create(){
	sound_t _new_sound = (sound_t)calloc(1,sizeof(sound));
	if (NULL == _new_sound)
		return NULL;
	sen14262_initialise(); 
	return _new_sound;
}

bool get_sound_gate_state()
{
	return sen14262_gate();
}

void sound_destroy(sound_t self)
{
	if (NULL != self)
	free(self);
}

bool soundDetection(sound_t self)
{
	self->_sound = sen14262_envelope();
	if (self->_sound > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}