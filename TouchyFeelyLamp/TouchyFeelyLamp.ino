#include <CapacitiveSensor.h>

//initialize variables for sensor and pins
CapacitiveSensor capsen = CapacitiveSensor(4,2); 
int threshold = 1000; 
const int ledPin = 12;

void setup() {
  // put your setup code here, to run once:

//create serial monitor session
  Serial.begin(9600);
//set led as an output
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

//store the value reported by the sensor in a variable
  long sensorValue = capsen.capacitiveSensor(30);
//prints out the sensor vlaue in the serial monitor 
  serial.println(sensorValue);

//turns led on if the value is greater than the threshold value and off if the value is lower
  if(sensorValue > threshold){

    digitalWrite(ledPin, HIGH); 
  }
  else{
    digitalWrite(ledPin, LOW);
  }

  delay(10);

}
