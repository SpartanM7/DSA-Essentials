#include<iostream>
using namespace std;

class animal{
    private:
    int weight;

    public:
    int age;
    string name;

    // default constructor -> initializes everything with 0 or empty
    animal(){
        this->age = 0; // this is used for best practice
        this->weight = 0;
        this->name = "";
        cout << "Default constructor was called" << endl;
    }

    // parameterized constructor 1
    animal(int age){
        this->age = age;
        cout << "Parametarized constructor 1 was called" << endl;
    }
    animal(int age, int weight){
        this->age = age;
        this->weight = weight;
        cout << "Parametarized constructor 2 was called" << endl;
    }
    animal(int age, int weight, string name){
        this->age = age;
        this->weight = weight;
        this->name = name;
        cout << "Parametarized constructor 3 was called" << endl;
    }

    // copy constructed : need to pass it by reference
    animal(animal &obj){ 
        obj.age = age;
        obj.weight = weight;
        obj.name = name;
        cout << "This is the copy constructor" << endl;
    }
    //distructor : has some default for static but for dynamic objects we need to call distructor
    ~animal(){
        cout << "Enter the distructor" << endl;
    }
};

int main()
{
    //object creation
    animal a; // default constructor
    animal b1(21);
    animal b2(21,95);
    animal b3(21,95,"gyanesh");
    animal *c1 = new animal(21,90,"Harsh");
    animal c2 = b3;
    animal c3(b1);
    
    return 0;
}