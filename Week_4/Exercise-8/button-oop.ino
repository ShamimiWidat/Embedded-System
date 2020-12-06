// initalize the pin assignments for butoons
#define BUTTONA_PIN 3
#define BUTTONB_PIN 4
#define BUTTONC_PIN 5
#define BUTTOND_PIN 6
#define BUTTONE_PIN 7

class input
{
  private:

    // initialize the variables
    byte pin;
    int state;
    int count;
    int lastState;

  public:

    //constructor to assign pin number on button class
    input(byte pin)
    {
      this-> pin = pin; // the pin variable is equal to the initiazlize variable in private

      count = 0; // initial pressed buttons
      lastState = HIGH; // default state of buttons
      
      set(); //setup 
    }

  void set() 
  {
    pinMode(pin, INPUT_PULLUP); // set the buttons to use internal pull_up
  }  

   double calculate()
   {
      state = digitalRead(pin); // read the state of each button
      if( state == LOW && state != lastState) // if the button is pressed at that instant
     {
        count++; // increase the amount of pressed button
        lastState = state; // reinitialize state button
      }

      lastState = state; // if not being pressed, remain the same
    
      return count;
   }
};


  //initialize pin number to its class
  input buttonA(BUTTONA_PIN);
  input buttonB(BUTTONB_PIN);
  input buttonC(BUTTONC_PIN);
  input buttonD(BUTTOND_PIN);
  input buttonE(BUTTONE_PIN);  
  
void setup(){
  Serial.begin(9600);
}

void loop() {

  int countA;
  int countB;
  int countC;
  int countD;
  int countE;

  // read the state of buttons
  countA = buttonA.calculate();
  countB = buttonB.calculate();
  countC = buttonC.calculate();
  countD = buttonD.calculate();
  countE = buttonE.calculate();

  //display the output at serial monitor
  Serial.print("A = ");Serial.print(countA);Serial.print("\t"); 
  Serial.print("B = ");Serial.print(countB);Serial.print("\t");
  Serial.print("C = ");Serial.print(countC);Serial.print("\t");
  Serial.print("D = ");Serial.print(countD);Serial.print("\t");
  Serial.print("E = ");Serial.print(countE);Serial.println("\t");
  
}
