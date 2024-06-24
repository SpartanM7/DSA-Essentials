#include<iostream>
using namespace std;

class ArrayStack{
    public:
    int top = -1;
    int* arr;
    ArrayStack(int& size){
        arr = new int[size];
    }
    void push(int x) {
        this->top = top+1;
        arr[this->top] = x;
    }
    void pop(){
        
        this->top = this->top-1;
    }
    int Top(){
        return arr[top];
    }
    int size(){
        return top+1;
    }
    void emptyFunction(){

    };


};

int main()
{
    int size;
    cout<<"Enter the number of elements in array : " << endl;
    cin >> size;
    ArrayStack stack(size);
    stack.push(23);
    cout << stack.Top() << endl;
    stack.pop();
    // cout << stack.emptyFunction() << endl;
    cout << stack.Top() << endl;
    return 0;
}