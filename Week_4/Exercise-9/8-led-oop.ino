// define all the pin assignment for the LEDs
#define LED1_PIN 0
#define LED2_PIN 1
#define LED3_PIN 2
#define LED4_PIN 3
#define LED5_PIN 4
#define LED6_PIN 5
#define LED7_PIN 6
#define LED8_PIN 7
// define the size of the array
#define pinCount 8

class blinky
{
  private:

    // intialize the variables
    int curState, pin;
    long highState, lowState, prevmillis;
    
  public:

    // initliaze the pin number according to the array number
    void setPin(int num)
    {pin=num;}

    // initialize the value of the LEDs
    void setState(int val)
    {curState = val;}

    // returned the initialized pin in setPin function to the called function
    int getPin()const
    {return pin;}
    
    void initialize(long high,long low)
    {
      highState = high; // high = on
      lowState = low; // low = off
    }

    // initialize the timer of the program to 0
    void resetPrevMillis()
    {prevmillis = 0;}
    
    void Refresh()
    {
      if(curState == HIGH && millis() - prevmillis >= highState) // the reach the limit duration of HIGH state
      {
        digitalWrite(pin,LOW); // turn the LED off
        curState = LOW;
        prevmillis = millis(); //reinitialize the timer
      }
      else if(curState == LOW && millis() - prevmillis >= lowState)// the reach the limit duration of LOW state
      {
        digitalWrite(pin,HIGH); // turn the LED on
        curState = HIGH;
        prevmillis = millis(); //reinitialize the timer
      }
    }
};

blinky Led[8]; // initialization of the LED array
void setup()
{
  for(int x=0;x<8;x++) // initialization for all LEDs as array
  {
    Led[x].setPin(x);  // initliaze the pin number according to the array number
    pinMode(Led[x].getPin(),OUTPUT); // define all the LED as outputs
    Led[x].setState(LOW); // all the inital condition of LEDs are low
    Led[x].resetPrevMillis();
  }

  // initializing the value for on off durations
  Led[0].initialize(781,515);
  Led[1].initialize(2014,1348);
  Led[2].initialize(343,573);
  Led[3].initialize(678,1839);
  Led[4].initialize(342,534);
  Led[5].initialize(1478,326);
  Led[6].initialize(1859,351);
  Led[7].initialize(777,888);
}
void loop()
{
  // call the function to output the LEDs in a loop
  for(int x = 0; x < pinCount; x++)
    Led[x].Refresh();
}
