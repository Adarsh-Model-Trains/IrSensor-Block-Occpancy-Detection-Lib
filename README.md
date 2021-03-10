# Ir-Sensor-lib

---

# <a href="https://github.com/adarshkumarsingh83/Pcf8574-lib/archive/main.zip"> Library download link </a>

## About the Lib
```
Ir-Sensor-lib is for supporing multiple Ir-Sensor bases block together 
in chain with less complexcity of the programming 

max we can connect any number of block till the arduino has input pins 2 pins per block 
this api support a simple interface where we can controll 1-N blocks for their occupancy and unoccupancy 

```


## Connections

![img](/image/connection.JPG)
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

#include "BlockSensors.h"
```

## define the object for the BlockSensors
```

BlockSensors blockSensors;

```

## define the number of the block we want 
```
#define NO_OF_BLOCKS 3
```


## initialize the object with in setup method
```
void setup() {
  
   .....

  blockSensors.initBlockSensors(NO_OF_BLOCKS);

  .......

}
```

## set the block starting ir sensor pin and end pins 
```
void setup() {
  
   .....

  blockSensors.setBlockSensorPins(0, 13, 12);
  blockSensors.setBlockSensorPins(1, 11, 10);
  blockSensors.setBlockSensorPins(2, 9, 8);

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
```
void loop() {
  
  .......

   bool isBlockOccuipied = blockSensors.isSensorBlockOccupied(blockNumber);
  ..........
}
```

### Complete Example
```

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

```