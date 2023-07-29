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

bool containsDuplicate(std::vector<int>& nums){
    // Initialize an unordered set
    std::unordered_set<int> set;

    // Iterate through array
    for (int num : nums){
        // If value has appeared before, return true
        if (set.count(num) > 0){ 
            return true;
        }
        // Else add unique value to set container
        set.insert(num);
    }
    // If we have iterated through all values in the array
    // And have not encountered duplicates
    return false;

}


// Driver/testing program
int main(){
    std::vector<int> nums1 = {1,2,3,1};
    std::vector<int> nums2 = {1,2,3,4};
    std::vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};

    std::cout << containsDuplicate(nums1) << std::endl;
    std::cout << containsDuplicate(nums2) << std::endl;
    std::cout << containsDuplicate(nums3) << std::endl;


    return 0;

}
