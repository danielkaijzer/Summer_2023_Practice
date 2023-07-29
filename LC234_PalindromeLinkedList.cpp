/**
 * @file LC234_PalindromeLinkedList.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-07-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

int getLength(ListNode* head){
    int count = 0;

    ListNode* cur = head;

    while (cur){
        count++;
        cur = cur->next;
    }
    return count;
}

bool isPalindrome(ListNode* head) {
    if (head == NULL) return true;

    ListNode* cur = head;

    std::stack<int> w;

    int index = 0;

    int length = getLength(head);

    if (length%2 == 0) // if length is even
    {
        while (cur){
            if (index < length/2){ // push first half of elements to stack
                w.push(cur->val);
                cur = cur->next;
                index++;
            }
            else{ // pop second half of elements from stack if they match
                if (w.top() == cur->val){ // wr matches stack, pop
                    w.pop();
                    cur = cur->next;
                }
                else{ // if wr does not match stack, it's not a palindrome
                    return false;
                }
            }
        }
    }
    else{ // if length is odd
        // std::cout << "Check\n";
        while (cur){
            if (index < length/2){ // push first half of elements to stack
            // std::cout << "Check\n";
                w.push(cur->val);
                cur = cur->next;
                index++;
            }
            else if (index > length/2){ // pop second half of elements from stack if they match
                if (w.top() == cur->val){ // wr matches stack, pop
                    w.pop();
                    cur = cur->next;
                }
                else{ // if wr does not match stack, it's not a palindrome
                    return false;
                }
            }
            else{
                // skip middle element if list is of odd length
                cur = cur->next;
                index++;
            }
        }
    }

    if (w.empty() == true){
        return true; 
    }
    return false;
}


// Driver
int main(){

    // List A
    ListNode *head = new ListNode(1);
    ListNode *mid1 = new ListNode(0);
    ListNode *mid2 = new ListNode(1);
    // ListNode *tail = new ListNode(1);


    head->next = mid1;
    mid1->next = mid2;
    mid2->next = NULL;
    // tail->next = NULL;

    if (isPalindrome(head)){
        std::cout << "True\n"; 
    }
    else{
        std::cout << "False\n"; 
    }

  
    return 0;
}