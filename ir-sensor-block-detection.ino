
#include "BlockSensors.h"
#define NO_OF_BLOCKS 3

BlockSensors blockSensors;

void setup() {
  Serial.begin(9600);
  blockSensors.initBlockSensors(NO_OF_BLOCKS);
  blockSensors.setBlockSensorPins(0, 13, 12);
  blockSensors.setBlockSensorPins(1, 11, 10);
  blockSensors.setBlockSensorPins(2, 9, 8);
}

void loop() {
  delay(1000);
  for (int i = 0; i < NO_OF_BLOCKS; i++) {
    bool isBlockOccuipied = blockSensors.isSensorBlockOccupied(i);
    Serial.print("Block no  ");
    Serial.print(i);
    Serial.print("  isBlockOccuipied  ");
    Serial.println(isBlockOccuipied);
  }
}
