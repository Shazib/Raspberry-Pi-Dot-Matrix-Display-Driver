// All credit to KaR]V[aN for the font array

#include <wiringPi.h> //For comtrolling pins
#include <wiringShift.h> // For sending bytes via serial
#include <iostream> // Standard C++ library
#include <ctime> // For time and date in printDate method

using namespace std;

// Font Array
int font[95][5] = {
{0x00,0x00,0x00,0x00,0x00}, //  
{0x00,0x00,0x7a,0x00,0x00}, // !
{0x00,0x70,0x00,0x70,0x00}, // "
{0x14,0x3e,0x14,0x3e,0x14}, // #
{0x10,0x2a,0x3e,0x2a,0x04}, // $
{0x64,0x08,0x10,0x26,0x00}, // %
{0x14,0x2a,0x14,0x02,0x00}, // &
{0x00,0x00,0x70,0x00,0x00}, // '
{0x00,0x3c,0x42,0x00,0x00}, // (
{0x00,0x42,0x3c,0x00,0x00}, // )
{0x00,0x2a,0x1c,0x2a,0x00}, // *
{0x08,0x08,0x3e,0x08,0x08}, // +
{0x00,0x01,0x06,0x04,0x00}, // ,
{0x08,0x08,0x08,0x08,0x00}, // -
{0x00,0x06,0x06,0x00,0x00}, // .
{0x04,0x08,0x10,0x20,0x00}, // /
{0x00,0x3c,0x42,0x3c,0x00}, // 0
{0x00,0x22,0x7e,0x02,0x00}, // 1
{0x22,0x46,0x4a,0x32,0x00}, // 2
{0x44,0x52,0x52,0x6c,0x00}, // 3
{0x18,0x28,0x7e,0x08,0x00}, // 4
{0x74,0x52,0x52,0x4c,0x00}, // 5
{0x3c,0x52,0x52,0x0c,0x00}, // 6
{0x40,0x46,0x58,0x60,0x00}, // 7
{0x2c,0x52,0x52,0x2c,0x00}, // 8
{0x30,0x4a,0x4a,0x3c,0x00}, // 9
{0x00,0x36,0x36,0x00,0x00}, // :
{0x01,0x36,0x34,0x00,0x00}, // ;
{0x00,0x08,0x14,0x22,0x00}, // <
{0x14,0x14,0x14,0x14,0x00}, // =
{0x00,0x22,0x14,0x08,0x00}, // >
{0x00,0x20,0x4a,0x30,0x00}, // ?
{0x3c,0x42,0x5a,0x38,0x00}, // @
{0x3e,0x48,0x48,0x3e,0x00}, // A
{0x7e,0x52,0x52,0x2c,0x00}, // B
{0x3c,0x42,0x42,0x24,0x00}, // C
{0x7e,0x42,0x42,0x3c,0x00}, // D
{0x7e,0x52,0x52,0x42,0x00}, // E
{0x7e,0x50,0x50,0x40,0x00}, // F
{0x3c,0x42,0x4a,0x2e,0x00}, // G
{0x7e,0x10,0x10,0x7e,0x00}, // H
{0x00,0x42,0x7e,0x42,0x00}, // I
{0x04,0x02,0x02,0x7c,0x00}, // J
{0x7e,0x18,0x24,0x42,0x00}, // K
{0x7e,0x02,0x02,0x02,0x00}, // L
{0x7e,0x30,0x30,0x7e,0x00}, // M
{0x7e,0x30,0x0c,0x7e,0x00}, // N
{0x3c,0x42,0x42,0x3c,0x00}, // O
{0x7e,0x48,0x48,0x30,0x00}, // P
{0x3c,0x46,0x42,0x3d,0x00}, // Q
{0x7e,0x48,0x4c,0x32,0x00}, // R
{0x24,0x52,0x4a,0x24,0x00}, // S
{0x00,0x40,0x7e,0x40,0x00}, // T
{0x7c,0x02,0x02,0x7c,0x00}, // U
{0x78,0x06,0x06,0x78,0x00}, // V
{0x7e,0x0c,0x0c,0x7e,0x00}, // W
{0x66,0x18,0x18,0x66,0x00}, // X
{0x00,0x70,0x0e,0x70,0x00}, // Y
{0x46,0x4a,0x52,0x62,0x00}, // Z
{0x00,0x7e,0x42,0x42,0x00}, // [
{0x20,0x10,0x08,0x04,0x00}, // "\"
{0x00,0x42,0x42,0x7e,0x00}, // ]
{0x00,0x20,0x40,0x20,0x00}, // ^
{0x02,0x02,0x02,0x02,0x00}, // _
{0x00,0x40,0x20,0x00,0x00}, // `
{0x0c,0x12,0x14,0x1e,0x00}, // a
{0x7e,0x12,0x12,0x0c,0x00}, // b
{0x0c,0x12,0x12,0x00,0x00}, // c
{0x0c,0x12,0x12,0x7e,0x00}, // d
{0x0c,0x16,0x1a,0x08,0x00}, // e
{0x08,0x3e,0x48,0x20,0x00}, // f
{0x0a,0x15,0x15,0x19,0x00}, // g
{0x7e,0x10,0x10,0x0e,0x00}, // h
{0x00,0x12,0x5e,0x02,0x00}, // i
{0x00,0x02,0x01,0x5e,0x00}, // j
{0x7e,0x08,0x14,0x02,0x00}, // k
{0x00,0x42,0x7e,0x02,0x00}, // l
{0x1e,0x08,0x18,0x0e,0x00}, // m
{0x1e,0x10,0x10,0x0e,0x00}, // n
{0x0c,0x12,0x12,0x0c,0x00}, // o
{0x1f,0x12,0x12,0x0c,0x00}, // p
{0x0c,0x12,0x12,0x1f,0x00}, // q
{0x1e,0x10,0x10,0x08,0x00}, // r
{0x0a,0x1a,0x16,0x14,0x00}, // s
{0x10,0x7c,0x12,0x02,0x00}, // t
{0x1c,0x02,0x02,0x1e,0x00}, // u
{0x00,0x1c,0x02,0x1c,0x00}, // v
{0x1e,0x06,0x06,0x1e,0x00}, // w
{0x12,0x0c,0x0c,0x12,0x00}, // x
{0x18,0x05,0x02,0x1c,0x00}, // y
{0x12,0x16,0x1a,0x12,0x00}, // z
{0x00,0x10,0x3c,0x42,0x00}, // {
{0x00,0x00,0x7e,0x00,0x00}, // |
{0x00,0x42,0x3c,0x10,0x00}, // }
{0x20,0x40,0x20,0x40,0x00}, // ~
};

