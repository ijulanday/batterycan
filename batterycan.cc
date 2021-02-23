#include "batterycan.hh"

void printRaw(CAN_message_t msg) {
    Serial.print(msg.id, HEX); Serial.print(" ");
    for (int i = 0; i < 8; i++) {
      Serial.print(msg.buf[i], HEX); Serial.print(" ");
    }
    Serial.println("");
}

void readAllCellVoltage(uint8_t packId, CAN_message_t *msg, FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> *can) {
    msg->flags.extended = true;
    msg->id = 0x1000510F | (packId << 4);
    msg->buf[0] = 0x01;
    msg->buf[1] = 0xF5;
    msg->buf[2] = 0x23;
    msg->buf[3] = 0x01;
    msg->buf[4] = 0x00;

    can->write(*msg);
    bool first = true;
    int counter = 1;
}
