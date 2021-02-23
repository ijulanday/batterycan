#pragma once

#include <Arduino.h>
#include <FlexCAN_T4.h>
#include <math.h>

#define REQ_ALL_CELL_VOLTAGES 0x1F4

void printRaw(CAN_message_t msg);
void readAllCellVoltage(uint8_t packId, CAN_message_t *msg, FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> *can);