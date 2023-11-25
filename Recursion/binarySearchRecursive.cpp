#include<iostream>
using namespace std;
#include<vector>

int binarySearch(vector<int> &arr, int& n, int s, int e,int& key){
    if(s > e){
        return -1;
    }
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid] == key){
            return mid;
        }
        // using TERNARY OPERATOR
        return (arr[mid] > key) ? binarySearch(arr, n, s, mid-1, key) : binarySearch(arr, n, mid+1, e, key);
        // if (arr[mid] > key){
        //     e = mid-1;
        //     binarySearch(arr, n, s, e, key);
        // }
        // else{
        //     s = mid+1;
        //     binarySearch(arr, n, s, e, key);
        // }
    }
}

int main() {


    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int key;
    cout << "Enter the value to be search: " << endl;
    cin >> key;

    int ans = binarySearch(arr, n, s, e,key);
    (ans >= 0) ? cout << "The index of the searched item is : " << ans << endl : cout << "Target not found.";
    
    return 0;
    
}