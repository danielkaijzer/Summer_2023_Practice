/**
 * @file LC852_Peak_Index_in_a_Mountain_Array.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 1
 * @date 2023-09-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    if (arr.size() < 3){
        return -1;
    }

    for (int i = 1; i < arr.size()-1; ++i){
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            return i;
        }
    }
    return -1;


}


int main(){
    vector<int> nums1{0,1,0}; // 1 is answer

    cout << peakIndexInMountainArray(nums1) << endl;
}
