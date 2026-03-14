# ByteWriter
This is an Arduino C code that makes it very easy to write numbers in binary. The code comes with an example.

# How to use

## Step 1: Declare the output byte.
As we can see in the code, there is a section that says `_8bit num;`. That section of code creates an object of type
_8bit. It contains all the pins to be used and the function for writing to them.

## Step 2: Declare the pins to be used.
As we can see in the code, the mode for each pin is first declared, and then stored in the list named “pins”
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
declared earlier. The `[The name of the byte declared earlier].printBYTE([8 bit data]);` function just takes the 8-bit
data and that's it, so that's all there is to it.

In my case, since I named my output byte ‘num’, I set it up as follows: `num.printBYTE(bitnum.n);`

## How it works.
If we look at the most important piece of code:
```
class _8bit {
  public:
    int pins[8]; // A list of size 8 is declared to store the pin numbers that will be used.
    void printBYTE(byte value) { // Function to write an 8-bit value in binary to the selected pins.
      for (int i = 0; i<8; i++) {
        digitalWrite(pins[i], bitRead(value, i)); // Writes the bit value to the selected pin.
      }
    }
};
```
There is a class called `_8bit`. Since it's a class, we can use as many bytes as we want.
### Line 7: `int pins[8];`
This class contains a list of type int that stores all eight pins so that the code knows which
ones to use to write the number/data in binary via the digital pins.

### Line 8-10: `void printBYTE(byte value)` function.
This is where most of the magic happens. The function takes a byte-type argument(`byte value`) because if we used an `int`, we wouldn't be able
to use data of any type other than `int`, which would severely limit us. So I decided this was the better approach, and it also helps
avoid problems.

### Line 9-11: `for` loop.
This piece of code is almost indispensable because it saves space and time, and eliminates the need to specify that a bit should be written to
each pin.

### Line 10: The most important line.
In this line, you can see that a `digitalWrite` is being performed. It specifies which pin is to be set to a value by looking it up in the list
mentioned earlier, and it reads the bit corresponding to that pin using `bitRead()`, which allows you to read a specific bit from a variable or
from a value entered directly.

### Line 17-19: Optional but important. (Trust me, read it just in case.)
As we can see in lines 17 through 19,

```
struct {
  unsigned int n : 8; // A variable with a size of 8 bits (or one byte) that is declared.
} byteNum;
```

there is a variable named ‘n,’ which is simply the name of the declared variable. I declare it this way because it’s the best method I’ve found for declaring a variable that uses exactly 8 bits. This is necessary if we want to avoid potential future problems, since this works with exactly 8 bits—no more, no less. But if you’re not going to use variables, then you don’t need to include this.
On line 19, the struct object named ‘byteNum’ is declared. You can name it whatever you like, since it's only used later to set `byteNum.n = 0;` and manipulate the variable. You can declare as many variables as you like, as shown in this example(But remember that 8 is the number of bits used for that variable, and I don't recommend changing it):
```
...

struct {
  unsigned int n1: 8;
  unsigned int n2: 8;
  unsigned int n3: 8;
  unsigned int n4: 8;
} byteNum;

void setup() {
  ...
  byteNum.n1 = 'A';
  byteNum.n2 = 0;
  byteNum.n3 = 0b10010001;
  byteNum.n4 = 0xFF;
}

void loop() {
  ...
}
```

Thanks for reading this, and I hope you find it useful. ;)
