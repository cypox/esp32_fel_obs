#pragma once

#include "peripheral.hpp"


void main_lights_task(void *parameters)
{
  (void) parameters;
  int led_pin = *((int*)parameters);

  pinMode(led_pin, OUTPUT);

  for (;;)
  {
    digitalWrite(led_pin, LOW);
    vTaskDelay(100 / portTICK_PERIOD_MS );
    digitalWrite(led_pin, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
