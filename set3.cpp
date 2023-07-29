/**
 * @file set2.cpp
 * @author your name (you@domain.com)
 * @brief A program that tests if characters within a `find` string exist in another string. 
 *        I do this using the set data structure.
 * 
 * Time complexity: O(n)
 * 
 * @version 0.1
 * @date 2023-06-06
 */

#include <iostream>
#include <set>
#include <string>


bool contains(std::string s, std::set<char> &exists_){
    // loop through s
    for (int i = 0; i < s.length(); i++){
        // remove all letters from set `exists` that exist in `s`
        exists_.erase(s[i]);
    }

    // if `exists_` is empty, return true
    if (exists_.empty()){
        return true;
    }
    return false;
}


int main(){
    std::string example = "Hello my name is Daniel and I am testing the set data structure.";

    std::string find = "mary";

    std::set<char> exists;

    // Add `find` into set `exists`
    for (int i = 0; i < find.length(); i++){
        char letter = find[i];
        exists.insert(letter);
    }

    if (contains(example, exists)){
        std::cout << "Characters in find exist in example string" << std::endl;
    }
    else{
        std::cout << "Characters in find DO NOT exist in example string" << std::endl;
    }

    return 0; // SUCCESS
}