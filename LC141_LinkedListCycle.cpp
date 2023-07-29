/**
 * @file LC141_LinkedListCycle 1
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-07-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head){
    
    // create slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;

    while(slow != nullptr && fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow){
            return true;
        }
    }
    return false;
    
}

// Driver
int main(){

    ListNode *head = new ListNode(1);
    ListNode *mid = new ListNode(2);
    ListNode *tail = new ListNode(3);

    head->next = mid;
    mid->next = tail;
    tail->next = head; //creates cycle

    if (hasCycle(head)){
        std::cout << "List has cycle\n";
    }
    else{
        std::cout << "List has NO cycle\n";
    }
    return 0;
}