void displayLCDB ()
{
  
  lcd.setCursor(0,0); // tell the screen to write on the top row
  lcd.print("Pick a spot :"); // tell the screen to write “hello, from” on the top row
  lcd.setCursor(1,2); // tell the screen to write on the bottom row
  lcd.print("O O O O O O O O O");// display position options

}

void selectionB()
{  
  lcd.setCursor(posnowB,2);
  lcd.print("#");//current position

  do
  {   
      potvalB = analogRead(potPinB);//read analog input from potentiometer
      outvalnowB = map(potvalB, 0, 1023, 0, 8);// put the analog value read in the range of 8-9
      
      if (outvalnowB > outvalprevB && selectB1 == false)// if potentiometer value is increasing and has not choosen any position
      {
        posprevB = posnowB;
        posnowB += 2;
        //Serial.println(posnow);
        lcd.setCursor(posnowB,2);//move current position # according to the analog input
        lcd.print("#");      
        lcd.setCursor(posprevB,2);//overwrite previous position as O
        lcd.print("O");

        guessB = posnowB;
        
      }
    
      else if (outvalnowB < outvalprevB && selectB1 == false)// if potentiometer value is decreasing and has not choosen any position
      {
        posprevB = posnowB;
        posnowB -= 2;
        //Serial.println(posnow);
        lcd.setCursor(posnowB,2);//move current position according to the analog input
        lcd.print("#");
        lcd.setCursor(posprevB,2);//overwrite previous position as O
        lcd.print("O");

        guessB = posnowB;

      }

      else if (selectB1 == true)//if have choosen position
      {
        chooseB();
      }

      else if (selectB2 == true)//if trying to guess opponents position
      {
        continueB();
      }
    outvalprevB = outvalnowB;
    
  }while (true);
}
