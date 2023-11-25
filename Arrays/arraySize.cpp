// difference in size between the array in main function and when it is passed to another function via reference
#include <iostream>
using namespace std;

void printArray(int arr[]){
    
    cout<<"In function "<< sizeof(arr) <<endl;
    int n = sizeof(arr)/sizeof(int);
    cout<< n << endl;
}


int main() {
    int arr[6] = {1,2,3,4,5,6};

    int n = sizeof(arr)/sizeof(int);

    cout<<"in main function " << sizeof(arr) <<endl;
    printArray(arr);

}