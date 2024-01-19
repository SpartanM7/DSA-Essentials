#include<iostream>
#include<vector>
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

// function for creating DLL from an array
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

// deleting the head of DLL
Node* deleteHead(Node* head){
    if(head == nullptr || head->next == nullptr) return NULL;
    Node* temp = head->next;
    delete head;
    temp->prev = nullptr;
    return temp;
}

// deleting the tail of DLL
Node* deleteTail(Node* head){
    if (head == nullptr || head->next == nullptr ) return nullptr;
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newTail = temp->prev;
    newTail->next = nullptr;
    delete temp;
    return head;
}

// delete any Kth list in DLL 
// need to add edge cases
Node* deleteK(Node* head, int k){
    Node* temp = head;
    // if(head = nullptr) return nullptr;
    // if(head->next == nullptr && k == 1 ) return nullptr;
    int count = 0;
    while(temp -> next != nullptr){
        count++;
        cout << count << endl;
        if(count == (k-1)){
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete deleteNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// deleting using value at the Kth position
// need to add edge cases
Node* deleteKValue(Node* head, int value){
    Node* temp = head;
    while(temp->next != nullptr){
        if(temp->value == value){
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            break;
        }
        temp = temp->next;
    }
    return head;

}

// inserting at the head
Node* insertHead(Node* head, int value){
    Node* temp = new Node(value, head, nullptr);
    head = temp;
    return head;
}

// insert at tail
Node* insertTail(Node* head, int value){
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newTail = new Node(value, nullptr, temp);
    temp->next = newTail;
    return head;
}

// insertin gat kth position , need to add edge cases
Node* insertK(Node* head, int value, int pos){
    Node* temp = head;
    int count = 0;
    while(temp->next != nullptr){
        count++;
        if(count == pos){
            Node* insertNode = new Node(value, temp->next, temp);
            temp->next = insertNode;
            insertNode->next->prev = insertNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    // array for creating the DLL
    vector<int> arr = {1,2,3,4,723,534,32,65,2345};

    Node* head = convert2DLL(arr);
    printDLL(head);
    printDLL(insertK(head , 17273, 3));


    return 0;
}

