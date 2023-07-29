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

bool isIsomorphic(std::string s, std::string t) {

    // if two strings are not same length, 
    // then they cannot be isomoprhic
    if (s.length() != t.length()){
        return false;
    }

    std::unordered_map<char,char> hashmap;
    std::unordered_map<char,char> hashmap2;

    for (int i = 0; i < s.length(); i++){

        if (hashmap.count(s[i]) == 0 && hashmap2.count(t[i]) == 0){
            hashmap.insert(std::make_pair(s[i], t[i]));
            hashmap2.insert(std::make_pair(t[i], s[i]));
        }
        if (hashmap[s[i]] != t[i]){
            return false;
        }
        if (hashmap2[t[i]] != s[i]){
            return false;
        }
    }
    return true;   
}


// Driver
int main(){
    std::string s1 = "title";
    std::string s2 = "paper";

    if (isIsomorphic(s1,s2)){
        std::cout << "The two strings are isomorphic.\n";
    }
    else{
        std::cout << "The two strings are NOT isomorphic.\n";
    }


    return 0;
}