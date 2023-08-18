/**
 * @file LC739_Daily_Temperatures.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.2
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> output;

    // add all elements to hashmap
    for (int i = 0; i < temperatures.size(); i++){
        int j = i;
        // find num of days until higher temp

        while (temperatures[i] >= temperatures[j] && j < temperatures.size()){
            j++;
        }
        output.push_back(j-i);
    }

    return output;
}


int main(){

}
