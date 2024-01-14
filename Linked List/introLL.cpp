/* This code is all about Linked List.
It contains : 
    1. creating class for the initializing of the linked list
    2. Creating linked list using the class
    3. transversing thourgh a linked list 
    4. Creating a Linked list from an array
    5. Searching in a Linked list
    
*/

#include<iostream>
#include<vector>
using namespace std;


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

// creating a function to convert array to linked list
Node* createLinkedList(vector<int> arr ) { // Time complexity -> O(n)
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

Node* searchInLinkedList(Node* head, int key){
    Node* temp = head; // to not tamper with the head
    while(temp){ 
        if(temp->data == key){

            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}


int main(){

    vector<int> arr = {0,1,2,4,723,534};

    // initializing a linked list
    Node* y = new Node(arr[5]);
    // cout << y << "\n"; // prints the memory location of the head
    // cout << y->data << "\n"; // prints the value present at the location of y

    Node* head = createLinkedList(arr);
    cout << head << "\n"; // prints the memory address of the head of linked list

    // transversing the linked list
    Node* temp = head; // to not tamper with the head
    while(temp){
        cout << temp->data << " ";
        temp = temp->next; // first the address of head is given to the temp then we change the address of temp to the next list in the line 
    }
    cout << endl;

    Node* searchResult = searchInLinkedList(head, 36745);
    if(searchResult != nullptr) cout << "Key Found" << endl;
    else cout << "Key Not Found" << endl;
    

    return 0;
}