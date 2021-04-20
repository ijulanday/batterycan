#pragma once

#include <Arduino.h>
#include <FlexCAN_T4.h>
#include <math.h>

#define REQ_ALL_CELL_VOLTAGES 0x1F4

extern CAN_message_t battery_message;

void printRawBat(CAN_message_t battery_message);
CAN_message_t readAllCellVoltage(uint8_t packId);