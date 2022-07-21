const int controlPin1 = 2; //connected to pin 7 on the H-bridge
const int controlPin2 = 3; //connected to pin 2 on the H-bridge
const int directionSwitchPin = 4; //connected to the switch for direction
const int onOffSwitchStateSwitchPin = 5; //connected to switch turning motor on and off
const int enablePin = 9; //connected to pin 1 on the H-bridge
const int potPin = A0; //connected to the potentiometer's output

//create variables to hold input values
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0; 
int directionSwitchState =0; 
int previousDirectionSwitchState =0; 

int motorEnabled =0; //turns motor on and off
int motorSpeed =0; //speed of motor
int motorDirection =0; // current direction of the motor

void setup() {
  // put your setup code here, to run once:
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT); 
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT); 
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

//read value of on and off switch
onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
delay(1); 

//read the value of the direction switch
directionSwitchState = digitalRead(directionSwitchPin); 
delay(1);

//reads the value of the pot and divide by 4 to get a value that can be used for PWM
motorSpeed = analogRead(potPin)/4; 

//if statement executes when the on/off button changed state since the last loop 
if(onOffSwitchState != previousOnOffSwitchState){
  //inner if statement executes when the button is pressed and it changes the value of motorEnabled
  if(onOffSwitchState == HIGH){
    motorEnabled = !motorEnabled;
  }
}

if(directionSwitchState != previousDirectionSwitchState){
  if(directionSwitchState == HIGH){
    motorDirection = !motorDirection;
  }
}

//changes the motor spinning direction by talking to the control pins of the H-Bridge
if(motorDirection == 1){
  digitalWrite(controlPin1, HIGH); 
  digitalWrite(controlPin2, LOW); 
  }
  else{
    digitalWrite(controlPin1, LOW); 
    digitalWrite(controlPin2, HIGH); 
  }

//if motor is supposed to be on, allow it to run and PWM the enable pin to vary the speed
  if(motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }
//if motor is not supposed to be on, then turn off motor
  else{
    analogWrite(enablePin, 0); 
  }
//save previous states of direction and on/off switch 
  previousDirectionSwitchState = directionSwitchState; 
  previousOnOffSwitchState = onOffSwitchState;

}
