//Source:  https://www.youtube.com/watch?v=gqAHOoqo3OI&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-&index=13

const String lessonName = "LESSON 13: Controlling an RGB LED with Arduino";
const int baudSpeed = 9600;
const int sleepTime = 1000;
const int shortSleepTime = 500;

const int ledBrightness = 100; //MIN is 0, MAX is 255
const int ledOff = 0; //MIN is 0, MAX is 255
const int ledFullBrightness = 255; //MIN is 0, MAX is 255


//Pins
const int pinBlue = 6;
const int pinGreen = 10;
const int pinRed = 11;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed);
  Serial.println(lessonName);
  setUpPins();
}

void loop() {
  // put your main code here, to run repeatedly:

  testRgb();
}

//Test function - changing RGB colors
void testRgb(){

  //Blue
  Serial.println("Blue is on");
  analogWrite(pinBlue, ledBrightness);
  delay(sleepTime);
  //analogWrite(pinBlue, ledOff);
  turnOffAllLed();

  //Green
  Serial.println("Green is on");
  analogWrite(pinGreen, ledBrightness);
  delay(sleepTime);
  //analogWrite(pinGreen, ledOff);
  turnOffAllLed();

  //Red
  Serial.println("Red is on");
  analogWrite(pinRed, ledBrightness);
  delay(sleepTime);
  //analogWrite(pinRed, ledOff);
  turnOffAllLed();

  //RGB
  Serial.println("RGB is on");
  turnOnAllLed();
  delay(sleepTime);
  turnOffAllLed();
}

//Turn off all LEDs
void turnOffAllLed(){

  analogWrite(pinBlue, ledOff);
  analogWrite(pinGreen, ledOff);
  analogWrite(pinRed, ledOff);
}

//Turn off all LEDs
void turnOnAllLed(){

  analogWrite(pinBlue, ledBrightness);
  analogWrite(pinGreen, ledBrightness);
  analogWrite(pinRed, ledBrightness);
}


//Set-up analog pins
void setUpPins(){

  pinMode(pinBlue, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinRed, OUTPUT);
}
