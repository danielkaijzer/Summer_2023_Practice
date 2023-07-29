/**
 * @file LC141_LinkedListCycle 2
 * @author Daniel Kaijzer
 * @brief Uses Floyd's Tortoise and Hare Algorithm
 * @version 0.1
 * @date 2023-07-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// Floyd's Tortoise and Hare Algorithm for finding entrance to cycle
    // kc = a+b
    // k = number of times fast pointer loops through cycle
    // c = cycle length
    // a+b = distance traveled by slow pointer before meeting fast pointer

    // The number of times the fast pointer laps the cycle times the length of the cycle
    // equals the distance from the head of hte list to the meeting point


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head){
    
    // create slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;

    // first loop
    do{
        if (slow == nullptr || fast==nullptr || fast->next == nullptr){
            return nullptr;
        }
        slow = slow->next;
        fast = fast->next->next;
    }while (fast!= slow);

    // second part of Floyd's algo
    fast=head;

    while (fast!=slow){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;

    // while(slow != nullptr && fast!=nullptr && fast->next!=nullptr)
    // {
    //     // first loop
    //     do{
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }while (fast!= slow);

        // // second part of Floyd's algo
        // fast=head;

        // while (fast!=slow){
        //     slow = slow->next;
        //     fast = fast->next;
        // }
        // return fast;
    // }
    // return nullptr;
    
}


// Driver
int main(){

    ListNode *head = new ListNode(1);
    ListNode *mid = new ListNode(2);
    // ListNode *tail = new ListNode(3);

    head->next = mid;
    mid->next = nullptr;
    // tail->next = head; //creates cycle

    if (detectCycle(head)){
        std::cout << "List has cycle\n";
    }
    else{
        std::cout << "List has NO cycle\n";
    }
    return 0;
}