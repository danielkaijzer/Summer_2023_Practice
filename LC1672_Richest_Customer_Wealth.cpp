/**
 * @file LC1672_Richest_Customer_Wealth.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-08-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

int sumHelper(std::vector<int>& nums, int begin, int end, int sum){
    if (begin > end){
        return sum;
    }
    sum+= nums.at(begin);
    return sumHelper(nums, begin+1, end, sum);
}

int sum(std::vector<int>& nums){
    return sumHelper(nums, 0, nums.size()-1, 0);
}

int maximumWealth(std::vector<std::vector<int>>& accounts) {
    int max = 0;
    for (int i = 0; i < accounts.size(); i++){
        max = std::max(max,sum(accounts.at(i)));
    }
    return max;
}


// Driver
int main(){
    std::vector<std::vector<int>> accounts = {{1,5}, {7,3}, {3,5}};

    std::cout << maximumWealth(accounts) << std::endl;
}