/**
 * @file LC2325_Decode_Message.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 1
 * @date 2023-08-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_map>

using namespace std;


/*
ideas:
- store all unique chars in a hashmap for key
- align substitution table with regular english alphabet
- everytime you encounter a new char, map next alphabet ASCII value to it, iterate alphabet

*/



string decodeMessage(string key, string message) {

    // store all unique chars in a hashmap for key
    unordered_map<char,char> hmp;
    hmp[' '] = ' '; // space chars remain unchanged
    int itr=0; // iterator for alphabet mapping

    for (char c : key){
        if (hmp.find(c) == hmp.end() && c <= 'z' && c >= 'a'){
            hmp[c] = 'a' + itr;
            itr++;
        }
    }

    // Decode message
    string decodedMessage;
    for (char c : message){
        decodedMessage.push_back(hmp[c]);
    }

    return decodedMessage;
}

int main(){

string key = "the quick brown fox jumps over the lazy dog";
string message = "vkbs bs t suepuv";

cout << decodeMessage(key,message) << endl;

}
