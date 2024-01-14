#include<iostream>
using namespace std;

void reverseCount (int n) {
    //base condition
    if(n == 0){
        return;
    }

    cout << n << " ";
    
    reverseCount(n-1);
}

int main() {

    cout << "Enter the number to count in reverse from: " << endl;
    int n;
    cin >> n;

    reverseCount(n);
    cout << endl;
    return 0;
}