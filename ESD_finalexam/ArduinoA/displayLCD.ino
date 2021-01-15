void displayLCDA ()
{
  
  lcd.setCursor(0,0); // tell the screen to write on the top row
  lcd.print("Pick a spot :"); // tell the screen to write “hello, from” on the top row
  lcd.setCursor(1,2); // tell the screen to write on the bottom row
  lcd.print("O O O O O O O O O");// display position options

}

void selectionA()
{  
  lcd.setCursor(posnowA,2);
  lcd.print("#");//current position

  do
  {   
      potvalA = analogRead(potPinA);//read analog input from potentiometer
      outvalnowA = map(potvalA, 0, 1023, 0, 8);// put the analog value read in the range of 8-9
      
      if (outvalnowA > outvalprevA && selectA1 == false)// if potentiometer value is increasing and has not choosen any position
      {
        posprevA = posnowA;
        posnowA += 2;
        //Serial.println(posnow);
        lcd.setCursor(posnowA,2);//move current position # according to the analog input
        lcd.print("#");      
        lcd.setCursor(posprevA,2);//overwrite previous position as O
        lcd.print("O");

        guessA = posnowA;
        
      }
    
      else if (outvalnowA < outvalprevA && selectA1 == false)// if potentiometer value is decreasing and has not choosen any position
      {
        posprevA = posnowA;
        posnowA -= 2;
        //Serial.println(posnow);
        lcd.setCursor(posnowA,2);//move current position # according to the analog input
        lcd.print("#");
        lcd.setCursor(posprevA,2);//overwrite previous position as O
        lcd.print("O");

        guessA = posnowA;

      }

      else if (selectA1 == true)//if have choosen position
      {
        chooseA();
      }
      else if (selectA2 == true)//if trying to guess opponents position
      {
        continueA();
      }
      
    outvalprevA = outvalnowA;
    
  }while (true);
}
