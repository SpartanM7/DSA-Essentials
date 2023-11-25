#include <iostream>
using namespace std;

int main() {

    int i, arr[10],n;
    
    cout << "Enter the number of the array elements:" << endl;
    cin >> n;
    cout << "Enter the array:" << endl;

    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(i = n-1; i >= 0; i--){
        cout << arr[i];
    }
    cout << endl;
    return 0;
}