/**
 * @file LC53_Max_Subarray.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.5
 * @date 2023-09-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_sum = nums[nums.size()-1], current_sum = 0;

    for (int i = 0; i < nums.size(); i++){
        current_sum += nums[i];

        if (current_sum > max_sum){
            max_sum = current_sum;
        }
        else if (current_sum < 0){
            current_sum = 0;
        }
        if (nums[i] > max_sum){
            max_sum = nums[i];
        }
    }

    return max_sum;
}


int main(){
    vector<int> nums1{-2,1,-3,4,-1,2,1,-5,4}; // 6 is answer

    cout << maxSubArray(nums1) << endl;
}
