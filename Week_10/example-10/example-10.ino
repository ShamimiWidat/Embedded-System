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

class Servo
{
  private:
    Blinky oscillator;
    int Period;

  public:
    Servo()
    {
      Initialize('B',5,20000);
    }
    Servo(char port,int pin,int period)
    {
      Initialize(port,pin,period);
    }
    void Initialize(char port,int pin,int period)
    {
      Period = period;
      oscillator.Initialize(port,pin,0,period);
    }
    void Write(int ontime)
    {
      oscillator.ChangeOnOffTimes(ontime, Period - ontime);
    }
    void Refresh()
    {
      oscillator.Refresh();
    }
};

class ServoSweeper
{
  private:
    Servo* servo;
    int Min,Max,Step,Delay_ms;
    int Current;
    unsigned long last_time=0;

  public:
    ServoSweeper()
    {
    }
    ServoSweeper(Servo* _servo,int _Min,int _Max,int _Step,int _Delay_ms)
    {
      Initialize(_servo,_Min,_Max,_Step,_Delay_ms);
    }
    void Initialize(Servo* _servo,int _Min,int _Max,int _Step,int _Delay_ms)
    {
      servo = _servo;
      Min = _Min;
      Max = _Max;
      Step = _Step;
      Delay_ms = _Delay_ms;
      Current =_Min;
    }
    void Refresh()
    {
      unsigned long now = millis();
      if(now - last_time >= Delay_ms)
      {
        last_time=now;
        Current +=Step;
        servo -> Write(Current);//equivalent to (*servo).Write(Current);
        
        if(Current >= Max ||Current <= Min)
        {
          Step = -Step;
        }
      }
      servo -> Refresh(); //equivalent to (*servo).Refresh()
    }
};

unsigned long last_time;
int Min = 544;
int Max = 2400;
int Step = 10;
int Delay_ms = 25;
int Current = Min;
Servo servo('B',0,20000);

void setup() {
  
}

void loop() {
 
  unsigned long now = millis();
  if (now - last_time >= Delay_ms)
  {
    last_time = now;
    Current += Step;
    servo.Write(Current);
    
    if(Current >= Max ||Current <= Min)
    {
      Step = -Step;
    }
    servo.Refresh();
  }
}
