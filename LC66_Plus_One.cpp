/**
 * @file LC66_Plus_One.cpp
 * @author Daniel Kaijzer
 * @brief convert array of digits into an int value,
 * incremement value by one
 * convert result int back into array of digits
 * @version 0.6
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    short int i = digits.size()-1;

    if (i>=0){ // if digits has a size
        while (i != -1){ // iterate through digits backwards from end
            digits[i] += 1;

            if (i == 0 && digits[i] == 10){ // if 
                digits[i] = 0;
                digits.insert(digits.begin(),1); // add leading 1
            }
            else if (digits[i] ==10){
                digits[i] = 0;
                // in this scenario, you will continue the loop
                // and go to next value and add 1 
            }
            else break; // if after adding 1, digit != 10, break
            i--;
        }
    }

    return digits;
}


int main(){
    vector<int> nums1{1,1,9}; // 1 is answer

    plusOne(nums1);
}
