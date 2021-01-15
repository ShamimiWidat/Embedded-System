#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//initialize the liquid crystal library
//the first parameter is the I2C address
//the second parameter is how many rows are on your screen
//the third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27, 16, 2);

int potPinA = A0, posnowA = 1, outvalprevA = 0, ledA = 7, ledwin = 8;
int pointA, pointB, potvalA, outvalnowA, posprevA;
int buttonA1 = 2, buttonA2 = 3, guessA, guessB;
boolean selectA1 = false, selectA2 = false;

void setup() {

  Serial.begin(9600);
  lcd.init(); //initialize lcd screen
  lcd.backlight();  // turn on the backlight
  pinMode(potPinA, INPUT);//initialize potentiometer as input
  pinMode(ledA, OUTPUT);
  pinMode(ledwin, OUTPUT);
  pinMode(buttonA1, INPUT);//buttonB1 is the ir sensor
  pinMode(buttonA2, INPUT);//buttonB2 is the touch sensor  
  attachInterrupt(digitalPinToInterrupt(buttonA1),pin_ISR0, CHANGE);//set ir sensor as interupt
  attachInterrupt(digitalPinToInterrupt(buttonA2),pin_ISR2, CHANGE);//set touch sensor as interupt  

}
void loop() {

  delay(500);
  displayLCDA();
  selectionA();

  do{
    pointB = Serial.read(); //Read the serial data and store in var
    Serial.println(pointB); //Print data on Serial Monitor
    delay(500);

    if(pointB != -1)//if value is read
      break;
  }while (pointB =-1);//if value is not read

  displayLCDA();
  chooseA();
     
}

void pin_ISR0()
{
  Serial.write(guessA);
  selectA1 = true;//have choose the position

}

void pin_ISR2()
{
  Serial.write(guessA);
  selectA2 = true;//have guess the opponent position

}
