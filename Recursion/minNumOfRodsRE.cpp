#include<iostream>
#include<limits.h>
using namespace std;

int solve(int n, int x, int y, int z){

    if(n == 0)
    return 0;

    if(n < 0)
    return INT_MIN;

    int ans1 = solve(n-x, x, y, z) + 1; //+ 1 is given due to the there are 2 parts of rods present -> 1. x lenght , 2. n-x lenght 
    int ans2 = solve(n-y, x, y, z) + 1;
    int ans3 = solve(n-z, x, y, z) + 1;

    int ans = max(ans1, max(ans2, ans3));
    return ans;

}


int main(){

    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = solve(n, x, y, z);

    // there can be 2 ans -> 1. when n < 0 that gives INT_MIN + 1 i.e -ve value thus INVALID SOLUTION
    // 2. when n >= 0 it will give some non-negative value, valid VALID SOLUTION
    // that is why we are checking it before printing the ans.
    (ans < 0) ? ans = 0 : ans;
    
    cout << "The max number of rods are : " << ans << endl;
    return 0;
}