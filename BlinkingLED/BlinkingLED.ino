//LED is connected to digital pin 13
 const int LED = 13;


void setup() {
  // put your setup code here, to run once:

//turn LED into an output
  pinMode(LED, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

// LED light turns on and off every two seconds (2000 ticks)
  digitalWrite(LED, HIGH); 
  delay(2000); 
  digitalWrite(LED, LOW);
  delay(2000); 

}
