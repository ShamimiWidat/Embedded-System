char *admux = (char*) 0x7C;
volatile unsigned char *adcsra = (unsigned char*) 0x7A;
volatile unsigned char *adch = (unsigned char*) 0x79;
volatile unsigned char *adcl = (unsigned char*) 0x78;

void setup() {
  
  *admux = 0b01000011; //Set analog reference to AVCC and analog source to PC3.
  *adcsra = 0b11000111; //Enable ADC, start conversion and set pre-scalerto 128
  Serial.begin(9600);
  
}

void loop() {

  while(1)
   {
    *adcsra|=0b01000000; //Start conversion (Set ADSC bit)
    while (((*adcsra) &0b01000000))//As long as ADSC bit is HIGH
    {
    //Do nothing
    }

    int lowbyte= (*adcl); //Capture low byte
     int highbyte= (*adch); //Capture high byte
    int value = (highbyte<<8) | lowbyte; //Merge high byte and low byte
    Serial.println(value);

    }
}
