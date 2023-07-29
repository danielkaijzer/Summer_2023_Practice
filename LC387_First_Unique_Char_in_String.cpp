/**
 * @file LC387_First_Unique_Char_in_String.cpp
 * @author Daniel Kaijzer
 * @brief Given a string, 
 * find the first non-repeating character in it and return it's index. 
 * If it doesn't exist, return -1.
 * @version 0.1
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>

    int firstUniqChar(std::string s) {

        // create hashmap where,
        // Key: char in string
        // Tuple values: 1) Char occurrence counter and 2) Index of char in string
        std::unordered_map<char,std::pair<int,int>> hmp1;

        int count = 1; // initial count
        int index = 0; // initial index

        // add repeating chars and their indices to hmp1
        for (char c : s){
            if (hmp1.count(c) > 0){
                hmp1[c].first += 1;
            }
            else{
                hmp1.insert(std::make_pair(c,std::make_pair(count,index)));
            }
            index++;
        }

        int min_count;
        int min_index = index; // initialize to highest index

        // find char with min count and min index
        for (auto itr = hmp1.begin(); itr != hmp1.end(); ++itr){

            // initialize min_count value for first pass
            if (itr == hmp1.begin()){
                min_count = itr->second.first;
            }

            // if current char has less or the same number of occurences AND lower index, update;
            if (itr->second.first <= min_count){
                min_count = itr->second.first;
        
                if (itr->second.second < min_index){
                    min_index = itr->second.second;
                }
            }
            // std::cout << "Key: " << itr->first << " | Occurence: " << itr->second.first << " | Index: " << itr->second.second << std::endl;
        }


        if (min_count > 1){
            return -1; // no non-repeating char in string
        }

        return min_index;
    }

// Driver
int main(){
    std::string s1 = "leetcode"; // 0
    std::string s2 = "loveleetcode"; // 2
    std::string s3 = "aabb"; // -1

    int x = firstUniqChar(s3);

    std::cout << "Min Index: " << x << std::endl;

    return 0;
}