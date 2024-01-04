// Intro for polymorphism.
// poly -> many
// morph -> forms 
// polymorphism -> meaning a function existing in many different forms but having same name
// It is of 2 types
//      1. Function overloading
//      2. Operator overlaoding

#include <iostream>
using namespace std;

class Math{

    public:
    int sum (int a, int b){
        cout << "This is the 1st Signature" << endl;
        cout << a + b << endl;
    };

    int sum (int a, int b, int c){
        cout << "This is the 2nd Signature" << endl;
        cout << a + b + c << endl;
    }
    float sum (int a , float b){
        cout << "This is the 3rd signature" << endl;
        cout << a + b << endl;
    }
};

class param{
    public:
    int value;

    void operator+(param& object2){
        int value1 = this->value;
        int value2 = object2->value;
        cout << (value1 + value2) << endl;
    }


};

int main()
{   
    Math m;

    // function overloading
    m.sum(5,2); // 1st signature
    m.sum(5,2,34); // 2nd signature
    // m.sum (5,2.17); it will not work since the compiler is about the float variable
    m.sum(5,2.17f); // stating 'f' here will show that this variable is floating type

    // operator overloading
    param object1, object2;
    object1.value = 7;
    object2.value = 2;
    object1 + object2; // this will not work since the commpiler doesn't know what is the '+' indicates between these objects 
    // object1 is treated as the current object
    // int this '+' is passed as the MEMBER FUNCTION 
    // 'object2' is passed as the input parameter

    return 0;
}