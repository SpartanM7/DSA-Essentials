/* There can be 2 solutions:
    1. Reversing and adding 1 : first reverse the LL and add 1 to and return the reversed the linked list
    2. Backtracking : use recursion and during the backtraking add carry (This solution is given below)
*/


#include<iostream>
using namespace std;

class Node {
    public:
      int data;
      Node *next;
      Node() {
          this->data = 0;
          this->next = NULL;
      }
      Node(int data) {
          this->data = data;
          this->next = NULL;
      }
      Node (int data, Node *next) {
          this->data = data;
          this->next = next;
    }
};



int helper(Node* temp){
        if(temp == NULL){
            return 1;
        }
        int carry = helper(temp->next);
        temp->data = temp->data + carry;
        if(temp->data < 10){
            return 0;
        }
       temp->data = 0;
       return 1;
};

Node *addOne(Node *head)
{

    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    else return head;
    
    

}
