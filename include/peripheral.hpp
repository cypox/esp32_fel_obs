#pragma once

#include <Arduino.h>


typedef struct lights_params {
  int led_pin;
  int on_time=100;
  int off_time=1000;
} lights_params_t;

void main_lights_task(void *);
