/**
 * @file LC15_3Sum.cpp
 * @author Daniel Kaijzer
 * @brief Given an integer array nums, return all the triplets 
 * [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
 * and nums[i] + nums[j] + nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * @version v1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/*
ideas:
- brute force every combination with 3 nested loops
- iterate though hashmap with triple nested loop
- store every unique combination in hashmap of 2D vectors
- 

*/


vector<vector<int>> threeSumHelper(vector<int>& nums, unordered_map<int,int> hmp){

    vector<vector<int>> solution;

    
    for (int i = 0; i <nums.size()-2; i++){ // added -2 since we only look at cur value + next two
        if (nums[i] >0){ // no solution for all positive 3sum
            break;
        }

        for (int j = i + 1; j <nums.size()-1; ++j){
            int complement = -1*(nums[i] + nums[j]);

            // make sure complement (k value for solution) exists
            // if it does, make sure j value is last occurrence 
            // to avoid duplicate triplets
            if (hmp.find(complement) != hmp.end() && hmp.find(complement)->second > j){
                solution.push_back({{nums.at(i), nums.at(j), complement}});
            }
            // update j index to be last occurrence to avoid triplets
            j = hmp.find(nums[j])->second;
        }
        // update i index to be last occurrence to avoid triplets
        i = hmp.find(nums[i])->second;
    }

    return solution;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    // first sort vector
    sort(nums.begin(), nums.end());
    
    // we want to try all combinations of the numbers such that all three number indices are unique and they add up to 0.
    if (nums.size() == 3){
        if (nums.at(0) + nums.at(1) + nums.at(2) == 0){
            return {{nums.at(0), nums.at(1), nums.at(2)}};
        }
        return {};
    }
    else if (nums.size() < 3){ // no triplet solution if vector size < 3
        return {};
    }

    if (nums[0] > 0){ // if we have no zero or negatives, no solution
        return {};
    }

    // store numbers in a hashmap
    unordered_map<int,int> hmp;

    for (int i = 0; i < nums.size(); ++i){
        hmp[nums[i]] = i;
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