/**
 * @file LC219_Contains_Duplicate_II.cpp
 * @author Daniel Kaijzer
 * @brief Given an integer array nums and an integer k, 
 * return true if there are two distinct indices 
 * i and j in the array 
 * such that nums[i] == nums[j] 
 * and abs(i - j) <= k.

 * @version 0.1
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map<int,int> map1; // key: int val, value: index

    // iterate through array of numbers 'nums'
    for (int i = 0; i < nums.size(); i++){

        if (map1.count(nums[i]) > 0){ // if current value has appeared before

            // get distance between first index - current index
            int distance = abs(map1[nums[i]] - i);

            // if duplicates have distance <= k, return true
            if (distance <= k){ 
                return true;
            }
            // update first index to current index in case the value appears again
            map1[nums[i]] = i;
        }
        else{ // else if current value has not appeared before, add it to map

            // Initialize as follows:
                // Key: integer value
                // Value: first index that integer value appears at
            map1.insert(std::make_pair(nums[i],i));
        }
    }
    // if there were no duplicates with distance <= k, return false
    return false;
}

// Driver
int main(){
    std::vector<int> nums1 = {1,2,3,1};
    int k1 = 3;

    std::vector<int> nums2 = {1,0,1,1};
    int k2 = 1;

    std::vector<int> nums3 = {1,2,3,1,2,3};
    int k3 = 2;


    std::cout << "Example 1: \n";
    if (containsNearbyDuplicate(nums1,k1)){
        std::cout << "True\n" << std::endl;
    }
    else{
        std::cout << "False\n" << std::endl;
    }

    std::cout << "Example 2: \n";
    if (containsNearbyDuplicate(nums2,k2)){
        std::cout << "True\n" << std::endl;
    }
    else{
        std::cout << "False\n" << std::endl;
    }


    std::cout << "Example 3: \n";
    if (containsNearbyDuplicate(nums3,k3)){
        std::cout << "True\n" << std::endl;
    }
    else{
        std::cout << "False\n" << std::endl;
    }

    return 0;
}


// std::cout << "Pass " << i << 
// " has distance of " << distance << " for value " << nums[i] << 
// " because first Index for "<< i << " is " << map1[nums[i]] << std::endl;


// std::cout << "At " << i << " For int value " << nums[i] << " First index: " << map1[nums[i]] << std::endl;

// if value has occurred only once
// if (map1[nums[i]].second == 1){
// }
// if value as occurred more than once
// check distance between every occurrence

// if current value occurs more than twice in array, then we need to check distance between all indices for that value

// check if there are duplicate values
// map1.insert(std::make_pair(nums[i],std::make_pair(i,initial_count)));

// std::cout << "Pass: " << i << ", Value " << nums[i] << 
// " first appears at index " << map1[nums[i]].first << " and it has appeared " 
// << map1[nums[i]].second << " number of times " << std::endl;

// if (map1.count(nums[i]) > 0){
//     map1[nums[i]].second += 1;
// }
