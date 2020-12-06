int potentiometer = A0; // Analog input pin that the potentiometer is attached to
int reading;
int outputValue;

void setup() {

  pinMode(potentiometer, INPUT); // intialize potentiometer as input
  Serial.begin(9600); // initialize serial communications at 9600 bps

}

void loop() {

  reading = analogRead(potentiometer); // read the analog in value
  Serial.println(reading); //display the result in serial monitor

}
