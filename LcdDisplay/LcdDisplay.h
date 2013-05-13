/*
	LcdDisplay.h -- Serial LCD Display Library for Arduino - Version 0.1
	
	Written for SDP (0.1) by Eric Moore
	
	Library to enable simple interface with Serial Enabled 16x2 LCD - Black on Green 3.3V
	https://www.sparkfun.com/products/9066

	Defines some basic functions to facilitate easy communication between the arduino and the LCD 

*/

#ifndef LcdDisplay_h
#define LcdDisplay_h

#include "Arduino.h"
#include <SoftwareSerial.h>

// Control Commands
#define LCD_COMMAND 		0xFE
#define LCD_CTRLCOMMAND		0x7C
// Commands
#define LCD_BACKLIGHT		0x80
#define LCD_CLEARDISPLAY	0x01
#define LCD_CURSORSHIFT		0x10
#define LCD_DISPLAYCONTROL	0x08
#define LCD_ENTRYMODESET	0x04
#define LCD_FUNCTIONSET		0x20
#define LCD_SETCGRAMADDR	0x40
#define LCD_SETDDRAMADDR	0x80
#define LCD_SETSPLASHSCREEN	0x0A
#define LCD_SPLASHTOGGLE	0x09
#define LCD_RETURNHOME		0x02

// Flags for display entry mode
#define LCD_ENTRYRIGHT		0x00
#define LCD_ENTRYLEFT		0x02

// Flags for choosing which line
#define LCD_LINEONE			0x80
#define LCD_LINETWO			0xC0

// Flags for display on/off control
#define LCD_BLINKON			0x01
#define LCD_CURSORON		0x02
#define LCD_DISPLAYON		0x04

// Flags for setting display size
#define LCD_SET2LINE		0x06
#define LCD_SET16CHAR		0x04

// LCD delay parameter
#define LCDdelay 			5

// LCD default pin
#define txPin 				2

// LCD Baud Rate
#define LCD_BAUDRATE		9600

// Use SoftwareSerial Object for communication with LCD screen
//SoftwareSerial LCD = SoftwareSerial(0, txPin);


class LcdDisplay
{
	public:
		LcdDisplay();
		//LcdDisplay(int pin);
		
		void selectLineOne();
		void selectLineTwo();
		void lcdPosition(int row, int col);
		
		void clearLCD();
		void backlightOn();
		void backlightOff();
		void writeToScreen(String s, int row, int col);
		void serCommand();
		void writeText(String s);
		void setSplash();
	private:
		int _pin;
};
#endif