/**
 * @file heapify.cpp
 * @author Daniel Kaijzer
 * @brief builds a Heap from an Array
 * @version 0.1
 * @date 2023-08-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>


using namespace std;

void heapify(int arr[], int N, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // if left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
    
    // If right child is larger than root
    if (r < N && arr[r] > arr[largest]){
        largest = r;
    }

    // if, after above two if-statements, 
    // largest has changed, update root
    if (largest != i){
        swap(arr[i], arr[largest]);

        // recursively heapify subtrees
        heapify(arr, N, largest);
    }

}

void buildHeap(int arr[], int N){
    int start_index = (N/2) - 1;

    for (int i = start_index; i >= 0; i--){
        heapify(arr, N, i);
    }
}

void printHeap(int arr[], int N){
    cout << "Array representation of Heap:\n";

    for (int i = 0; i < N; ++i){
        cout << arr[i] << " ";
    }
    cout << "\n";
}


int main(){
       // Binary Tree Representation
    // of input array
    //             1
    //           /    \
    //         3        5
    //       /  \     /  \
    //     4      6  13  10
    //    / \    / \
    //   9   8  15 17
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
 
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    buildHeap(arr, N);
    printHeap(arr, N);
   
    // Final Heap:
    //              17
    //            /    \
    //          15      13
    //         /  \     / \
    //        9     6  5   10
    //       / \   / \
    //      4   8 3   1
 
    return 0;
}
