/**
 * @file LC217_Contains_Duplicate.cpp
 * @author Daniel Kaijzer
 * @brief Uses the unordered_set STL container to check for duplicate values in arrays of integers
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

    // every element appears twice except for one.
    // Find that single one.
int singleNumber(std::vector<int>& nums){
    // Initialize an unordered set
    std::unordered_set<int> set;

    std::unordered_set<int> duplicates;


    // add all numbers to set
    for (int num : nums){
        if (set.count(num) > 0){
            duplicates.insert(num);
        }
        set.insert(num);
    }

    for (auto it = set.begin(); it != set.end(); ++it){
        if (duplicates.count(*it) == 0){
            return *it;
        }
    }

    return -1;
}

// Driver/testing program
int main(){
    std::vector<int> nums1 = {2,2,1};
    std::vector<int> nums2 = {4,1,2,1,2};
    std::vector<int> nums3 = {1};

    std::cout << singleNumber(nums1) << std::endl; // 1
    std::cout << singleNumber(nums2) << std::endl; // 4
    std::cout << singleNumber(nums3) << std::endl; // 1

    return 0;

}
