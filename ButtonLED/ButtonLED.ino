const int LED = 13; 
const int BUTTON = 7; 

int val = 0; 


void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

val = digitalRead(BUTTON); 

if(val == LOW){

  digitalWrite(LED, HIGH); 

}else{

  digitalWrite(LED, LOW);
}
}
