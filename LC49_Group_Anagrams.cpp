/**
 * @file LC49_Group_Anagrams.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

void printGroupedStrings(std::vector<std::vector<std::string>> groupedStrs) {
  for (auto group : groupedStrs) {
    for (std::string string : group) {
      std::cout << string << " ";
    }
    std::cout <<std::endl;
  }
}


// function to sort string
std::string sortString(std::string s){
    sort(s.begin(), s.end());
    return s;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    
    std::vector<std::vector<std::string>> groupedStrs;  

    int group_count = 0;

    std::unordered_map<std::string, std::vector<std::string>> hashmap;
    // Key: Sorted string
    // Value: A vector of associated strings

    // iterate through vector of strings
    for (int i = 0; i < strs.size(); i++){

        std::string current_string = strs[i];

        // convert current string into sorted string to use as key
        std::string sorted_str = sortString(current_string); // convert current string into sorted string

        // if sorted string has appeared before
        if (hashmap.count(sorted_str) > 0){
            // map anagram to sorted_str key
            hashmap[sorted_str].push_back(strs[i]);
        }
        else{ // if sorted string has not appeared before, make it a new key
            std::vector<std::string> new_vector_s = {current_string};
            hashmap.insert(std::make_pair(sorted_str, new_vector_s));
            group_count++;
        }
    }

    groupedStrs.resize(group_count); // Allocate appropriate amount of space


    int index = 0;
    // Iterate through map and for each key, add vector of strings to that index of output vector
    for (auto itr = hashmap.begin(); itr != hashmap.end(); ++itr){
        groupedStrs[index] = itr->second;
        index++;
    }

    // output vector of grouped together strings
    return groupedStrs;
}

// Driver
int main(){
    std::vector<std::string> s1 = {"eat","tea","tan","ate","nat","bat"}; 

    std::vector<std::vector<std::string>> groupedAna = groupAnagrams(s1);

    printGroupedStrings(groupedAna);

    return 0;
}