/**
 * @file LC844_Backspace_String_Compare.cpp
 * @author Daniel Kaijzer
 * @brief 
 * 
 * idea: you can prob optimize using a stack
 * 
 * @version 1
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
        if (s[i] != '#'){
            output.push_back(s[i]);
        }

        // if char == #, we remove last entry to string
        if (s[i] == '#'){
            if (!output.empty()){
                output.pop_back();
            }
        }
    }
    // std::cout << output << std::endl;
    return output;
}

bool backspaceCompare(std::string s, std::string t) {
    // if strings are empty return true
    if (s.empty() && t.empty()){
        return true;
    }

    if (s.empty()){
        // check if if t output is empty
        return(backspaceOutput(t).empty());
    }

    if (t.empty()){
        // check if if s output is empty
        return(backspaceOutput(s).empty());
    }

    // process both strings and compare outputs
    return (backspaceOutput(s) == backspaceOutput(t));
}


// Driver
int main(){

    std::string s = "ab#c";
    std::string t = "ad#c";

    if (backspaceCompare(s,t)){
        std::cout << "TRUE\n";
    }
    else{
        std::cout << "FALSE\n";
    }

}