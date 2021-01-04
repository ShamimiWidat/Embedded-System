void setup() {
  
  Serial.begin(9600);

}

void loop() {

  char* ddrb = (char*)0x24; //Points to DDRB register
  char* portb = (char*)0x25;//Points to PORB register
  *ddrb = 0b00001111;//Set the 4 pins as output
  
  char DriveSteps[] = {1,2,4,8};//Activation pattern of wave drive
  char position = 0;
  
  unsigned long now  = millis();
  unsigned long last;//Stores last time the motor moved
  
  if(now - last >= 5)//If the motor has not moved for 5 ms
  {
    *portb = DriveSteps[position];
    position++;
    
    if(position >= 4)
    {
      position = 0;
    }
    last = now;
    Serial.println((unsigned char)*portb,BIN);//Serial printing is just for trouble shooting
   }

  /*if(now-last>=2)//If the motor has not moved for 2 ms
  {
    *portb  = DriveSteps[position];
    position--;

    if(position < 0)
    {
      position =  3;
    }
    last = now;
    Serial.println((unsigned char)*portb,BIN);//Serial printing is just for trouble shooting
  }*/
}
