void chooseA()
{
  displayLCDA();
  selectA1 = false;// to not continue the choosing option in selectionA()
  selectionA();
}

void continueA()
{
  if (guessA == pointB)//if correctly guess opponent position
  {
    digitalWrite(ledwin, HIGH);
    delay(1000);
    digitalWrite(ledwin, LOW);
    delay(1000);
  }
  
  else
  {
    digitalWrite(ledA, HIGH);
    delay(1000);
    digitalWrite(ledA, LOW);
    delay(1000);

    displayLCDA();
    selectionA();// reguess the position
  }
}
