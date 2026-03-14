# ByteWriter
This is an Arduino C code that makes it very easy to write numbers in binary. The code comes with an example.

# How to use

## Step 1: Declare the output byte.
As we can see in the code, there is a section that says `_8bit num;`. That section of code creates an object of type
_8bit. It contains all the pins to be used and the function for writing to them.

## Step 2: Declare the pins to be used.
As we can see in the code, the mode for each pin is first declared, and then stored in the list named “num”
(previously declared), which has 8 slots for storing the number of each pin. (I used these because they worked best 
for me with my ESP8266.)
```
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
```

## Optional: Declare a variable.
As we can see in this:
```
struct {
  unsigned int n : 8; // A variable with a size of 8 bits (or one byte) that is declared.
} bitnum;
```
snippet, a variable is declared that is unnecessary if you are going to insert the 8-bit
number or value directly.

And when you're working with it, you should type something like `byteNum.[Variable name] = [Inserted value];`. In my case, since
the variable is called ‘n’, I typed `byteNum.n = 0;`.

## Final step: Write the byte.
To finally display it, send it, or do whatever you want with it, you call the function located in the byte named ‘num’ that we
declared earlier. The `[The name of the byte declared earlier].printBYTE([8 bit data]);` function just takes the 8-bit data and that's it, so that's all there is to it.

In my case, since I named my output byte ‘num’, I set it up as follows: `num.printBYTE(bitnum.n);`

Thanks for reading this, and I hope you find it useful. ;)
