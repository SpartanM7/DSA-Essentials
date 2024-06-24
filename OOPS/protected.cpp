#include<iostream>
using namespace std;

class A{
    protected:
    void show(){
        cout << "base class show" << endl;
    }
};

class B : public A{
    public:
    B(){
        show();
    }
};
class C : public B{
    public:
    C(){
        show();
    }
};

int main()
{
    C c1;
    B b1;
    // b1.show();

    

    return 0;
}