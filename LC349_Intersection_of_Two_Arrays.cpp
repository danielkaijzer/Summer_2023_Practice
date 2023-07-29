/**
 * @file LC349_Intersection_of_Two_Arrays.cpp
 * @author Daniel Kaijzer
 * @brief Uses the unordered_set STL container. 
 * Given two integer arrays nums1 and nums2,
 * return an array of their intersection. 
 * Each element in the result must be unique 
 * and you may return the result in any order.
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

// return elements common to both sets
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> result; 

    std::unordered_set<int> nums1_set; // initialize set to store unique values in nums1
    std::unordered_set<int> intersection; // initialize set to store values that exist in both nums1 and nums2

    // add nums1 to nums1_set
    for (int num : nums1){
        nums1_set.insert(num);
    }

    // iterate through nums2 and add all elements from nums1 that don't exist in nums2 to the set 'intersection'
    for (int num : nums2){
        if (nums1_set.count(num) > 0){
            intersection.insert(num);
        }
    }

    // add elements from set 'intersection' to vector 'result' for proper output
    for (auto it = intersection.begin(); it != intersection.end(); ++it){
        result.push_back(*it);
    }

    return result;
    
}

// Driver/testing program
int main(){
    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};

    std::vector<int> output = intersection(nums1, nums2);

    std::cout << "Output: " << std::endl;

    int index = 0;
    for (int num : output){
        index++;
        if (output.size() > 1 && index < output.size()){
            std::cout << num << ", ";
        }
        else{
            std::cout << num;
        }
    }
    std::cout << std::endl;

    return 0;

}
