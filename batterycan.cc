#include "batterycan.hh"

CAN_message_t battery_message;

void printRawBat(CAN_message_t msg) {
    Serial.print(msg.id, HEX); Serial.print(" ");
    for (int i = 0; i < 8; i++) {
      Serial.print(msg.buf[i], HEX); Serial.print(" ");
    }
    Serial.println("");
}

void readAllCellVoltage(uint8_t packId, CAN_message_t *battery_message, FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> *can) {
    battery_message->flags.extended = true;
    battery_message->id = 0x1000510F | (packId << 4);
    battery_message->buf[0] = 0x01;
    battery_message->buf[1] = 0xF5;
    battery_message->buf[2] = 0x23;
    battery_message->buf[3] = 0x01;
    battery_message->buf[4] = 0x00;

    can->write(*battery_message);
}
