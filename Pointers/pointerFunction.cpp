#include<iostream>
using namespace std;

int* solve() {
    int a  = 5;
    int* ans = &a;
    cout << "The output of Solve function: " << ans << endl; 
    return ans;
}


int main() {
    cout << "The main function output: " << solve() << endl;
}