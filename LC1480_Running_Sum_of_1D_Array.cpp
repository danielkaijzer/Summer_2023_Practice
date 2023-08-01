/**
 * @file LC1480_Running_Sum_of_1D_Array.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.2
 * @date 2023-08-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>


void runningSumHelper(std::vector<int>& nums, int begin, int end, int sum, std::vector<int>& output){
    if (begin > end){     // Base case
        return;
    }

    sum += nums.at(begin);
    output.push_back(sum);

    runningSumHelper(nums,begin+1, end, sum, output);    // recursive step
}

std::vector<int> runningSum(std::vector<int>& nums) {
    std::vector<int> output;
    runningSumHelper(nums, 0, nums.size()-1, 0, output);
    return output;
}


// Driver
int main(){

    std::vector<int> nums = {1,1,1,1};
    std::vector<int> output = runningSum(nums);

    for (int i = 0; i < output.size(); i++){
        std::cout << output.at(i)<< std::endl;
    }
}