/*there are 2 possible solution known for now 
    1. Using stack to reverse data : it is a 2 iteration process 1 -> storing data in stack 2 -> retriving data from stack and storing in list
    2. reverse the lists themselves : 1 iteration process
    3. recursive method - same as above but using recrusion
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

// creating DLL fron an array
Node* convert2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size() ; i++){
        Node* temp = new Node(arr[i], nullptr, mover);
        mover->next = temp;
        mover = temp;
    }
    return head;

}

// printing the DLL
Node* printDLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->value << " ";
        temp=temp->next;
    }
    cout << endl;
}

// reverse using stack method TC = O(2n) ; SC = O(n)
Node* reverseStack(Node* head){
    stack<int> s;
    Node* temp = head;
    while(temp != nullptr){
        s.push(temp->value);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        temp->value = s.top();
        s.pop();
        temp = temp->next;
    }
    return head;
};


// reverse the lists
Node* reverse(Node* head){
    // if the list is empty or has 1 list
    if(head == NULL || head->next == NULL){ 
        return head;
    }
    Node* curr = head;
    Node* prevList = NULL;
    while(curr != NULL){
        prevList = curr->prev;
        curr->prev = curr->next;
        curr->next = prevList;
        curr = curr->prev;
    }
    return prevList->prev;

};


int main()
{
        // array for creating the DLL
    vector<int> arr = {1,2,3,4,5};

    Node* head = convert2DLL(arr);
    printDLL(reverse(head));

    return 0;
}