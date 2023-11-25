#include <iostream>
using namespace std;

bool BinarySearch(int arr[][4], int n, int m, int target){
    int s = 0;
    int e = n*m-1;
    int mid = s + (e-s)/2;

    while(s <= e){
        int rowIndex = mid/m;
        int columnIndex = mid%m;

        if(arr[rowIndex][columnIndex] == target){
            cout << "Target was found at: " << rowIndex << columnIndex << endl;
            return true;
        }
        if (arr[rowIndex][columnIndex] < target)
        {
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e - s)/2;
    }
    return false;
}

int main(){

    int arr[5][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20}};
    int rows = 5;
    int columns = 4;
    int target;
    cout << "Enter the element to be searched: " << endl;
    cin >> target;

    bool ans = BinarySearch(arr, rows, columns, target);

    if(ans){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }
    return 0;
}