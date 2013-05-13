/*
	LcdDisplay.cpp -- Serial LCD Display Library for Arduino - Version 0.1
	
	Written for SDP (0.1) by Eric Moore
	
	Library to enable simple interface with Serial Enabled 16x2 LCD - Black on Green 3.3V
	https://www.sparkfun.com/products/9066

	Defines some basic functions to facilitate easy communication between the arduino and the LCD 

*/

#include "Arduino.h"
#include <SoftwareSerial.h>

#include "LcdDisplay.h"

SoftwareSerial LCD = SoftwareSerial(0, txPin);


LcdDisplay::LcdDisplay(){ 							// Default Constructor
	pinMode(txPin, OUTPUT);
	_pin = txPin;
	//LCD = SoftwareSerial(0, _pin);				// Initialize SoftwareSerial Object
	LCD.begin(LCD_BAUDRATE);
	
}

void LcdDisplay::selectLineOne(){  					// puts the cursor at line 0 char 0.
   LCD.write(LCD_COMMAND);   						// command flag
   LCD.write(128);    								// position
   delay(LCDdelay);
}
void LcdDisplay::selectLineTwo(){  					// puts the cursor at line 0 char 0.
   LCD.write(LCD_COMMAND);   						// command flag
   LCD.write(192);    								// position
   delay(LCDdelay);
}

void LcdDisplay::lcdPosition(int row, int col) {	// goto row & column
  LCD.write(LCD_COMMAND);   						// command flag
  LCD.write((col + row*64 + 128));    				// position 
  delay(LCDdelay);
}
void LcdDisplay::clearLCD(){
  LCD.write(LCD_COMMAND);   						// command flag
  LCD.write(LCD_CLEARDISPLAY); 						// clear command.
  delay(LCDdelay);
}
void LcdDisplay::backlightOn() {  					// turns on the backlight
  LCD.write(LCD_CTRLCOMMAND);   					// Control command flag
  LCD.write(157);    								// light level.
  delay(LCDdelay);
}
void LcdDisplay::backlightOff(){  					// turns off the backlight
  LCD.write(LCD_CTRLCOMMAND);   					// Control command flag
  LCD.write(128);     								// light level for off.
  delay(LCDdelay);
}

void LcdDisplay::writeToScreen(String s, int row, int col){   //a general function to write stuff to the screen
  lcdPosition(row, col);
  LCD.print(s);
}
void LcdDisplay::serCommand(){   					// a general function to call the command flag for issuing all other commands   
  LCD.write(LCD_COMMAND);
}

void LcdDisplay::writeText(String s){   			// a general function to call the command flag for issuing all other commands   
  LCD.print(s);
}

void LcdDisplay::setSplash(){						// Saves first 2 lines of txt to splash screen memory
	LCD.write(LCD_CTRLCOMMAND);						// Control command flag
	LCD.write(LCD_SETSPLASHSCREEN);
	delay(LCDdelay);
}

