// Code written by Antonio Parra Strungariu (Pepoxtop).
// This example was written for the ESP8266, but it also works on other microcontrollers.
// Note: The comments have been translated because I'm not confident in my English skills, so there may be translation errors.

class _8bit {
  public:
    int pins[8]; // A list of size 8 is declared to store the pin numbers that will be used.
    void printBYTE(byte value) { // Function to write an 8-bit value in binary to the selected pins.
      for (int i = 0; i<8; i++) {
        digitalWrite(pins[i], bitRead(value, i)); // Writes the bit value to the selected pin.
      }
    }
};

_8bit num; // An object is created to store and execute functions for working with bytes.

struct {
  unsigned int n : 8; // A variable with a size of 8 bits (or one byte) that is declared.
} bitnum;

// Example This example shows how to generate a number by repeatedly adding 1 to it.-----

void setup() {
  // The pins are declared as OUTPUT.
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  // The pins to be used for each bit are specified.
  num.pins[0] = 16;
  num.pins[1] = 5;
  num.pins[2] = 4;
  num.pins[3] = 0;
  num.pins[4] = 14;
  num.pins[5] = 12;
  num.pins[6] = 13;
  num.pins[7] = 15;
  // An initial value of 0 is set.
  bitnum.n = 0;
}

void loop() {
  bitnum.n++;
  num.printBYTE(bitnum.n); // Function that writes the number in binary
  delay(500);
  /*
    Note: You don't need to represent the number in binary; it works with any 
    data type that uses 8 bits. This means you can even use ‘A’ or ‘B’, or enter
    numbers like 10 or 20 without converting them to binary.
  */
}

// --------------------------------------------------------------------------------------
