#include "peripheral.hpp"


void main_lights_task(void *parameters)
{
  int led_pin = *((int*)parameters);

  Serial.printf("Main light on pin %d\n", led_pin);

  pinMode(led_pin, OUTPUT);

  for (;;)
  {
    digitalWrite(led_pin, LOW);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
