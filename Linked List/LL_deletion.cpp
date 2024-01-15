/*Deletion in Linked list
    1. head element
    2. tail 
    3. Kth position list
    4. kth position list according to the value
Thus, there are in total 8 questions
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

// function for deleteing the head of linked list
Node* deleteHead(Node* head){
    if(head == NULL) return head; // if the linked list is empty
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
};

// function for deleting the tail of linked list
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = nullptr;
    return head;
};

//function to delete the kth list in a linked list
Node* deleteK(Node* head, int k){

    Node* temp = head;
    // handling null and single linked lists
    if(head == NULL || head->next == NULL) return NULL;

    // linked lists with 2 or more lists
    int count = 1;
    while(count != k-1){
        temp = temp->next;
        count++;
        cout << count << endl;
    }
    Node* skip = temp->next;
    temp->next = temp->next->next;
    delete skip;
    return head;

};

// function for deleteing Kth list according to its value
Node* deleteKthValue(Node* head, int value){

    Node* temp = head;
    // handling null and single linked lists
    if(head == NULL || head->next == NULL) return NULL;

    // linked lists with 2 or more lists
    int count = 1;
    while(temp->next->data != value){
        temp = temp->next;
        count++;
        cout << count << endl;
    }
    Node* skip = temp->next;
    temp->next = temp->next->next;
    delete skip;
    return head;

};

int main(){
    vector<int> arr = {1,2,3,4,723,534};

    Node* head = createLinkedList(arr);
    printLL(head);
    printLL(deleteKthValue(head, 723));


    return 0;
}