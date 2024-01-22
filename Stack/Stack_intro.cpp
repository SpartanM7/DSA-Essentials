#include<iostream>
#include<stack>
using namespace std;

/* There are 2 ways of implementing stack 
    1. array : 
    2. linked list :
*/

// implementing stack using array -> pop , push, top, empty
class StackArray {

    // properties
    public:
        int size;
        int topIndex;
        int* arr;

    // behaviours
    public:
        StackArray(int size){
            this->size = size;
            topIndex = -1;
            arr = new int[size];
        }

    // push operation
    void push(int element){
        if(topIndex+1 < size){
            topIndex++;
            arr[topIndex] = element;
        }
        else{
            cout << "Stack is full" << endl;
        }
        
    }

    // pop 
    void pop(){
        if(topIndex == -1){
            cout<< "The stack is empty" << endl;
        } 

        else{
            topIndex --;
        }
    }

    // isempty
    bool empty(){
        if(topIndex == -1) return true;
        else return false;
    }

    // top
    int top(){
        if(topIndex >= 0 && topIndex < size) return arr[topIndex];
        else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }



};





int main(){

    StackArray st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    st.pop();

    cout << st.StackArray::top() << endl;
    cout << st.StackArray::empty() << endl;



    // stack<int> s;

    // // push operation
    // s.push(1);
    // s.push(2);
    // s.push(4);

    // // pop operation
    // s.pop();
    

    // s.push(3);

    // // top operation
    // cout << s.top() << endl;

    // // empty operation
    // cout << s.empty() << endl;


}