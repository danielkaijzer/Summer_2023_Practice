/**
 * @file LC141_LinkedListCycle 2
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-07-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
// #include <unordered_map>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head){
    
    // create slow and fast pointers
    // ListNode* slow = head;
    // ListNode* fast = head;

    // std::unordered_map<ListNode*, int> hmp;
    std::unordered_set<ListNode*> hash_set;

    ListNode * cur = head;

    while(cur != nullptr){
        // hmp.insert(std::make_pair(cur,0));

        if (hash_set.count(cur) > 0){
            return cur;
        }

        hash_set.insert(cur);
        cur = cur->next;

        // slow = slow->next;
        // fast = fast->next->next;

        // if (fast == slow){ // if fast catches up to slow, there is a cycle
        //     return slow->next;
        // }
    }
    return nullptr;
    
}

// Driver
int main(){

    ListNode *head = new ListNode(1);
    ListNode *mid = new ListNode(2);
    ListNode *tail = new ListNode(3);

    head->next = mid;
    mid->next = tail;
    tail->next = head; //creates cycle

    if (detectCycle(head)){
        std::cout << "List has cycle\n";
    }
    else{
        std::cout << "List has NO cycle\n";
    }
    return 0;
}