
#include "BlockSensors.h"
#define NO_OF_BLOCKS 3

int block_led[] = {7, 6, 5};

BlockSensors blockSensors;

void setup() {
  Serial.begin(9600);
  blockSensors.initBlockSensors(NO_OF_BLOCKS);
  blockSensors.setBlockSensorPins(1, 13, 12);
  blockSensors.setBlockSensorPins(2, 11, 10);
  blockSensors.setBlockSensorPins(3, 9, 8);
  for (int i = 0; i < NO_OF_BLOCKS; i++) {
    pinMode(block_led[i], OUTPUT);
  }
}

void loop() {
  for (int i = 1; i <= NO_OF_BLOCKS; i++) {
    checkBlockStatus(i);
  }
}

void checkBlockStatus(int blockNo) {
  bool isBlockOccuipied = blockSensors.isSensorBlockOccupied(blockNo);
  Serial.print("Block no  ");
  Serial.print(blockNo);
  Serial.print("  isBlockOccuipied  ");
  Serial.println(isBlockOccuipied);
  if (isBlockOccuipied) {
    digitalWrite(block_led[blockNo - 1], HIGH);
  } else {
    digitalWrite(block_led[blockNo - 1], LOW);
  }
}
