/**
 * @file LC652_FindDuplicateSubtrees.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>


struct Node {
    int val_= 0;
    Node* next_;
    Node* previous_;

    Node(): next_(nullptr), previous_(nullptr){}

    Node(int val) : val_(val), next_(nullptr), previous_(nullptr){}

    Node(int val, Node* next) : val_(val), next_(next), previous_(nullptr){}

    Node(int val, Node* next, Node* previous) : val_(val), next_(next), previous_(previous){}
};

class MyLinkedList {
public:
    MyLinkedList() {
        first_ = nullptr;
        last_ = first_;
        item_count_ = 0;
    }
    
    int get(int index) {
        if (index > item_count_ -1 || item_count_ == 0){
            return -1;
        }

        // traverse linkedlist until you have reached index
        int count = 0;
        Node* cur = first_;

        while (count < index){
            // first check if there is another node after current one
            if (cur->next_ == nullptr){
                // if you're at last node and that isn't the index
                // return flag value
                return -1;
            }
            // if there is a next node, go to that one
            cur = cur->next_;
            count++;
        }
        // when we have reached indexth node, return the value therein
        return cur->val_;
    }

    int getListSize(){
        return item_count_;
    }
    
    void addAtHead(int val) {

        // construct a new node that stores value and points to current head
        Node* newNode = new Node(val,first_,nullptr);

        // if this isn't our first addition to list
        if (item_count_ == 0){
            first_ = newNode;
            last_ = newNode;
            item_count_++;
            return;
        }
        else if (item_count_ > 0){
            // make what is currently the first node point to newNode as previous
            // otherwise the nodes in list will have all previous pointers set to nullptr
            first_->previous_ = newNode;
        }

        // make the first node in list the new added node
        first_ = newNode;

        item_count_++;
    }
    
    void addAtTail(int val) {
        Node* cur = first_;


        // if there's only one node
        if (item_count_ == 0){
            addAtHead(val);
            return;
        }

        while (cur->next_ != nullptr){
            cur = cur->next_;
        }

        // now that we're at last node
        
        // add a new node to the end
        Node* newTailNode = new Node(val,nullptr,cur);
        cur->next_ = newTailNode;
        last_ = newTailNode;
        item_count_++;
    }
    
    Node* getPointerToIndex(int index){
        if (index > item_count_){
            return nullptr;
        }
        if (index == 0){
            return first_;
        }

        int cur_index = 0;
        Node* cur = first_;

        // iterate to index
        while (cur_index < index){
            cur = cur->next_;
            cur_index++;
        }

        // return pointer to node at index
        return cur;
    }

    void addAtIndex(int index, int val) {
        // make sure index exists
        if (index > item_count_){
            return;
        }

        Node* cur = getPointerToIndex(index);

        // make new node to insert at current index, make it point to current node as next_
        Node* newNode = new Node(val, cur);

        if (index == 0){
            addAtHead(val);
            return;
        }
        else if (index == item_count_){ // if index is at the end of list, just use addAtTail method
            addAtTail(val);
            return;
        }
        else{
            // make the previous node pointer for the new addition
            // point to the previous node pointer of current index node
            newNode->previous_ = cur->previous_;

            // update the previous node pointer for the current node to point to the new node
            cur->previous_ = newNode;

            // update the next_ pointer for the previous node so that it points to newNode
            cur = newNode->previous_;
            cur->next_ = newNode;
        }

        item_count_++; // iterate item count
    }
    
    void deleteAtIndex(int index) {
        if (index > item_count_ - 1 || item_count_ == 0){
            return;
        }

        Node* cur = getPointerToIndex(index);

        if (index == 0 && item_count_ == 1){ // if only one node in list and we're deleting it
            first_ = nullptr;
            last_ = nullptr;
        }
        else if (index == 0 && item_count_ > 1){ // if deleting first node and list size > 1
            // update first pointer
            first_ = first_->next_;
            cur->next_->previous_ = nullptr;

        }
        else if (index == item_count_ -1){ // if deleting tail node
            cur->previous_->next_ = cur->next_;
            last_ = cur->previous_;
        }
        else{ // if node to delete is somewhere in the middle
            // connect the nodes previous and after the current node
            cur->next_->previous_ = cur->previous_;
            cur->previous_->next_ = cur->next_;
        }

        // then delete current node
        delete cur;
        // remove dangling pointers
        cur->next_ = nullptr;
        cur->previous_ = nullptr;
        cur = nullptr;

        item_count_--; // decrement 
    }
private:
    Node* first_;
    Node* last_;
    size_t item_count_;
};



// Driver
int main(){

    // // Construct a linked list
    // MyLinkedList myLinkedList;
    // // myLinkedList.addAtHead(2);
    // myLinkedList.addAtHead(1);
    // // myLinkedList.addAtTail(3);
    // // myLinkedList.addAtIndex(1,9);
    // myLinkedList.deleteAtIndex(0);


    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(2);
    myLinkedList.deleteAtIndex(1);



    // std::cout << "Number of nodes in list: " << myLinkedList.getListSize() << std::endl;

    for (int i = 0; i < myLinkedList.getListSize(); i++){
        std::cout << myLinkedList.get(i) << std::endl;
    }
}