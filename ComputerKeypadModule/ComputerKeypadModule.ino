#include <Keypad.h>
#include <Wire.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

const int PORT_IIC = 0x3F;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  Wire.begin();
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Wire.beginTransmission(PORT_IIC); 
    Wire.write(customKey);
    Wire.endTransmission();
    Serial.println(customKey);
  }
}
