/*
 * Sound.h
 *
 * Created: 4/27/2023 1:15:28 PM
 *  Author: Jagerinho
 */ 

#include "sen14262.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct sound* sound_t;

sound_t sound_create();
void sound_destroy();
bool get_sound_gate_state();
bool soundDetection(sound_t self);