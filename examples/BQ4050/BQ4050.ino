/**
  Example of how to read battery fuel percentage, total voltage, cell voltages and current
  from TI BQ4050 fuel gauge chip.
  Fuel percentage reading will not be correct unless the battery has been calibrated for this chip
**/

//Libraries to be included
#include "Arduino.h"
#include <Lib_BQ4050.h>

//Default address for device. Note, it is without read/write bit. When read with analyser,
//this will appear 1 bit shifted to the left
#define BQ4050addr     0x0B
//Initialise the device and library
Lib_BQ4050 BQ4050( BQ4050addr );
//Instantiate the structs
extern Lib_BQ4050::Regt registers;

uint32_t previousMillis;
uint16_t loopInterval = 1000;

void setup() {

  Serial.begin(115200);

}

void loop() {

  uint32_t currentMillis = millis();

  if( currentMillis - previousMillis > loopInterval ){
    previousMillis = currentMillis;

    BQ4050.readReg( registers.voltage );
    Serial.print( "Pack voltage: " );
    Serial.print( registers.voltage.val );
    Serial.println( "mV" );
    delay( 15 );
    BQ4050.readReg( registers.current );
    Serial.print( "Pack current: " );
    Serial.print( registers.current.val );
    Serial.println( "mA" );
    delay( 15 );
    BQ4050.readReg( registers.averageTimeToEmpty );
    Serial.print( "Average Time to Empty: " );
    Serial.print( registers.averageTimeToEmpty.val );
    Serial.println( "s" );
    delay( 15 );
    BQ4050.readReg( registers.cellVoltage1 );
    Serial.print( "Cell voltage 1: " );
    Serial.print( registers.cellVoltage1.val );
    Serial.println( "mV" );
    delay( 15 );

    BQ4050.readReg( registers.cellVoltage2 );
    Serial.print( "Cell voltage 2: " );
    Serial.print( registers.cellVoltage2.val );
    Serial.println( "mV" );
    delay( 15 );

    BQ4050.readReg( registers.cellVoltage3 );
    Serial.print( "Cell voltage 3: " );
    Serial.print( registers.cellVoltage3.val );
    Serial.println( "mV" );
    delay( 15 );

    BQ4050.readReg( registers.cellVoltage4 );
    Serial.print( "Cell voltage 4: " );
    Serial.print( registers.cellVoltage4.val );
    Serial.println( "mV" );
    delay( 15 );

     BQ4050.readReg( registers.remainingCapAlarm );
    Serial.print( "Cell voltage 4: " );
    Serial.print( registers.remainingCapAlarm.val );
    Serial.println( " " );
    delay( 15 );



  }

}
