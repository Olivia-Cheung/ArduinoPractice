int switchState = 0; 

void setup() {
  // put your setup code here, to run once:

//initalize the different pins and establish if they're input or output
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);

  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  switchState = digitalRead(2);

//when the switchState is not pressed, LED 3 will light up 
  if (switchState == LOW){

    digitalWrite(3, HIGH); 
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
  }

//when the switchState is pressed, LED 4 and 5 will take turns lighting up in a quarter of a second interval
  else{

    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250); 

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250);

    
  }

}
