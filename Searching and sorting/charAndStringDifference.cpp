#include<iostream>
#include<string>
using namespace std;

int main()
{
    char arr1[50] = {'m','a','a','z','\0','a'};
    string arr2 = "maaz\0a";
    cout << arr1 << endl;
    cout << arr2 << endl;
}