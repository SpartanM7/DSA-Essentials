#include<iostream>
using namespace std;
int l = 0;
int ans = 0;

int subs(string a, string b, int n, int m)
{
    
    // base condition
    if(n == 0 || m==0)
    {
        return 0;
    }
    if(a[n-1] == b[m-1])
    {
        l = 1+subs(a, b, n-1,m-1);
        return ans = max(ans,l);
    }
    else
    {
        l = 0;
        return max(subs(a, b, n-1,m), subs(a, b, n,m-1));
    }
}
int main()
{
    string a = "hars";
    string b = "gyanes";

    int n = a.length();
    int m = b.length();

    int len = subs(a,b,n,m);
    cout<< len;
    return len;
}
