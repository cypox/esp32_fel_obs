#include "rtos_tasks.hpp"


void create_command_task(Command& cmd_server, int stack_size, int priority, int core)
{
  xTaskCreatePinnedToCore(&Command::server_loop, "command_loop_task", stack_size, cmd_server.get_server_address(), priority, NULL, core);
}

void create_lights_task(int* led_pin, int stack_size, int priority, int core)
{
  xTaskCreatePinnedToCore(&main_lights_task, "blinking_lights_task", stack_size, led_pin, priority, NULL, core);
}
