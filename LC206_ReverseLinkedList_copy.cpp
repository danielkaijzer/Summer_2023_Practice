/**
 * @file LC206_ReverseLinkedList
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

ListNode* reverseList(ListNode* head) {
    // Use two pointers for swapping
    ListNode* temp1 = NULL; // prev
    ListNode* temp2 = NULL; // next

    while (head != NULL){
        temp2 = head->next;
        head->next = temp1;
        temp1 = head;
        head = temp2;
    }

    head = temp1;
    return head;
}


// Driver
int main(){

    // List A
    ListNode *head = new ListNode(1);
    ListNode *mid = new ListNode(2);
    ListNode *tail = new ListNode(3);


    head->next = mid;
    mid->next = tail;
    tail->next = nullptr;

    ListNode* cur = reverseList(head);

    while (cur){
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    return 0;
}