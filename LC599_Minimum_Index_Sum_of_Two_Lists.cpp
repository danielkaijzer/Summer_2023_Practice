/**
 * @file LC205_IsomorphicStrings
 * @author Daniel Kaijzer
 * @brief Given two strings s and t, determine if they are isomorphic.

    Two strings `s` and `t` are isomorphic 
    if the characters in s can be replaced to get t.

    All occurrences of a character must be replaced with another character 
    while preserving the order of characters. 

    No two characters may map to the same character, 
    but a character may map to itself.
 * 
 * @version 0.1
 * @date 2023-06-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


// find not only the string that matches
// but the ones that are at the index closest to beginning
std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {

    std::unordered_map<std::string,int> hmp1;
    std::unordered_map<std::string,int> hmp2;

    // Add strings from list1 to hmp1
    int index = 0;
    for (auto str : list1){
        // std::cout << "Key: " << str << " | Value/Index: " << index << "\n"; 
        hmp1.insert(std::make_pair(list1[index], index));
        index++;
    }

    int min_sum; // min sum variable
    int index_sum; // initialize index sum variable

    index = 0; // re-initialize index
    for (auto str : list2){
        // check if str exists in hmp1
        if (hmp1.count(str) !=0){ // if strings match
            index_sum = index + hmp1[str];
            hmp2.insert(std::make_pair(str,index_sum)); // add string to map2 along with index_sum

            // update min_sum variable
            if (hmp2.size() == 1){ // initialize min_sum during first pass
                min_sum = index_sum;
            }
            else if (min_sum > index_sum){ // only update min_sum value if a lesser index_sum is found
                min_sum = index_sum;
            }
            
        }
        index++;
    }

    // make a vector with only min index sum entries
    std::vector<std::string> min_index_sum;

    // iterate through hmp2 and only add entries with min sum
    for (auto itr = hmp2.begin(); itr != hmp2.end(); ++itr){
        // remove entries that aren't min sum
        if (itr->second == min_sum){
            min_index_sum.push_back(itr->first);
        }
    }

    return min_index_sum;
}


// Driver
int main(){
    std::vector<std::string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    std::vector<std::string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse", "Shogun"};

    std::vector<std::string> result = findRestaurant(list1,list2);

    for (auto str : result){
        std::cout << str << std::endl;
    }

    return 0;
}