/**
 * @file LC160_IntersectionLinkedLists
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-07-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    
    // create pointers to follow each list
    ListNode* p1 = headA;
    ListNode* p2 = headB;

    std::unordered_set<ListNode*> l1_vals;

    // first loop
    while (p1 != nullptr){

        std::cout << p1 << std::endl;
        l1_vals.insert(p1);
        p1 = p1->next;
    }

    while (p2 != nullptr){
        if (l1_vals.count(p2) > 0){
            return p2;
        }
        p2 = p2->next;
    }

    // if we reach end of either lists, no intersection
    return NULL;
}


// Driver
int main(){

    // List A
    ListNode *head1 = new ListNode(1);
    ListNode *mid1 = new ListNode(2);

    // List B
    ListNode *head2 = new ListNode(5);
    ListNode *mid2 = new ListNode(4);

    ListNode *tail = new ListNode(3);


    head1->next = mid1;
    mid1->next = tail;
    head2->next = mid2;
    mid2->next = tail;

    if (getIntersectionNode(head1, head2)){
        std::cout << "Lists have intersection\n";
    }
    else{
        std::cout << "Lists have NO intersection\n";
    }
    return 0;
}