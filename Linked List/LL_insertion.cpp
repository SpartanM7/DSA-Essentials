/*
    Linked List insertions:
    1. insert before head
    2. insert after tail
    3. insert before and after at kth position
    4. insert before and after kth position value
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

// function for creating linked list form an array
Node* createLinkedList(vector<int> &arr ) { // Time complexity -> O(n)
    // creating head, that will be the first element
    Node* head = new Node(arr[0]); 

    Node* mover = head; // copying the value of head to mover

    for (int i = 1; i < arr.size() ; i++){   // starting with one cuz the 1st element is already the head
        Node* temp = new Node(arr[i]);      // temp is a pointer variable that holds memory address
        mover->next = temp; // mover->next stores the address of the temp object
        mover = temp;

    }

    return head;
};

// function for printing linked list
Node* printLL(Node* head){ 
    Node* temp = head; // to not tamper with the head
    while(temp){
        cout << temp->data << " ";
        temp = temp->next; // first the address of head is given to the temp then we change the address of temp to the next list in the line 
    }
    cout << endl;
};

// insert before head, thus replacing the head
Node* insertHead(Node* head, int value){
    Node* temp = new Node(value);
    temp->next = head;
    return temp;
};

// insert after tail
Node* insertTail(Node* head, int value){
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Node(value);
    return head;
}

// insert at the Kth position with value
Node* insertKValue(Node* head, int value, int newValue){
    if(head == NULL) {  // if the linked list is empty
        return new Node(newValue);
    }
    Node* temp = head;
    int count = 0;
    while(temp->next != NULL){
        if(temp->data == value){
            Node* newNode = new Node(newValue, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;

};

// insert at the kth position
Node* insertK(Node* head, int k, int value){
    if(head == NULL) {  // if the linked list is empty
        if(k == 1){
            return new Node(value);
        }
    }
    if(k == 1) return new Node(value, head); // inserting at the head

    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count+=1;
        if(count == (k-1)){
            Node* newNode = new Node(value, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;

};



int main(){
    vector<int> arr = {1,2,3,4,723,534};

    Node* head = createLinkedList(arr);
    printLL(head);
    printLL(insertKValue(head, 4, 6253));


    return 0;
}