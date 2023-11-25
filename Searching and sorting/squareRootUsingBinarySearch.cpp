// this program will find the square root of the number    

#include<iostream>
using namespace std;
#include<algorithm>

int findSqrt( int n){
    int start = 0;
    int end = n;
    int mid = start + (end-start)/2; 
    int ans = -1;
    while (start < end)
    {
        if(mid*mid == n){
            return mid;
        }
        else if (mid*mid > n)
        {
            end = mid-1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
    

int main(){
    int n;
    cout << "Enter the number to find the square root:" << endl;
    cin >> n;
    int ans = findSqrt(n);
    cout << "The interger part of the square root is: " << ans << endl;        

    // adding the precision part
    int precision;
    cout << "Enter the number of values after the decimal :" << endl;
    cin >> precision;
    double finalAns = ans;
    double step = 0.1; 
    for( int i = 0; i < precision; i++){

        for (double j= finalAns; j*j<=n; j=j+step)
        {
            finalAns = j;
        }
      step = step/10;  
    }
    cout << "The final answer is : " << finalAns << endl;

    return 0;    
    
}
