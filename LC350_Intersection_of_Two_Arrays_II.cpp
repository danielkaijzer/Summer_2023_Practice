/**
 * @file LC350_Intersection_of_Two_Arrays_II
 * @author Daniel Kaijzer
 * @brief Given two integer arrays nums1 and nums2, 
 * return an array of their intersection. 
 * 
 * Each element in the result must appear as many times as it shows in both arrays 
 * and you may return the result in any order.
 * @version 0.1
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> intersection;

    // unordered maps for each vector containing the 1) value and 2) number of occurrences of value
    std::unordered_map<int,int> hmp1;
    std::unordered_map<int,int> hmp2;

    int count = 1; // initial count for occurrence of a value in vector

    // insert values into hmp1
    for (int i = 0; i < nums1.size(); i++){
        if (hmp1.count(nums1[i]) > 0){
            hmp1[nums1[i]] += 1;
        }
        else{
            hmp1.insert(std::make_pair(nums1[i], count));
        }
    }

    std::cout << "Map 1: " << std::endl;
    for (auto itr = hmp1.begin(); itr != hmp1.end(); ++itr){
        std::cout << itr->first << " | " << itr->second <<std::endl;
    }


    // insert values into hmp2
    for (int i = 0; i < nums2.size(); i++){
        if (hmp2.count(nums2[i]) > 0){ // if int value from vector has appeared before
            // std::cout << count << std::endl;
            hmp2[nums2[i]] += 1;  // increase occurence count for that value
        }
        else{
            hmp2.insert(std::make_pair(nums2[i], count));
        }
    }

    std::cout << "\nMap 2: " << std::endl;
    for (auto itr = hmp2.begin(); itr != hmp2.end(); ++itr){
        std::cout << itr->first << " | " << itr->second <<std::endl;
    }

    int cur_value;

    // iterate through hmp2
    // add elements common to hmp1 and hmp2
    // the number of times each element appears in both
    for (auto itr = hmp2.begin(); itr != hmp2.end(); ++itr){
        cur_value = itr->first;

        if (hmp1.count(cur_value) > 0){ // if current element in hmp2 appears in hmp1
            // then add this element to output vector the number of times it appears in both maps

            // if element appears more in hmp1, add it the amount of times it appears in hmp2
            if (hmp1[cur_value] > hmp2[cur_value]){ 
                for (int i = 0; i < itr->second; i++){
                    intersection.push_back(itr->first);
                }
            }
            else{
                for (int i = 0; i < hmp1[itr->first]; i++){
                    intersection.push_back(itr->first);
                }
            }
        }
    }

    return intersection;
}

// Driver
int main(){
    std::vector<int> nums1 = {3,1,2};
    std::vector<int> nums2 = {1,1};

    // std::vector<int> nums1 = {1,2,2,1};
    // std::vector<int> nums2 = {2};

    std::vector<int> output = intersect(nums1,nums2); 


    // Print intersection
    std::cout << "Intersection: [";
    int index=0;
    for (int i : output){
        std::cout << i;
        if (index < output.size()-1){
            std::cout << ",";
        }
        index++;
    }
    std::cout << "]" << std::endl;

    return 0;
}