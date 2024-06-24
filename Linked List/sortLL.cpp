/* Problem used to sort a LL. It can be done :
        1. using merge sort (SC-> 1+ log(n)[due to recursisve  calls]) (TC-> log(n)[recursion] * (n[merging] + n/2 [finding middle of LL]))
        2. brute force
        3. merge sort
*/


#include<iostream>
#include<vector>
using namespace std;

// class for linked list
class Node{

    public:
    int data;
    Node* next;

    // parameterized constructors 
    // passing data and null pointer
    Node(int data1, Node* next1){
        this->data = data1;
        this->next = next1;
        // cout << "Constructor 1 \n";
    }
    // passing data only
    Node(int data1){
        this->data = data1;
        this->next = nullptr;
        // cout << "Constructor 2\n";
    }
};

// find the 1st middle of the LL
Node* findMiddle(Node *head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return slow;
        }
    }
}

// using merge sort
