#include<iostream>
using namespace std;

// any data members and mmember functions can be accessed in the class
// public -> can be accessed anywhere
// protected => can be accessed by the chlid only
// private -> cannot be accessed anywhere except the class
class animal{

    // adding access modifiers
    // state or properties
    private:
        int weight;
    
    public:
        int age;
        string name;

        // behaviours 
        // cpp -> functions
        // java -> methods
        void eat(){
            cout << "Eating something" << endl;
            return;
        }
        void sleep(){
            cout << "Always sleeping" << endl;
            return;
        }
        // setter
        void setWeight(int weight){
            // this : indicates the current object
            this->weight = weight;
        }
        // getter
        void getWeight(){
            cout << weight << endl;
        }

};

class emptyClass{
    //this is an empty class to check the size of it
    // every empty class is assigned min space so that it can have an existance
};

int main()
{
    // object creation
    //                  -> static
    //                  -> dynamic

    // empty object
    emptyClass notZero;
    cout << "Size of the empty class : " << sizeof(notZero) << endl;   // 1 because its a empty class and takes only one byte in memory


    // static object creation
    animal harsh;
    // to access the members of a class:
    // . operator is used
    harsh.age = 21;
    harsh.name = "harsh";
    cout << harsh.age << endl;
    cout << harsh.name << endl;
    harsh.eat();
    harsh.sleep(); 
    // cout << harsh.eat() << endl; --> this does not seem to be working

    // cout << harsh.weight << endl;
    // trying to access a private member, it will give error
    // to access the private members , we will use setter and getter
    // setter
    harsh.setWeight(90);
    //getter
    harsh.getWeight();

    // dynamic object creation

    // memory for gyanesh allocated in heap memory
    // porint gyanesh is allocated in stack memory
    animal* gyanesh = new animal;
    gyanesh->age = 21;
    // using dereferencing operator
    (*gyanesh).name = "Gyanesh";
    cout << gyanesh->age << endl;
    cout << gyanesh->name << endl;
    gyanesh->eat();
    gyanesh->setWeight(95);
    gyanesh->getWeight();

    // delete allocated memory from the heap
    delete gyanesh;

    return 0;
}