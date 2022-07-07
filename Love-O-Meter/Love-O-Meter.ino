const int sensorPin = A0;
const float baselineTemp = 22.0;

void setup() {
  // put your setup code here, to run once:

//create and open a serial port
  Serial.begin(9600);

//loop through to set up the pins for the LED lights
  for(int pinNumber = 2; pinNumber<5; pinNumber++){

    pinMode(pinNumber, OUTPUT); 
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

//create sensor value variable and output the value in Serial Monitor 
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

//create the voltage based on sensorVal and print out volts and degrees in celsius in Serial Monitor 
  float voltage = (sensorVal / 1024.0) * 5.0; 

  Serial.print(" , Volts: "); 
  Serial.print(voltage); 

  Serial.print(" , degrees C: "); 

//convert the voltage to temperature in degrees

  float temperature = (voltage - .5) * 100; 
  Serial.println(temperature); 

//create a bunch of conditionals and based on how temperature compares to baselineTemp, the three LEDS will light up or not
  if(temperature < baselineTemp+2){

    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
  }

  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
  }

  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){

    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, LOW); 
  }

  else if(temperature >= baselineTemp+6){

    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
  }

  delay(100);

}
