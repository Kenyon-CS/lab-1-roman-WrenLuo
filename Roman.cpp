#include "Roman.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Roman {
    
    std::string romanNumeral;  
    int integerValue; 

    //Default Constructor
    Roman::Roman(){
        romanNumeral = "";
        integerValue = 0;
    }

    // Constructor to initialize with an integer
    Roman::Roman(int value){
        integerValue = value;
    }

    // Constructor to initialize with a Roman numeral string
    Roman::Roman(const std::string& numeral){
        romanNumeral = numeral;
    }
    

    int Roman::romanToInt(const std::string& numeral){
        std::unordered_map<char, int> RomNumtoInt={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        for (int i=0; i<numeral.length(); i++){
            if(i<(numeral.length()-1) && RomNumtoInt[numeral[i]]<RomNumtoInt[numeral[i+1]]){
                integerValue-=RomNumtoInt[numeral[i]];
            }
            else{
                integerValue += RomNumtoInt[numeral[i]];
            }
        }
            return integerValue; 
    }

        
    

    std::string Roman::intToRoman(int value){
        if(value <= 0 || value >=4000){
            //check if the integer input is out of range
            std::cout <<"Invalid Integer. The Integer inputed must between 0 and 3999." << std::endl; 
        }
        else { 
            // start converting is it's in the range.
            //check the input interger belongs to which range. 
            
           int tempPiece; //temporarily store devided value for converting to corrosponding numeral number. 
            
            //roman numeral for thousands
            if (value >= 1000){
                tempPiece = (value/1000);
                
                for(int i = 0; i < tempPiece; i++){
                    romanNumeral += "M"; 
                }
               value %= 1000;

            }
            //roman numeral for hundreds
            if (value >= 100)
            {
                tempPiece = (value/100);

                if (tempPiece == 9) {
                    romanNumeral += "CM";
                }
                else if(tempPiece >= 5){
                    romanNumeral += "D";
                    for (int i=0; i < tempPiece - 5; i++){
                        romanNumeral += "C";
                    }
                }
                else if(tempPiece == 4){
                    romanNumeral += "CD";
                }
                else if(tempPiece >= 1){
                    for (int i=0; i < tempPiece; i++){
                        romanNumeral += "C";
                    }
                }

                value %= 100;
            }

            //roman numeral for tens
            if (value > 10){
                tempPiece = (value/10);

                if (tempPiece == 9) {
                    romanNumeral += "XC";
                }
                else if(tempPiece >= 5){
                    romanNumeral += "L";
                    for (int i=0; i < tempPiece - 5; i++){
                        romanNumeral += "X";
                    }
                }
                else if(tempPiece == 4){
                    romanNumeral += "XL";
                }
                else if(tempPiece >= 1){
                    for (int i=0; i < tempPiece; i++){
                        romanNumeral += "X";
                    }
                }
                value %= 10;
            }

            //roman numeral for units
            if (value > 1){
                tempPiece = value;

                if (tempPiece == 9) {
                    romanNumeral += "IX";
                }
                else if(tempPiece >= 5){
                    romanNumeral += "V";
                    for (int i=0; i < tempPiece - 5; i++){
                        romanNumeral += "I";
                    }
                }
                else if(tempPiece == 4){
                    romanNumeral += "IV";
                }
                else if(tempPiece >= 1){
                    for (int i=0; i < tempPiece; i++){
                        romanNumeral += "I";
                    }
                }
            }

        }
        return romanNumeral; 
    }


    //Getter for the integer value
    int Roman::getInt() const{
        return integerValue;
    }

    //Getter for the Roman numeral string
    std::string Roman::getRoman() const{
        return romanNumeral;
    }

    // Function to print the integer value
    void Roman::printDec() const{
        std::cout << integerValue << std::endl;
    }
    // Function to print the Roman numeral
    void Roman::printRoman() const{
        std::cout<< romanNumeral <<std::endl;
    }

    


};
