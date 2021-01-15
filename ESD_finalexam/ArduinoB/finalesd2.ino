#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//initialize the liquid crystal library
//the first parameter is the I2C address
//the second parameter is how many rows are on your screen
//the third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27, 16, 2);

int potPinB = A0, posnowB = 1, outvalprevB = 0, ledB = 7, ledwin = 8;
int pointA, pointB, potvalB, outvalnowB, posprevB;
int buttonB1 = 2, buttonB2 = 3, guessA, guessB;
boolean selectB1 = false, selectB2 = false;

void setup() {

  Serial.begin(9600);
  lcd.init(); //initialize lcd screen
  lcd.backlight();  // turn on the backlight
  pinMode(potPinB, INPUT);//initialize potentiometer as input
  pinMode(ledB, OUTPUT);
  pinMode(ledwin, OUTPUT);
  pinMode(buttonB1, INPUT);//buttonB1 is the ir sensor
  pinMode(buttonB2, INPUT);//buttonB2 is the touch sensor
  attachInterrupt(digitalPinToInterrupt(buttonB1),pin_ISR1, CHANGE);//set ir sensor as interupt
  attachInterrupt(digitalPinToInterrupt(buttonB2),pin_ISR3, CHANGE);//set touch sensor as interupt

}
void loop() {

  do{
    pointA = Serial.read(); //Read the serial data from ArduinoA
    Serial.println(pointA); //Print data on Serial Monitor
    delay(500);

    if(pointA != -1)//if value is read
      break;
  }while (pointA =-1);//if value is not read

  displayLCDB();
  selectionB();

  displayLCDB();
  chooseB();
}

void pin_ISR1()
{
  Serial.write(guessB);
  selectB1 = true;//have choose the position
}

void pin_ISR3()
{
  Serial.write(guessB);
  selectB2 = true;//have guess the opponent position
}
