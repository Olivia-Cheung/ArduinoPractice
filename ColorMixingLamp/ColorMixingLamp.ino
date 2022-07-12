
//initalize phototransistors
const int redSensorPin = A0; 
const int greenSensorPin = A1; 
const int blueSensorPin = A2;

//ports for the rgb pins 
const int redLEDPin = 10; 
const int greenLEDPin = 9; 
const int blueLEDPin = 11; 

//initialize variables 
int redValue = 0;
int greenValue = 0;
int blueValue = 0; 
int redSensorValue = 0;
int greenSensorValue = 0; 
int blueSensorValue = 0; 



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(redLEDPin, OUTPUT); 
  pinMode(greenLEDPin, OUTPUT); 
  pinMode(blueLEDPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  redSensorValue = analogRead(redSensorPin); 
  delay(5); 
  greenSensorValue = analogRead(greenSensorPin); 
  delay(5); 
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw Sensor Values \t red: "); 
  Serial.print(redSensorValue); 
  Serial.print("\t green: "); 
  Serial.print(greenSensorValue); 
  Serial.print("\t blue: "); 
  Serial.print(blueSensorValue); 

  redValue = redSensorPin/4; 
  greenValue = greenSensorPin/4; 
  blueValue = blueSensorPin/4; 


  Serial.print(" Mapped Sensor Values \t red:"); 
  Serial.print(redValue); 
  Serial.print(" \t green "); 
  Serial.print(greenValue); 
  Serial.print(" \t blue ");
  Serial.println(blueValue);

   analogWrite(redLEDPin, redValue); 
   analogWrite(greenLEDPin, greenValue); 
   analogWrite(blueLEDPin, blueValue); 
  

}
