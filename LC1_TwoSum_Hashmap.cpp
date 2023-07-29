/**
 * @file LC1_TwoSum_Hashmap.cpp
 * @author Daniel Kaijzer
 * @brief Given an array of integers 'nums' 
 * and integer 'target'
 * return the indices of the two numbers
 * such that they add up to 'target'
 * 
 * Assume that each input has exactly one solution
 * you may not use the same element twice.
 * 
 * @version 0.2
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {

    std::unordered_map<int,int> nums_map;

    // iterate through nums
    // store index and value in map if value isn't greater than target
    for (int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];

            // if complement exists in map, 
            // return the index of complement and current value
            if (nums_map.find(complement) != nums_map.end()){
                return {nums_map[complement],i}; // returns solution if it exists
            }

            nums_map.insert(std::make_pair(nums.at(i), i)); // add new values to map
    }
    return {}; // if solution doesn't exist, returns empty
}


// Driver
int main(){

    std::vector<int> nums1 = {2,7,11,15};
    std::vector<int> nums2 = {2,3,2};
    int target = 9;
    

    std::vector<int> output = twoSum(nums1, target);

    // print incides for twoSum

    std::cout << "\n[";

    for (int i = 0; i < output.size(); ++i){
        std::cout << output.at(i);
        if (output.size() > 1 && i < output.size()-1){
            std::cout << ", ";
        }
    }
    std::cout << "]"<< std::endl;

    return 0;
}