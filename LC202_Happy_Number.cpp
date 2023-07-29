/**
 * @file LC349_Intersection_of_Two_Arrays.cpp
 * @author Daniel Kaijzer
 * @brief Uses the unordered_set STL container. 
 * Given two integer arrays nums1 and nums2,
 * return an array of their intersection. 
 * Each element in the result must be unique 
 * and you may return the result in any order.
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
    int sum = 0;
    while (n!=0){
        int square = (n%10) * (n%10);
        sum = sum + square;
        n = n /10;
    }
    std::cout << sum << "\n";
    return sum;
}

bool isHappy(int n) {
    int sum = n;

    // base case
    if (sum ==1){
        return true;
    }

    // do sum of squares process as long as sum != 1, sum isn't single digit and it is positive
    if (sum != 1 && n >3){
        // replace n by sum of squares of its digits
        sum = digitSumSquares(sum);

        // if sum doesn't equal 1, repeat
        return isHappy(sum);
    }
    // sum is not 1, single digit or negative
    return false; 
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
