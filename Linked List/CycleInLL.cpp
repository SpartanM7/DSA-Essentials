/*
    This question entails that there might be a linked list that has a cyclic nature to it. Therefore we have to check if the LL has the cyclic
    nature or not and if it has the cyclic nature return the intersection point.
    Approches:
        1. Using hashmap/set to store and check all the points
        2. Floyd's algorithm (Hare and Tortoise) {Slow and fast pointer}  [COMPLETE]
        3. Brent's cycle detection algorithm  
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// class for the doubly linked list
class Node{
    public:
        int value;
        Node* next;
        Node* prev;

    public:
        Node(int value1, Node* next1 ,Node* prev1){
        this->value = value1;
        this->next = next1;
        this->prev = prev1;
    }
    Node(int value1){
        this->value = value1;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// 2. Floyd's Algorithm
bool cycleLL(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast=>next=>next;
        if(slow == fast){ // it means there is a loop but meeting point  can be anywhere in the cycle
            cout << "There is a loop" << endl;
            // to find the intersection point we can put slow or fast at the head then run the while to find the intersection point
            slow = head;
            int count = 0;
            while(slow != head){
                slow = slow->next;
                fast = fast->next;
                count ++;
            }
            cout << "The index of the intersection node is :" << count << endl;
        }
        return true;
    }
    return false;
}
