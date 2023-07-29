/**
 * @file LC2_AddTwoNumbers.cpp
 * @author Daniel Kaijzer
 * 
 * @brief You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order,
 * and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero,
 * except the number 0 itself.
 * 
 * @version 0.1
 * @date 2023-07-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

    ListNode* l3 = new ListNode();
    ListNode* head = l3;

    int carry = 0;

    // Add first two digits
    // l3's first value will be sum of l1->val + l2-val,
    // then proceed to next
    while (l1 != NULL && l2 != NULL){

        int cur_sum = l1->val + l2->val + carry; // sum for current node
        carry = cur_sum/10; // update carry

        l1 = l1->next;
        l2 = l2->next;
        l3->next = new ListNode(cur_sum%10);
        l3 = l3->next;
    }

    // if there's more to l1
    while (l1!=NULL){
        int cur_sum = l1->val + carry;
        carry = cur_sum/10;
        
        l1 = l1->next;
        l3->next = new ListNode(cur_sum%10);
        l3 = l3->next;
    }
    // // if there's more to l2
    while (l2!=NULL){
        int cur_sum = l2->val + carry;
        carry = cur_sum/10;
        
        l2 = l2->next;
        l3->next = new ListNode(cur_sum%10);
        l3 = l3->next;
    }

    // if additional carry leftover
    if (carry){
        l3->next = new ListNode(carry);
    }

    return head->next;

}

// Driver
int main(){

    // List 1
    ListNode *head1 = new ListNode(5);
    ListNode *mid1 = new ListNode(1);
    ListNode *tail1 = new ListNode(1);
    
    head1->next = mid1;
    mid1->next = tail1;
    tail1->next = NULL;


    // List 2
    ListNode *head2 = new ListNode(5);
    ListNode *mid2 = new ListNode(1);
    // ListNode *tail2 = new ListNode(4);

    head2->next = mid2;
    mid2->next = NULL;
    // tail2->next = NULL;

    ListNode* cur = addTwoNumbers(head1, head2);

    while(cur){
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

}