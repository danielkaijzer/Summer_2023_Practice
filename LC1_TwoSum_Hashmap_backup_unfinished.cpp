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
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result;

    std::unordered_map<int,int> nums_map;

    // iterate through nums
    // store index and value in map if value isn't greater than target
    for (int i = 0; i < nums.size(); ++i){
        if (nums.at(i) <= target){
            nums_map.insert(std::make_pair(nums.at(i),i));
            // std::cout << nums.at(i) << std::endl;
        }
    }

    // iterate through hashmap
    for (auto pair : nums_map){
        // check if target - current val is in hashmap
        int check_val = target - pair.first;
        std::cout << "key: " << pair.second << " | value: "<< pair.first << " | Check_val: " << check_val << std::endl;

        // check if check_val exists at any index
        // AND if the difference doesn't only exist for value at current index



        // if target - current value exists in map
        if (nums_map.count(check_val) > 0){ 
            // AND if the difference doesn't only exist for value at current index
            if (!(check_val == pair.first && nums_map.count(check_val) == 1)){
                result.push_back(pair.first); // add to vector storing indices
            }
        }
    }

    // if vector size is not 2, result is invalid
    // if (result.size() != 2){
    //     // return empty vector
    //     result.clear();
    //     return result;
    // }
    // else result is valid
    return result; // return solution
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