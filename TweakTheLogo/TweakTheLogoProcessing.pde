import processing.serial.*;
//initialize variables for the port, logo, and color
Serial myPort;
PImage logo;
int bgColor = 0;
void setup()
{
    //initialize color mode, the location of the arduino logo, and size window of arduino
    colorMode(HSB, 255);
    logo = loadImage("https://www.arduino.cc/arduino_logo.png");
    surface.setSize(logo.width * 2, logo.height * 2);
   //print in console what ports are avalible for input
    println("Available Serial ports: ");
    printArray(Serial.list());
   //create a new serial port that connects to the same port the arduino ide was initialized to
    myPort = new Serial(this, Serial.list()[0], 9600);
}

//function to change the background color
void draw(){

  //when the port is avaliability is true, it's going to read the input from the potentiometer, change the background color, and print out the value in the console
    if(myPort.available() > 0)
    {
        bgColor = myPort.read();
        myPort.clear();
        println(bgColor);
    }
   //this is here to make sure the background and logo do appear when this function is called 
    background(bgColor, 255, 255);
    image(logo, logo.width / 2, logo.height / 2);
}
 
