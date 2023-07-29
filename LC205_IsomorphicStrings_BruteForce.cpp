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

    // map each unique character in string 1
    // to unique characters in string 2
    std::unordered_map<char,char> hashmap;
    std::unordered_map<char,char> hashmap2;

    // two strings won't be isomorphic if:
    // the number of unique characters differs
    // the placement of repeated characters differ


    for (int i = 0; i < s.length(); i++){

        if (hashmap.count(s[i]) == 0){
            hashmap.insert(std::make_pair(s[i], t[i]));
            hashmap2.insert(std::make_pair(t[i], s[i]));
        }
    }


    // // use hashmap to recreate string
    std::string test;
    std::string test2;

    // loop through string `s` and try to recreate string `t` with string `test`
    for (char c : s){
        // add characters to `test` string using hashmap
        test += hashmap[c];
    }
    // loop through string `s` and try to recreate string `t` with string `test`
    for (char c : t){
        // add characters to `test` string using hashmap
        test2 += hashmap2[c];
    }

    // if strings do not match, then strings are not isomorphic
    std::cout << test << std::endl;
    std::cout << t << std::endl;

    std::cout << test2 << std::endl;
    std::cout << s << std::endl;

    for (int i = 0; i < t.length(); i++){
        if (t[i] != test[i]){
            return false;
        }
    }

    for (int i = 0; i < s.length(); i++){
        if (s[i] != test2[i]){
            return false;
        }
    }

    return true;
    
}


// Driver
int main(){
    std::string s1 = "paper";
    std::string s2 = "title";

    if (isIsomorphic(s1,s2)){
        std::cout << "The two strings are isomorphic.\n";
    }
    else{
        std::cout << "The two strings are NOT isomorphic.\n";
    }


    return 0;
}