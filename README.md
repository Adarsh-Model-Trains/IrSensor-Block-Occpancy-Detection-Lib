# IrSensor-Block-Occpancy-Detection-Lib

---

# <a href="https://github.com/adarshkumarsingh83/IrSensor-Block-Occpancy-Detection-Lib/archive/production.zip"> Library download link </a>

## About the Lib
```
IrSensor-Block-Detection-Lib is for supporing multiple Ir-Sensor bases block together 
in chain with less complexcity of the programming 

max we can connect any number of block till the arduino has input pins 2 pins per block 
this api support a simple interface where we can controll 1-N blocks for their occupancy and unoccupancy 

NOTE: block number will start from 1 to the nax number configured 

```




### YOUTUBE LINK  FOR LIBRARY DETAILS AND DEMO EXAMPLES
[![IR SENSOR FOR BLOCK DETECTION](http://img.youtube.com/vi/0u4pMxkpFJA/0.jpg)](https://www.youtube.com/watch?v=0u4pMxkpFJA "IR SENSOR FOR BLOCK DETECTION")

## Connections

![img](/image/connections.JPG)
```
+5v and gnd from arduino to the breadboard +ve and -ve common lines 
then supply the smae from breadboard of block 2 and block 3 till block N breadboard common +ve and -ve lines 

pin 13 to the out pin of Sensor start of the block1
pin 12 to the out pin of Sensor end of the block1

pin 11 to the out pin of Sensor start of the block2
pin 10 to the out pin of Sensor end of the block2

pin 9 to the out pin of Sensor start of the block3
pin 8 to the out pin of Sensor end of the block3

repeate the same till the blockN 

connect the jumper from +5v to the vcc of the all the IR sensors of block 1 block 2 and block 3 till block N 
connect the jumper from gnd to the gnd of the all the IR sensors of block 1 block 2 and block 3 till block N

```


## steps for using lib

## include the header file
```

#include "IrBlockSensors.h"
```

## define the object for the IrBlockSensors
```

IrBlockSensors irBlockSensors;

```

## define the number of the block we want 
```
#define NO_OF_BLOCKS 3
```


## initialize the object with in setup method
*   irBlockSensors.initBlockSensors(NO_OF_BLOCKS);
* this will set the number os ir sensor blcok we cant to configure 
```
initBlockSensors() will take total nuber of block we want to configure 

void setup() {
  
   .....

  irBlockSensors.initBlockSensors(NO_OF_BLOCKS);

  .......

}
```

## set the block starting ir sensor pin and end pins 
*    irBlockSensors.setBlockSensorPins(BLOCKNO, BLOCK_START_IR_SENSOR_PIN, BLOCK_END_IR_SENSOR);
*  it will set the block starting ir sensor  pin and block ending ir sensor  pin for particular block number 
```
setBlockSensorPins() will take block number followed by ir sensor pin which is at start of block and ir sensor pin which is at end of block 
void setup() {
  
   .....

  irBlockSensors.setBlockSensorPins(1, 13, 12); //block 1
  irBlockSensors.setBlockSensorPins(2, 11, 10); //block 2
  irBlockSensors.setBlockSensorPins(3, 9, 8);   //block 3

  .......

}
```

## for debug messages a initialize Serial in setup
```
void setup() {
  
  Serial.begin(xxxx); // xxx can be any valid supported number 

  .........
}

```

## use lib method for know the block state
* bool isBlockOccuipied = irBlockSensors.isSensorBlockOccupied(BLOCKNO); 
* will return the if block is occupoied other wise false in all other cases 
```
void loop() {
  
  .......
  
   bool isBlockOccuipied = irBlockSensors.isSensorBlockOccupied(blockNumber);
  ..........
}
```

### Complete Example
```


#include "IrBlockSensors.h"
#define NO_OF_BLOCKS 3

int block_led[] = {7, 6, 5};

IrBlockSensors irBlockSensors;

void setup() {
  Serial.begin(9600);
  irBlockSensors.initBlockSensors(NO_OF_BLOCKS);
  irBlockSensors.setBlockSensorPins(1, 13, 12);
  irBlockSensors.setBlockSensorPins(2, 11, 10);
  irBlockSensors.setBlockSensorPins(3, 9, 8);
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
  bool isBlockOccuipied = irBlockSensors.isSensorBlockOccupied(blockNo);
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

```