/*Global Variables*/
//Pin Assignment
int chipEnable;
int resetPin;
int clockPin;
int dataPin;
int registerSelect;
int SEL;
//Program Variables
int cursorPos = 0; // Keeps track of which byte was last written to display
int displayLength; // Length of display, should be one of(4,8,12)
string inputString; // String that stores what is printing
int dotRegister[160]; // Array which stores the values (in bytes) to be sent to the screen

/*
 * Method to assign initial global variables.
 * You ned to pass numbers for the Data Pin, Register Select Pin, 
 * Clock Pin, Reset Pin, Select Pin, and the length of the display (4, 8, 12)
 */

static void InitialiseGpio(	int _dataPin, 
							int _registerSelect, 
							int _clockPin, 
							int _chipEnable, 
							int _resetPin, 
							int _selPin,
							int _displayLength) {
	dataPin = _dataPin;       
	registerSelect = _registerSelect;   	
	clockPin = _clockPin;        			
	chipEnable = _chipEnable;       		
	resetPin = _resetPin;         		
	displayLength = _displayLength;  
	cursorPos = 0; //Method also assigns the default value of 0 to cursor Position
	
}

/* 
 * Method to prepare the GPIO's, initialises WiringPi library,
 * sets default values, and resets the screen.
 */
static void begin () {
	// Prepare wiringPi
	wiringPiSetupGpio();
	
    // Set pin modes.  
    pinMode(resetPin, OUTPUT); 
    pinMode(SEL, OUTPUT); 
    pinMode(chipEnable, OUTPUT); 
    pinMode(clockPin, OUTPUT); 
    pinMode(dataPin, OUTPUT); 
    pinMode(registerSelect, OUTPUT);   
  
    // Set default values
    digitalWrite(SEL, HIGH);
    digitalWrite(chipEnable, HIGH);
    digitalWrite(registerSelect, LOW);
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, LOW);
    delay(10);

	// Reset
	digitalWrite(resetPin, LOW);
    delay(10);
    digitalWrite(resetPin, HIGH);
    delay(10);
}

/*
 * Method to clear the dotRegister array
 * Calculates max length based on displayLength and assigns value of 0.
 */
static void clear () {
	int maxData = displayLength * 5; // Calculate Max Data

	for (int i =0; i < maxData; i++ )
	{
		dotRegister[i] = 0; // Assign 0 for all bytes.
	}
	
}

/* 
 * Method to write a byte to the control registers
 * Writes a user defined byte.
 */
void loadControlRegister(int dataByte ) { 
  // Format 0bXXXXXXXX is easiest in relation to the datasheet
  // 0b01111111 wil set for max brightness.
  
  // Select the control registers:
  digitalWrite(registerSelect, HIGH);
  // Enable writing to the display:
  digitalWrite(chipEnable, LOW);
  // Shift the data out:
  shiftOut(dataPin, clockPin, MSBFIRST, dataByte);
  // Disable writing:
  digitalWrite(chipEnable, HIGH);
}

