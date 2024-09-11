#include <iostream>
#include <map>
#include <string>
#include "Roman.h" 

int main() {
    // Creating objects of Roman class
    Roman roman1("XII");
    Roman roman2(1987);

    // Printing values
    roman1.printRoman();   // Output: Roman Numeral: XII
    roman1.printDec(); // Output: Integer Value: 12

    roman2.printRoman();   // Output: Roman Numeral: MCMLXXXVII
    roman2.printDec(); // Output: Integer Value: 1987

    //add runtest
    //Creating objects of Roman class
    Roman roman3("");
    Roman roman4(4044);
    Roman roman5(-3);

    //Printing Values
    roman3.printRoman(); 
    roman3.printDec();


    return 0;
}
