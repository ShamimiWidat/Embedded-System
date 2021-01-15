void chooseB()
{
  displayLCDB();
  selectB1 = false;// to not continue the choosing option in selectionB()
  selectionB();
}

void continueB()
{
  if (guessB == pointA)//if correctly guess opponent position
  {
    digitalWrite(ledwin, HIGH);
    delay(1000);
    digitalWrite(ledwin, LOW);
    delay(1000);
  }
  
  else// if wrong guess
  {
    digitalWrite(ledB, HIGH);
    delay(1000);
    digitalWrite(ledB, LOW);
    delay(1000);

    displayLCDB();
    selectionB();// reguess the position
  }
}
