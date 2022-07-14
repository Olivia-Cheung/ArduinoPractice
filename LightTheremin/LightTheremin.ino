//initialize sensor variable, high and low values, and ledPin
int sensorValue; 
int sensorLow = 1023; 
int sensorHigh = 0; 
const int ledPin = 13; 


void setup() {
  // put your setup code here, to run once:

//creates ledPin into an outpu and turns it on
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, HIGH);

//calibrates the surrounding light for the first five seconds the program runs
  while(millis() < 5000){
    sensorValue = analogRead(A0); 
  //finds the maximum sensor value
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
   //findt the minimum sensor value
    if(sensorValue < sensorLow){

      sensorLow = sensorValue; 
    }
    
  }
//calibrate finishes and ledPin turns off
  digitalWrite(ledPin, LOW); 

}

void loop() {
  // put your main code here, to run repeatedly:

//initializes sensorValue to A0 port
  sensorValue = analogRead(A0); 
//maps the sensor value to a range of pitches
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000); 

//plays the tone for 20 milliseconds on pin 8 and waits for a second
  tone(8, pitch, 20); 
  delay(10);

}
