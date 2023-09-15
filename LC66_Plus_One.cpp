/**
 * @file LC66_Plus_One.cpp
 * @author Daniel Kaijzer
 * @brief convert array of digits into an int value,
 * incremement value by one
 * convert result int back into array of digits
 * @version 0.5
 * @date 2023-09-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int val = 0;

    // convert vector of digits into an int value
    for (int i = 0; i < digits.size(); ++i){
        double cur_power = digits.size()-i-1;
        val += digits.at(i) * (int)pow(10.0, cur_power);
    }

    // increment int value by 1
    val += 1;

    vector<int> output;

    // convert output to string
    std::string output_string = std::to_string(val);

    for (char c : output_string){
        // convert char to int and add to vector
        output.push_back(c-'0');
    }

    return output;
}


int main(){
    vector<int> nums1{1,1,9}; // 1 is answer

    plusOne(nums1);
}
