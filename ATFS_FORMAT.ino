/*
 * EEPROM Write
 *
 * Stores values read from analog input 0 into the EEPROM.
 * These values will stay in the EEPROM when the board is
 * turned off and may be retrieved later by another sketch.
 */

#include <EEPROM.h>

/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
int addr = 3;
int state = 0;
int readbit = 0;  

void setup() {
  EEPROM.write(1, 200);
  EEPROM.write(2, 201);
  Serial.begin(9600);
}

void loop() {
  if (state==0)
  {
    EEPROM.write(1, 200);
    EEPROM.write(2, 201);
    Serial.println("FORMATOWANIE"); 
    state=1;
  }
  if (state==1)
  {
    EEPROM.write(addr, 255);
    addr = addr + 1;
  }
  /***
    Advance to the next address, when at the end restart at the beginning.

    Larger AVR processors have larger EEPROM sizes, E.g:
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb EEPROM storage.
    - Arduino Mega:       4kb EEPROM storage.

    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all AVR processors.
  ***/
  if (addr == EEPROM.length()) {
   if (state==1){
    state=2;
   if (state == 2)
   {
   //Serial.println(EEPROM.read(1));
   //Serial.println(EEPROM.read(2));
   state=3;
   if(EEPROM.read(1)==200) if(EEPROM.read(2)==201)
    {
      Serial.println("FORMATOWANIE UKOŃCZONE");
      Serial.print("POJEMNOŚĆ PAMIĘCI: ");
      Serial.println(EEPROM.length());
      EEPROM.write(3, 203);
      EEPROM.write(4, 54);
      EEPROM.write(5, 58);       
      EEPROM.write(6, 54);       
      EEPROM.write(7, 54);       
      EEPROM.write(8, 45);       
      EEPROM.write(9, 53);       
      EEPROM.write(9, 54);
      EEPROM.write(10, 204);
      EEPROM.write(11, 58);
      EEPROM.write(12, 44);
      EEPROM.write(13, 205);
      EEPROM.write(14, 203);
      EEPROM.write(15, 54);
      EEPROM.write(16, 58);       
      EEPROM.write(17, 54);       
      EEPROM.write(18, 44);       
      EEPROM.write(19, 57);       
      EEPROM.write(20, 41);       
      EEPROM.write(21, 204);
      EEPROM.write(22, 58);
      EEPROM.write(23, 44);
      EEPROM.write(24, 44);
      EEPROM.write(25, 44);
      EEPROM.write(26, 205);
      
      
    }
    else
    {
      Serial.println("BŁĄD FORMATOWANIA!");
    }
   }
   }
  }

  delay(2);
}
