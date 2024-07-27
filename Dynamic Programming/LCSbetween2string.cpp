#include<iostream>
using namespace std;

string main()
{
        string text1 = "abcde";
        string text2 = "ace";
        int n = text1.length();
        int m = text2.length();
        int i , j;
        int t[n+1][j+1];
        string ans;
        memset(t,0,sizeof(t));

        for(i = 1; i<= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        while( i != 0 && j != 0)
        {
            if(text1[i] == text2[j])
            {
                ans.push_back(text1[i]);
                i--;
                j--;
            }
            else
            {
                if(t[i-1][j] < t[i][j-1])
                {
                    j--;
                }
                else {
                    i--;
                }
            }
        }
        ans = reverse(ans.begin() , ans.end());
        return ans;
    
}