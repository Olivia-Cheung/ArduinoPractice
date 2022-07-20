//initialize variables
const int switchPin = 2;
const int motorPin = 9; 
int switchState = 0; 
void setup() {
  // put your setup code here, to run once:
//setups what is an input or output
pinMode(motorPin, OUTPUT);
pinMode(switchPin, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

//reads the state of the pin
  switchState = digitalRead(switchPin); 

  if(switchState == HIGH){

    digitalWrite(motorPin, HIGH); 
  }

  else{
    digitalWrite(motorPin, LOW);
  }
}
