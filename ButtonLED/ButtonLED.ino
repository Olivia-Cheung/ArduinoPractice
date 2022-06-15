const int LED = 13; 
const int BUTTON = 7; 

int val = 0; 
int oldVal = 0; 
int state = 0; 

void setup() {

//creates inputs and outputs
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT); 

}

void loop() {
  
//read input value and store it
val = digitalRead(BUTTON); 

//checks if there was a transition
if((val == HIGH)&& (oldVal == LOW)){

  state = 1- state; 
  delay(10); 
}

//helps with debouncing
if((val  == LOW) && (oldVal == HIGH)){

  delay(10);
}

//store val into oldVal since it will no longer be used
oldVal = val; 

if(state == 1){
  digitalWrite(LED, HIGH);
}

else{

  digitalWrite(LED, LOW);
}

}
