/**
 * @file LC844_Backspace_String_Compare.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.2
 * @date 2023-08-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

// Takes a string with backspace chars and removes chars previous to backspace chars
std::string backspaceOutput(std::string s){
    std::string output;

    for (int i = 0; i < s.size(); i++){
        // if char != # then we add to string

        // if char == #, we remove last entry to string
    }

    std::cout << output << std::endl;
    return output;

}

bool backspaceCompare(std::string s, std::string t) {

    // Process both strings

    // compare outputs
    return (backspaceOutput(s) == backspaceOutput(t));
    
}


// Driver
int main(){

    std::string s = "ab#c";
    std::string t = "ad#c";


}