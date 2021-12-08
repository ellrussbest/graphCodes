#include <iostream>

using namespace std;

int main() {
    int value = 0x04030201; //32 bit number or 4 byte number
    
    /*
    for us to write an hexadecimal number in C++, then we have to start with
    0x
    and a binary number on the other hand, 
    0b
    */
    
    //extracting each Byte from value MSB to LSB
    int a = (value >> 24) & 0xff; //04 (bits 24 -1) MSB
    int b = (value >> 16) & 0xff; //03 (bits 16-23)
    int c = (value >> 8) & 0xff; //01 (bits 8 - 15)
    int d = value & 0xff; //01 (bits 0-7) LSB
    
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
  return 0;
}