/* 
 * Method to load contents of dot register array onto screen
 * loads a byte at a time based on the dotRegister[]
 * Will only load as much as the screen can fit.. i.e. 20 bytes for a 4 character etc.
 */
void loadDotRegister() {

  // Calculate maximum data that is supported.
  int maxData = displayLength * 5;

  // Select the dot register:
  digitalWrite(registerSelect, LOW);
  // Enable writing to the display:
  digitalWrite(chipEnable, LOW);
  // Shift the data out
  for (int i = 0; i < maxData; i++) {
	// LSBFIRST can be alternated to MSBFIRST for writing upside down/right way round.
	// Least significant bit / Most significant bit.
    shiftOut(dataPin, clockPin, LSBFIRST, dotRegister[i]); 
  }
  // disable writing:
  digitalWrite(chipEnable, HIGH);
}

/* 
 * Method to write an individual character to the display
 * Does not communicate with the screen, only assigns bytes to the dot register.
 * Writes 5 bytes for the character, taken from the font array.
 * Increments cursor position each byte.
 */
void writeCharacter (char character, int _cursorPos) {
	
	for (int i = 0; i < 5; i++) {// For 5 bytes
		// Write a byte to the specified cursor position
		dotRegister[_cursorPos] = font[character-32][i];
		// Increment cursor position ready for next byte
		_cursorPos++;
	}
	cursorPos = _cursorPos; // Now assign new cursor positon ready for next character
	// Overwrite previous bytes if over max length of screen
	int maxData = displayLength * 5;
	if (cursorPos >= maxData) //////
		{cursorPos = 0;}  /////
}

/* 
 * Method to write a whole string to the dotRegister
 * does not communicate with the screen
 * Loops writeCharacter() method.
 * Sets cursor to home first.
 */
void writeString (string _inputString) {
	// Work out string length
	int stringLength = _inputString.length();
	for (int i = 0; i < stringLength; i++) { // For each character
			// Write the character
			writeCharacter(_inputString[i], cursorPos);
        }
	inputString = _inputString; //assign the string
}

/* 
 * Method to scroll text across the display, right to left.
 * Needs to be passed a value for brightness (1-15) and speed in milliseconds.
 * This method runs lower level methods automatically.
 * Example: scroll("Test string one", 15, 700)
 * Note, this method runs forever. a constant loop
 */
void scroll(string _inputString, int _brightness, int _speed) {
	begin(); // Initialise 
	clear(); // Clear dotRegister to blank screen
	loadDotRegister(); // Print blank screen
	// Use brightness value to calculate complete byte for control register.
	int controlByte = 0b01110000 + _brightness;
	loadControlRegister(controlByte); // Load byte to control registers
	cursorPos = 0; //Assign default cursor position
	string printString = "   " + _inputString + "   "; // Add blank values for visually accutate scroll
	int stringLength = printString.length(); // Calculate string length
	while (true){	// forever
		for (int i = 0; i < stringLength-3; i++){
		// Write first four characters, then increment by one and write...till end of string
			writeCharacter(printString[i], cursorPos);
			writeCharacter(printString[i+1], cursorPos);
			writeCharacter(printString[i+2], cursorPos);
			writeCharacter(printString[i+3], cursorPos);
			loadDotRegister();//print to screen
			cursorPos = 0;
			delay(_speed);
		}
	}
}

/* 
 * This method uses scroll(); to scroll the current date
 * Currently formatted for GMT/UTC time.
 * Default format "Tue 26th Mar 22:22:22 2013"
 */
void scrollDate (int _brightness, int _speed){
	while (true){	//forever
		// Work out current time
		// assign to string
		time_t now = time(0);
		tm* gmtm = gmtime(&now);
		string temp = asctime(gmtm);
		string timeString = temp.substr(0,24);
		cout << timeString << endl;
		//Scroll timeString
		scroll(timeString, _brightness, _speed);
		}	
}


/* 
 * Method to write string to screen
 * does all initialisaation, writes a string to dotRegister then outputs it.
 * Requires brightness input 0-15, 0=0% 15=100%
 * Resets cursor postion at end so it can be run multiple times.
 */
void write(string _inputString, int _brightness) {
	// Prepare GPIO, and blank the screen
	begin();
	clear();
	loadDotRegister();
	// Load control witrh custom brightness
	int controlByte = 0b01110000 + _brightness;
	loadControlRegister(controlByte);
	// call writeString
	writeString(_inputString);
	// Output to screen
	loadDotRegister();
	// Reset cursor
	cursorPos = 0;
}



/*
 * TESTING
 */

int main (void) {
InitialiseGpio(22,17,4,11,10,9,4);

scrollDate(15,500);
}


