/**
 * @file LC482_License_Key_Format.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 3
 * @date 2023-08-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// What I need to fix: 
// Prioritize splitting all alphanum groups into parts with k chars each

// rules:
// all groups after first group must be of length k, first group can be less than k
// step 1: from tail to head break string into groups of k
// 

#include <iostream>
#include <unordered_map>

using namespace std;

string licenseKeyFormatting(string s, int k) {

    string output;

    int i = 0;

    // check alphanum count to determine whether to skip first dash
    int alphanum_count =0;
    for (char c: s){
        if (c != '-'){
            alphanum_count++;
        }
    }

    // if no alphanum chars, return empty string
    if (alphanum_count == 0){
        return "";
    }
    
    int remainder = alphanum_count%k;
    int alpha_num_index =0;
    if (remainder != 0){
        cout << "CHECK\n";
        while(alpha_num_index != remainder){ // for index up to remainder-1, add chars and first dash
            if (s[i] != '-'){
                // make sure all alpha chars added are uppercase
                if (s[i] >= 'a' && s[i] <= 'z'){
                    output.push_back(s[i]-32);
                }
                else{
                    output.push_back(s[i]);
                }
                alpha_num_index++;
            }
            i++;
        }
        // add first '-'
        output.push_back('-');
    }


    int dash_index = 1;
    // add in rest of chars but add '-' after every k chars
    // make all lower case chars uppercase
    while (s[i] != '\0'){
        if (s[i] != '-'){ // don't add dashes from original string

            // make sure all alpha chars added are uppercase
            if (s[i] >= 'a' && s[i] <= 'z'){
                output.push_back(s[i]-32);
            }
            else{
                output.push_back(s[i]);
            }
            
            if (dash_index%k == 0){ // add '-' after every k chars
                output.push_back('-');
            }
            dash_index++; // only iterate index for non '-' chars
        }
        i++;
    }

    // remove '-' added to end if there is one
    if (output[output.size()-1] == '-'){
        output.pop_back();
    }
    return output;
}

int main(){

// int key = 4;
string s1 = "5F3Z-2e-9-w"; 
string s2 = "2-5G-3J"; // since 
string s3 = "2-4A0r7-4k"; // since there are 8 alphanum chars, where k=4, ignore first dash
string s4 = "---";


// cout << licenseKeyFormatting(s1, 4) << endl; // "5F3Z-2E9W"
// cout << licenseKeyFormatting(s2, 2) << endl; // "2-5G-3J"
// cout << licenseKeyFormatting(s3, 4) << endl; // "24A0-R74K"
// cout << licenseKeyFormatting(s3, 3) << endl; // "24-A0R-74K"
cout << licenseKeyFormatting(s4,3) << endl; // "AA-AA"

}
