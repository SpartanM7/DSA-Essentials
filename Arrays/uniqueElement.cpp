// method 1. using binary XOR (1^1=0)
#include <iostream>
using namespace std;

int main() {

    int n, arr[10], i, ans=0;
    cout << "Enter the no. of elements you want to put in the array:" << endl;
    cin >> n;
    cout << "Enter the elements of the array:" << endl;
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(i =0; i < n; i++){
        ans = ans^arr[i];
        cout << ans << endl;
    }
    cout << "The unique element in the array is :" << ans << endl;

    return 0;
}