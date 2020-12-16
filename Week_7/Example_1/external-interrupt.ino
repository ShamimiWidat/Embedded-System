unsigned char* pind = (unsigned char*)0x29;
unsigned char* ddrb = (unsigned char*)0x24;
unsigned char* portb = (unsigned char*)0x25;
unsigned char* sreg = (unsigned char*)0x5F;
unsigned char* eimsk = (unsigned char*)0x3D;
unsigned char* eicra = (unsigned char*)0x69;

void setup() {
  
  *ddrb = 1 << 5;//Set PB5 as output
  *sreg |= (1 << 7); //Enable interrupts in general
  *eimsk=1; //Enable INT0
  *eicra=1; //Set interrupt mode to "any logic change"

}

void loop (){

  
}
ISR(INT0_vect)
{
  bool pin_status= ((*pind) & 4);
  digitalWrite(13, digitalRead(2));
}
