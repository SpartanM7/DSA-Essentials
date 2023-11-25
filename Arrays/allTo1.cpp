// code to change every element of an array to 1
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1,3,5,7,9};
    for (int i = 0; i < 5; i++){
        arr[i] = 1;
        cout << arr[i] << " ";
    }
    return 0;
}