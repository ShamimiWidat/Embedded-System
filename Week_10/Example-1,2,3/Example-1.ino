class Blinky
{
  private:
  
    unsigned long OnTime;//The ON duration in μs
    unsigned long OffTime; //The OFF duration in μs
    
    unsigned long last_time = 0; //The last time a transition occurred
    char mask;//If pin = 3, mask = 0000 1000
    char mask_inv; //If pin = 3, mask_inv= 1111 0111
    
    char* DDR;
    char* PORT;
    
   public:
     Blinky()//Constructor without arguments
      {
        Initialize('B',5,1000000,1000000);
      }
      Blinky(char port,int pin,long ontime,long offtime) //Constructor with arguments
      {
        Initialize(port,pin,ontime,offtime);
      }
      void Initialize(char port,int pin,long ontime,long offtime)
      {
        OnTime = ontime;
        OffTime = offtime;

        switch(port)
        {
          case'B':
            DDR = (char*)0x24;
            PORT = (char*)0x25;
            break;
          case'C':
            DDR =(char*)0x27;
            PORT =(char*)0x28;
            break;
          case'D':
            DDR = (char*)0x2A;
            PORT = (char*)0x2B;
            break;
        }
        mask = (1 << pin); //The expression (1 << pin) will be used often, it is faster to store it
        mask_inv = ~mask;//The inverse of the expression (1 << pin) will also be used often
        *DDR |= mask;//Set the pin as output pin
      }
      
      void ChangeOnOffTimes(long ontime,long offtime)
      {
        OnTime = ontime;
        OffTime = offtime;
      }

      //The refresh function needs to be constantly called. It performs respective transitions.
      void Refresh()
      {
        unsigned long now = micros();
        
        if (*PORT & mask)//The pin is currently HIGH
        {
          if(now - last_time >= OnTime)//If the pin has been HIGH for long enough
          {
            if(OffTime > 0)//If OffTimeis 0, no need to even turn it OFF
            {
              *PORT &= mask_inv; //Make the pin LOW
            }
            
            last_time = now;//Take note of the time
          }
        }
      
        else//The pin is currently LOW
        {
          if(now - last_time >= OffTime)//If the pin has been LOW for long enough
          {
            if (OnTime > 0)//If OnTimeis 0, no need to even turn it ON
            {
              *PORT |= mask;//Make the pin HIGH
              
            }
            last_time = now;//Take note of the time
          }
        }
      }
};

Blinky blinker('B',5,1000000,1000000); //Blink PB5 1s ON and 1s OFF
//Blinky blinker('B',5,200,300); //Blink PB5 200us ON and 300us OFF
//Blinky blinker('B',5,100,200); //Blink PB5 100us ON and 200us OFF 

void setup() {

}

void loop() {

 blinker.Refresh();
}
