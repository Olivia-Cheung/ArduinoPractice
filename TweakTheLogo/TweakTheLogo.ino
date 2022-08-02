void setup() {
  // put your setup code here, to run once:
//create serial monitor session
  Serial.begin(9600); 
  

}

void loop() {
  // put your main code here, to run repeatedly:

//reads in input from port A0, divide it by 4, and then wait one millisecond
  Serial.write(analogRead(A0)/4);
  delay(1);  

}
