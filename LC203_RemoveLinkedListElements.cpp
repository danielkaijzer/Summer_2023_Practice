/**
 * @file LC203_RemoveLinkedListElements.cpp
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

ListNode* removeElements(ListNode* head, int val) {

    if (head == NULL) return NULL;

    ListNode* temp1 = NULL;

    // if values to delete are at front of list
    while(head->val == val){
        if (head->next == NULL){
            return NULL;
        }
        temp1 = head;
        head = head->next;
        delete temp1;
        temp1 = NULL;
    }

    ListNode* cur = head;

    ListNode* prevcur = head;

    // if values to delete are in middle of list
    while (cur)
    {
        while (cur->val == val && cur->next != NULL){
            cur->val = cur->next->val;
            temp1 = cur->next;
            cur->next = cur->next->next;
            delete temp1;
            temp1 = NULL;
        }

        if (cur->next != NULL){
            cur = cur->next;
        }
        else{
            break;
        }
    }

    // if value to be deleted is at the end
    if (cur->val == val){
        // std::cout << cur << std::endl;
        while(prevcur){
            if (prevcur->next == cur){
                prevcur->next = NULL;
            }
            prevcur = prevcur->next;
        }
    }

    return head;

}


// Driver
int main(){

    // List A
    ListNode *head = new ListNode(1);
    ListNode *mid1 = new ListNode(7);
    ListNode *mid2 = new ListNode(7);
    ListNode *tail = new ListNode(7);


    head->next = mid1;
    mid1->next = mid2;
    mid2->next = tail;
    tail->next = NULL;

    ListNode* cur = removeElements(head, 7);
    // ListNode* cur = head;

    while (cur){
        std::cout << cur->val << " " << cur << std::endl;
        cur = cur->next;
    }
    std::cout << std::endl;

    return 0;
}



    // // if head contains values to be removed
    // if (head->val == val){
    //     temp1 = head;
    //     head = head->next;
    //     delete temp1;
    //     temp1 = NULL;
    // }

    // ListNode* cur = head;
    
    // // if middle nodes contain values to be removed
    // while (cur != NULL && cur->next != NULL){ // loop until we reach nullpointer
    //     if (cur->next->val == val){
    //         temp1 = cur->next;
    //         cur->next = cur->next->next;
    //         delete temp1;
    //         temp1 = NULL;
    //     }
    //     std::cout << "loop check" << std::endl;
    //     cur = cur->next;
    // }

    // // // Tail value == val
    // // if (cur->val == val){
    // //     temp1 = cur;
    // //     cur = NULL;
    // //     delete temp1;
    // //     temp1 = NULL;
    // // }


    // return head;