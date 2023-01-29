#pragma once

#include "command.hpp"
#include "peripheral.hpp"


void create_command_task(Command&, int, int, int);

void create_lights_task(int, int, int, int);
