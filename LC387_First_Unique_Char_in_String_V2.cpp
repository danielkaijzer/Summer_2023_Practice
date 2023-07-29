/**
 * @file LC387_First_Unique_Char_in_String.cpp
 * @author Daniel Kaijzer
 * @brief Given a string, 
 * find the first non-repeating character in it and return it's index. 
 * If it doesn't exist, return -1.
 * @version 0.2
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <unordered_map>

    int firstUniqChar(std::string s) {

        // create hashmap where,
        // Key: char in string
        // Tuple values: 1) Char occurrence counter and 2) Index of char in string
        std::unordered_map<char,std::pair<int,int>> hmp1;

        int count = 1; // initial occurrence count for a char
        int index = 0; // initial index
        int min_count = s.size(); // initialize to highest possible value (if all chars in string are the same)
        int min_index = s.size(); // initialize to highest index

        // add repeating chars and their indices to hmp1
        for (char c : s){
            if (hmp1.count(c) > 0){ // if char has appeared before 
                hmp1[c].first += 1;
            }
            else{
                hmp1.insert(std::make_pair(c,std::make_pair(count,index)));
            }
            index++;
        }

        // find char with min count and min index
        for (auto itr = hmp1.begin(); itr != hmp1.end(); ++itr){

            // if current char has less or the same number of occurences AND lower index, update
            if (itr->second.first <= min_count){
                min_count = itr->second.first;
        
                if (itr->second.second < min_index){
                    min_index = itr->second.second;
                }
            }
            // std::cout << "Key: " << itr->first << " | Occurence: " << itr->second.first << " | Index: " << itr->second.second << std::endl;
        }

        if (min_count > 1){ // if no non-repeating char in string
            return -1;
        }
        // else return min index of char with min occurrences
        return min_index;
    }


// Driver
int main(){
    std::string s1 = "leetcode"; // 0
    std::string s2 = "loveleetcode"; // 2
    std::string s3 = "aabb"; // -1

    int x = firstUniqChar(s1);

    std::cout << "Min Index: " << x << std::endl;

    return 0;
}