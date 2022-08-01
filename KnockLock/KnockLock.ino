#include <Servo.h>
//initialize servo variable
Servo myServo; 
//initialize pins for the piezo, switch, and LED lights
const int piezo = A0; 
const int switchPin = 2; 
const int yellowLED = 3; 
const int greenLED = 4; 
const int redLED = 5; 

//initialize piezo value and switch value
int knockVal; 
int switchVal;

//initialize values of quiet and loud knocks
const int quietKnock = 10; 
const int loudKnock = 100; 

//variable to indicate if locked or not 
bool locked = false; 
// variable for how many valid knocks the arduino has received 
int numberOfKnocks = 0; 

void setup() {
  // put your setup code here, to run once:
//attach the servo to pin 9 
  myServo.attach(9); 

// make the LED pins into outputs
  pinMode(yellowLED, OUTPUT); 
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT); 

//makes the switch into an input
  pinMode(switchPin, INPUT); 

//creates a session for serial monitor 
  Serial.begin(9600); 

//green LED lights turn on, servo goes to unlcoked position, and prints out status to the serial monitor 
  digitalWrite(greenLED,HIGH); 
  myServo.write(0); 
  Serial.println("the box is unlocked!"); 

}

void loop() {
  // put your main code here, to run repeatedly:

//if the box is unlcoked
  if(locked == false){
    //read the value of the switch pin 
    switchVal = digitalRead(switchPin); 

//if the button is pressed, lock the box
    if(switchVal == HIGH){
    //boolean becomes true 
    locked = true; 
    //change the status LEDs
    digitalWrite(greenLED, LOW); 
    digitalWrite(redLED, HIGH); 
    //move the servo to the locked position
    myServo.write(90); 
    //print out status
    Serial.println("the box is locked!"); 
    //wait for the servo to move into position 
    delay(100); 
    }
  }

//if the box is locked 
  if(locked == true){
    //check the value of the piezo 
    knockVal = analogRead(piezo); 

    //if statement runs when there are not enough valid knocks
    if(numberOfKnocks < 3 && knockVal > 0){
      //checks to see if the knock is in range
      if(checkForKnock(knockVal) == true){
        //increments numberOfKnocks when a knock is detected
        numberOfKnocks++; 
      }
      //print out status of knocks 
      Serial.print(3 - numberOfKnocks); 
      Serial.print(" more knocks to go "); 
    }

//if there are three knocks
    if(numberOfKnocks >= 3){
    //box is unlock
      locked = false;
    //move the servo to the unlocke position 
      myServo.write(0); 
    //wait for it to move 
      delay(20); 
    //change status LEDs
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW); 
      Serial.println("the box is unlocked!"); 
      
    //reset number of knocks
      numberOfKnocks = 0; 
      
    }
  }
}

//this function checks to see if a detected knock is within max and min range
bool checkForKnock(int value){

  if(value > quietKnock && value < loudKnock){
//if the knock is greater than the minimum and larger than the maximum
    digitalWrite(yellowLED, HIGH); 
    delay(50); 
    digitalWrite(yellowLED, LOW);

//prints out the status and returns true
    Serial.print("Value knock of value "); 
    Serial.println(value); 
    return true; 
  }

  else{
//if the knock is not within the range, it prints out the value and return false
    Serial.print(" Bad knock value "); 
    Serial.println(value); 
    return false;
  }
}
