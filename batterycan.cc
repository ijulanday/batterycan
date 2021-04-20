#include "batterycan.hh"

CAN_message_t battery_message;

void printRawBat(CAN_message_t msg) {
    Serial.print(msg.id, HEX); Serial.print(" ");
    for (int i = 0; i < 8; i++) {
      Serial.print(msg.buf[i], HEX); Serial.print(" ");
    }
    Serial.println("");
}

CAN_message_t readAllCellVoltage(uint8_t packId) {
    battery_message.flags.extended = true;
    battery_message.id = 0x1000510F | (packId << 4);
    battery_message.buf[0] = 0x01;
    battery_message.buf[1] = 0xF5;
    battery_message.buf[2] = 0x23;
    battery_message.buf[3] = 0x01;
    battery_message.buf[4] = 0x00;
    battery_message.len = 5;
    return battery_message;
}
