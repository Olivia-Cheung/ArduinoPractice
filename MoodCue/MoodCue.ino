//library for servo commands
#include <Servo.h>

//initializing servo and variables
Servo myServo; 

int const potPin = A0; 
int potVal; 
int angle; 


void setup() {
  // put your setup code here, to run once:
//configuring servo to be on port 9
myServo.attach(9); 

// opening up session for serial monitor 
Serial.begin(9600); 
  
}

void loop() {
  // put your main code here, to run repeatedly:

//potVal reads potPin and prints out the value that the servo is at 
  potVal = analogRead(potPin); 
  Serial.print("potVal: "); 
  Serial.print(potVal); 

 /*map scales numbers for us 
  * 
  * takes 5 inputs: 
  * 1. the the number to be scaled (potValue)
  * 2. the minimum value of the input (0)
  * 3. the maximum value of the input (1023)
  * 4. the minimum value of the output (0)
  * 5. the maximum value of the output (179)
  */
  angle = map( potVal, 0, 1023, 0, 179);

 // prints out the angle the servo is at 
  Serial.print(" , angle: "); 
  Serial.println(angle); 

 //servo moves to that angle
  myServo.write(angle); 
  delay(15); 

}
