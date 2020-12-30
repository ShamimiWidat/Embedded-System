class EEPROM
{
  public:
    static void WriteByte(int address,char data)
    {
      char* data_register = (char*)0x40; //Points to EEDR
      volatile char* control_register = (char*)0x3F; //Points to EECR
      int* address_register = (int*)0x41; //Points to EEAR. Note that intis 16bit on ATmega328p
      //This pointer points to both low byte and high byte of EEAR
      while(((*control_register) &2))//If the data is being written (EEPE is high)
      {
      //do nothing
      }
        *address_register = address; //Stores the address in the EEAR
        *data_register = data; //Stores the data in the EEDR
        *control_register = 4; //Enable Master Write
        *control_register |= 2; //Start writing
     }

    static char ReadByte(int address)
    {
      char* data_register = (char*)0x40; //Points to EEDR
      volatile char* control_register = (char*)0x3F; //Points to EECR
      int* address_register = (int*)0x41; //Points to EEAR. Note that intis 16bit on ATmega328p
      //This pointer points to both low byte and high byte of EEAR
  
      while(((*control_register) & 2))//If the data is being written (EEPE is high)
      {
      //do nothing
      }
        *address_register = address; //Stores the address in the EEAR
        *control_register = 1; //Set EERE (Initiate reading)
        return* data_register; //Return the contents of the data register (EEDR)
    }   
};

void setup() {

  Serial.begin(9600);
  EEPROM :: WriteByte(56,90); //Write a value of 168 to the memory location 115
  unsigned char a = EEPROM :: ReadByte(56); //Read the value at memory location 115
  Serial.println(a); //Prints the value of the EEPROM at memory address 115

}

void loop() {
  

}
