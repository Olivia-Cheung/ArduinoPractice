//set up an array with 6 indexes 


int notes[]= {262, 294, 330, 349};

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

//creates in input reading from port A0
  int keyValue = analogRead(A0);

//printouts keyValue to serial monitor
  Serial.print(keyValue);

//plays a certain note depending on which keyvalue it falls under
  if(keyValue == 1023){

    tone(8, notes[0]);
  }

  else if(keyValue >=990 && keyValue <= 1010){

    tone(8, notes[1]);
  }

  else if(keyValue >=505 && keyValue <=515){

    tone(8, notes[2]);
  }

  else if(keyValue >=5 && keyValue <=10){
    tone(8, notes[3]);
  }

//plays no notes if no keyvalue is detected
 else{
  
  noTone(8);
}
}
