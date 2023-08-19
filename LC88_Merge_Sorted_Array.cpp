/**
 * @file LC88_Merge_Sorted_Array.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 1
 * @date 2023-08-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>


using namespace std;

void mergeS(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // first determine which array is larger
    int num2_index = 0;

    // merge arrays
    for (int i = m; i < nums1.size(); i++){

        nums1[i] = nums2[num2_index];
        num2_index++;
    }

    // sort arrays
    sort(nums1.begin(), nums1.end());
}


int main(){

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
 
    mergeS(nums1, 3, nums2, 3);

    // for (int i=0; i < nums1.size(); i++){
    //     cout << nums1[i] << endl;
    // }
}
