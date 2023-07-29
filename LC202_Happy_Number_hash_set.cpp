/**
 * @file LC349_Intersection_of_Two_Arrays.cpp
 * @author Daniel Kaijzer
 * @brief Uses hash sets for isHappy problem
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

/**
 * @brief 
 * A happy number is a number defined by the following process:
 * 
- Starting with any positive integer, 
replace the number by the sum of the squares of its digits.

- Repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1.

- Those numbers for which this process ends in 1 are happy.
 * 
 * @param n (an integer)
 * @return true if n is a happy number
 * @return false if not
 */

    int digitSumSquares(int n){
        int squaresum = 0;
        while (n!=0){
            int square = (n%10) * (n%10);
            squaresum = squaresum + square;
            n = n /10;
        }
        return squaresum;
    }

    // modified to use hash sets to solve problem
    bool isHappy(int n) {
        int sum = n;
        std::unordered_set<int> set;

        // do sum of squares process as long as sum != 1 and values don't repeat (meaning we don't get stuck in infinite loop)
        while (sum != 1 && !set.count(sum)){ // use count() to fix infinite loop issue
            set.insert(sum); // add current element to set
            sum = digitSumSquares(sum); // do sum of squares process
        }
        // once process is done, return true/false
        return (sum==1); 
    }

// Driver/testing program
int main(){
    int n = 2;

    if (isHappy(n)){
        std::cout << "n is happy! :)\n";
    }
    else{
        std::cout << ":(\n";
    }

}
