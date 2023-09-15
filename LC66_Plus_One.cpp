/**
 * @file LC66_Plus_One.cpp
 * @author Daniel Kaijzer
 * @brief convert array of digits into an int value,
 * incremement value by one
 * convert result int back into array of digits
 * @version 0.3
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

    // cout << val << endl;

    vector<int> output;
    // convert int value back into vector of digits

    int output_vector_size = digits.size(); // temp

    for (int i = 0; i < output_vector_size; ++i){
        double cur_power = output_vector_size+i-1; // adjust

        // cout << cur_power << endl;

        // adjust below
        double cur = val % (int)pow(10.0, cur_power); // 1,2,0

        cout << cur << endl;

        // output.push_back(cur);
    }


    

    return {};
}


int main(){
    vector<int> nums1{1,1,9}; // 1 is answer

    plusOne(nums1);
}
