//initializes constant for the switch pin
const int switchPin = 8; 

unsigned long previousTime = 0; //stores last updated time for an LED
int switchState = 0; //the current switch state
int prevSwitchState = 0; //previous switch tate
int led = 2; // variable referst to the LEDs

// 1000 = 1 second in milliseconds
long interval = 1000; 

void setup() {
  // put your setup code here, to run once:

//initalizes all the LED pins as outputs
  for (int x = 2; x<8; x++){

    pinMode(x, OUTPUT); 
  }
  //set the tilt switch pin as input
  pinMode(switchPin, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

//store the time since the Arduino started running 
  unsigned long currentTime = millis(); 

//compares current time to previous time an LED turned on
//if it is greater than the interval, the inner if statement will run and break
  if(currentTime - previousTime > interval){
    //saves the current time as the last time an LED was lit
    previousTime = currentTime; 
    //turn LED on
    digitalWrite(led, HIGH); 
    //increment the led variable and in 10 mins, the next LED will light up
    led++; 

  //the hours is up
    if(led == 7){
      
    }
  }

  //reads the switch value
  switchState = digitalRead(switchPin); 

//incase the switch value has changed
  if(switchState != prevSwitchState){
    //turn off all the LEDS
    for(int x = 2; x<8; x++){
      digitalWrite(x, LOW);
    }
    //reset the LED variable to initial value and reset timer
    led = 2;
    previousTime = currentTime; 
  }
//set the previou switch state to the current state
  prevSwitchState = switchState;

}
