volatile bool changed;
unsigned char* sreg = (unsigned char*)0x5F;
unsigned char* pcicr = (unsigned char*)0x68;
unsigned char* pcmsk2 = (unsigned char*)0x6D;

void setup() {
 
  *sreg |= (1 << 7); //Enable interrupts in general
  *pcicr = 4; //Enable pin change interrupt 0
  *pcmsk2 = 255; //Enable pin change interrupt on all the Port D pin
  Serial.begin(9600);

}

void loop() {
  
  if(changed)
  {
  Serial.println("Sensor values changed");
  //Perform necessary investigation and subsequent operations
  changed =0;
  }

}

ISR(PCINT2_vect)
{
  changed = 1;
  Serial.println("triggered");
}
