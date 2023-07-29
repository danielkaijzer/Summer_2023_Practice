/**
 * @file set2.cpp
 * @author your name (you@domain.com)
 * @brief A program that tests if characters within a `find` string exist in another string. 
 *        I do this using the set data structure.
 * 
 * Time complexity: O(n^2)
 * 
 * @version 0.1
 * @date 2023-06-06
 */

#include <iostream>
#include <set>
#include <string>

bool contains_helper(char c, std::set<char>exists_){
    for (auto index = exists_.begin(); index != exists_.end(); index++){
        if (*index == c){
            return true;
        }
    }
    return false;
}

bool contains(std::string find_, std::set<char> exists_){
    // iterate through `find` string and check if each character is in the set `exists`
    for (int i = 0; i < find_.length(); i++){
        // if character in `find` string does not exists in `exists`, return false
        if (!(contains_helper(find_[i], exists_))){
            return false;
        }
    }
    return true;
}


int main(){
    std::string example = "Hello my name is Daniel and I am testing the set data structure.";

    std::string find = "mary?";

    std::set<char> exists;

    // Add example into set exists
    for (int i = 0; i < example.length(); i++){
        char letter = example[i];
        exists.insert(letter);
    }

    // check if chars in `find` string exist in `exist` set
    if (contains(find, exists)){
        std::cout << "Characters in find exist in example string" << std::endl;
    }
    else{
        std::cout << "Characters in find DO NOT exist in example string" << std::endl;
    }

    return 0; // SUCCESS
}