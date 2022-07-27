#include <LiquidCrystal.h>
//initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
//initialize variables for pins and variables to hold information
const int switchPin = 6; 
int switchState = 0; 
int prevSwitchState = 0; 
int reply; 

void setup() {
  // put your setup code here, to run once:
//set up the number of columns (16) and rows (2) on the LCD
  lcd.begin(16, 2); 
//set the switch pin as an input 
  pinMode(switchPin, INPUT); 
//creates the message "Ask the Crystal Ball!" on column 0, line 1
  lcd.print("Ask the"); 
  lcd.setCursor(0, 1); 
  lcd.print("Crystal Ball!"); 

}

void loop() {
  // put your main code here, to run repeatedly:
//check the status of the switch
switchState = digitalRead(switchPin); 

//compare the switchState to its previous state
if(switchState != prevSwitchState){
  //when switchState == low, the ball in the sensor has been tilted
  if(switchState == LOW){
    //chooses a reply in the switch state and outputs it to answer the user's question
    reply = random(8); 
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("The ball says:"); 
    lcd.setCursor(0, 1); 

   //switch statement that reply randomly selects from
    switch(reply){
      case 0:
        lcd.print("Yes"); 
        break;

      case 1: 
        lcd.print("Most likely");
        break;

      case 2: 
        lcd.print("Outlook good"); 
        break;

      case 3: 
        lcd.print("Unsure");
        break;

      case 4: 
        lcd.print("Ask again");
        break;

      case 5: 
        lcd.print("Doubtful"); 
        break;

      case 6:
        lcd.print("No"); 
        break;
    }
  }
}
//save current switch state as the last state
prevSwitchState = switchState;
}
