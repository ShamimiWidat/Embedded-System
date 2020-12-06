//initialize the pin number of LEDs
#define LED1_PIN 8
#define LED2_PIN 9

class blinky
{
  private:

    //initialize variables
    double on;
    double off;
    byte pin;
    byte currentState;
    long currentTime;
  
  public:

    void set()
    {
      // initialize the initial state of LED as on
       pinMode(pin, OUTPUT);
       digitalWrite(pin, HIGH);
    }
    
    blinky (byte pin, double y, double z)
    {
      this-> pin = pin;
    
      currentState = HIGH;
      currentTime = 0;

      set();
      
      on = y;
      off = z;
    }

    double Refresh()
    {   
      if( currentState == HIGH)// if LED is on
      {
        if ((millis()- currentTime) >= on)// if LED is on and has reach the limit of on
        {
          currentState = LOW; // turn off the LED
          digitalWrite(pin, currentState); //reinitialize the LED state
          currentTime = millis(); //reinitialize the current time according to the timer      
        }   
      }
      
      else if ((millis()- currentTime) >= off)// if LED is off and has reach the limit of off
      {
        currentState = HIGH; // turn on the LED
        digitalWrite(pin, currentState); //reinitialize the LED state
        currentTime = millis(); //reinitialize the current time according to the timer     
      }
          
    }
};

  // initialize the value for on off LEDs
  blinky Led1(LED1_PIN,750,350);
  blinky Led2(LED2_PIN,400,600);
void setup(){}

void loop() {

  //call class functions
  Led1.Refresh();
  Led2.Refresh();

}
