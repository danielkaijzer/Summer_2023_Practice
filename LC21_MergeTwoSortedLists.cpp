/**
 * @file LC21_MergeTwoSortedLists.cpp
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
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL){
        return list2;
    }
    else if (list2 == NULL){
        return list1;
    }
    
    // if values aren't null, compare
    // the compared order of the first two vals determines the chain of recursive events
    // and which list we will merge all elements into
    if(list1->val <= list2->val){
        //recursively call until we have properly merged list2 into list1
        // checks if next value in list1 is still less than current value in list2
        list1->next = mergeTwoLists(list1->next,list2);
        return list1; // return list1 as merged list
    }
    else{ // if list1 value greater than list2 value
        // use recursive call to check if next list2value is still greater than current list1 value
        list2->next = mergeTwoLists(list1, list2->next);
        return list2; // return list2 as merged list
    }
}


// Driver
int main(){

    // List A
    ListNode *head1 = new ListNode(1);
    ListNode *mid1 = new ListNode(3);
    ListNode *tail1 = new ListNode(5);

    head1->next = mid1;
    mid1->next = tail1;
    tail1->next = NULL;

    // List B
    ListNode *head2 = new ListNode(2);
    ListNode *mid2 = new ListNode(4);
    ListNode *tail2 = new ListNode(6);

    head2->next = mid2;
    mid2->next = tail2;
    tail2->next = NULL;
    
    ListNode* cur = mergeTwoLists(head1, head2);

    while(cur){
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
  
    return 0;
}