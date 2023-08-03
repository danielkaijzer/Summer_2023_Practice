/**
 * @file LC15_3Sum.cpp
 * @author Daniel Kaijzer
 * @brief Given an integer array nums, return all the triplets 
 * [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
 * and nums[i] + nums[j] + nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> threeSumHelper(vector<int>& nums, unordered_map<int,int> hmp){

    vector<vector<int>> output = {{}};

    for (int i = 0; i <nums.size(); i++){
        for (int j = i + 1; j <nums.size(); j++){
            int current_2sum = nums[i] + nums[j];
            int complement = 0 - current_2sum;

            if (hmp.find(complement) != hmp.end()){
                // if triplet exists, add it to output 2D vector of ints
                output.push_back({nums[i],nums[j],complement});
            }
        }
    }

    return output;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    // we want to try all combinations of the numbers such that all three number indices are unique and they add up to 0.
    if (nums.size() ==3){
        if (nums.at(0) + nums.at(1) + nums.at(2) == 0){
            return {{nums.at(0), nums.at(1), nums.at(2)}};
        }
        return {{}};
    }

    // store numbers in a hashmap
    unordered_map<int,int> hmp;

    for (int i=0;i<nums.size();i++){
        hmp[i] = nums.at(i);
    }

    return threeSumHelper(nums,hmp);
}

int main(){
    vector<int> input = {-1,0,1,2,-1,-4};
    // vector<int> input = {0,0,1};

    vector<vector<int>> output = threeSum(input);

    for (auto itr = output.begin(); itr != output.end(); itr++){
        for (int i = 0; i< itr->size(); i++){
            cout << itr->at(i) << " ";
        }
        cout << endl;
    }

}