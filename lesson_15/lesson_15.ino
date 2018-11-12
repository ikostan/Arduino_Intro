//Source: https://www.youtube.com/watch?v=Ltp3skGLqFM&index=16&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-
/*
 * How to read colors with the color sensor:
 * 
 * S2   |  S3   |  Color Read
 * ---------------------------
 * LOW  |  LOW  |  Red
 * LOW  |  HIGH |  Blue
 * HIGH |  HIGH |  Green
 * 
 * pulseWidth = pulseIn(outPin, LOW);    //Measure length of a LOW pulse at pin outPin.
 * This measurement will return a value between 0 an 102,400. 
 * 
 * Because of this, you need to be sure to declare pulseWidth variable an unsigned int. 
 * Normal integers can only hold numbers up to +/- 32,768 an unsigned int allows only positive numbers but allows numbers up to 4,294,967,295. 
 * 
 * The number that is returned which we put in the variable pulseWidth above can be interpreted as such: The lower the number, the stronger the color being read. 
 * The larger the number, the weaker the color.
 * 
 * We need to somehow convert this rather odd number into something that means something in the real world. 
 * Well, when we write values to an RGB LED we want them to be between 0 and 255.  
 * Also, that is a fairly standard scale to report RGB colors . . . by giving the relative strength of the compoents of R, G, and B on a scale from 0 to 255. 
 * First we need to convert 0 to 102,400 to this range.  102,400/400 = 256. 
 * Almost exactly what we want! But we need to subtract one. 
 * So, we could say that rColorStrength = (pulseWidth/400) – 1. 
 * That gets us a number between 0 and 255. 
 * Only problem is, remember that in the original pulseWidth, big numbers mean weak colors and small numbers mean strong colors, so we need to fix that. 
 * We could fix it by now saying:
 * rColorStrength = (255 – rColorStrength);
 * That simply adjusts things so that big numbers now mean strong colors. Also, you can see this example would be for reading red. You would need to repeat by setting S2 and S3 to also create gColorStrenght and bColorStrength for green and blue. 
 * 
 */


const int baudSpeed = 9600;
const int waitTime = 25; //Wait time in ms
const int longWaitTime = 500; 

const String lessonName = "LESSON 15: Super Cool Arduino Color Sensor Project";
const int pinRed = 11;
const int pinGreen = 10;
const int pinBlue = 6;

const int ledBrightness = 120;

const int pinOUT = 4;
const int pinS2 = 7;
const int pinS3 = 8;

//Color strength: numbers between 0-255
int redColorStrength;
int greenColorStrength;
int blueColorStrength;

unsigned int pulseWidth; //Big int that can hold numbers up to 4,294,967,295

//Initial Setup
void setup() {
  
  // put your setup code here, to run once:

  //Serial port setup
  Serial.begin(baudSpeed);
  Serial.println(lessonName);

  //Test LED
  turnOffLed();
  testLed();
  turnOffLed();
}

//Main loop
void loop() {
  
  // put your main code here, to run repeatedly:
  
  //
  
}


//Turn off all colors
void turnOffLed(){
  
  //Turn off all colors
  analogWrite(pinRed, 0); //red
  analogWrite(pinGreen, 0); //green
  analogWrite(pinBlue, 0); //blue
}


//Test LED
void testLed(){

  //Red
  turnOffLed();
  analogWrite(pinRed, ledBrightness);
  delay(longWaitTime); 

  //Green
  turnOffLed();
  analogWrite(pinGreen, ledBrightness);
  delay(longWaitTime); 

  //Blue
  turnOffLed();
  analogWrite(pinBlue, ledBrightness);
  delay(longWaitTime);
}
