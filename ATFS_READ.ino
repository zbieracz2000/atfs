/*
 * EEPROM Read
 *
 * Reads the value of each byte of the EEPROM and prints it
 * to the computer.
 * This example code is in the public domain.
 */

#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;
char filename;
char extension;
int header1 = 0;
int header2 = 0;
int formated = 0;
int list = 0;
int readfile = 0;
int fileaddr = 0;
int filesize = 0;
void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // read a byte from the current address of the EEPROM
  value = EEPROM.read(address);
  if (formated==0)
  {
  if(address==1) if (value==200) header1 = 1; 
  if(address==2) if (value==201) header2 = 1;
  if(header1==1) if (header2==1) formated = 1;
  }  
  if (formated==1) if(list==0)
  {
    Serial.println("WYKRYTO SFORMATOWANĄ PAMIĘĆ");
    Serial.print("POJEMNOŚĆ:"); 
    Serial.print(EEPROM.length());  
    Serial.println(" BAJTÓW"); 
    Serial.println("LISTA PLIKÓW:");  
    list=1;
  }
  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();
  address = address + 1;
  if (address>=3){
    if (value==203) 
    {
      fileaddr=address;
      readfile=1;
    }
    if (readfile==1)
    {
      //if (value<=100) 
      if (value==205) 
      {
        filesize=address-fileaddr;  
        Serial.print("ROZMIAR PLIKU: ");
        Serial.print(filesize);
        Serial.println(" BAJTÓW");
        readfile=0;  
    } 
   }
  }
  if (address == EEPROM.length()) {
    address = 0;
  }
  delay(500);
}
