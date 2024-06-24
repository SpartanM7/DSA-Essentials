#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution{

    public:
    int MAH(vector<int>& a, int size){
        vector<int> right,left, ans(a.size());
        stack<pair<int, int>> s;
        // Nearest Smaller to Right
        int psuedoEnd = 4;
        for(int i = a.size()-1; i >= 0; i--){
            if(s.empty()) {
                right.push_back(psuedoEnd);
                s.push({a[i], i});
            }
            else if(!s.empty() && s.top().first < a[i]){
                right.push_back(s.top().second);
                s.push({a[i],i});
            }
            else{
                while(!s.empty() && s.top().first >= a[i]){
                    s.pop();
                }
                if(s.empty()) right.push_back(psuedoEnd);
                else right.push_back(s.top().second);
                s.push({a[i], i});
            }
        }
        reverse(right.begin() , right.end());

        s = stack<pair<int, int>>();
        psuedoEnd = -1;
        for(int i = 0; i < a.size(); i++){
            if(s.empty()) {
                left.push_back(psuedoEnd);
                s.push({a[i], i});
            }
            else if(!s.empty() && s.top().first < a[i]){
                left.push_back(s.top().second);
                s.push({a[i],i});
            }
            else{
                while(!s.empty() && s.top().first >= a[i]){
                    s.pop();
                }
                if(s.empty()) left.push_back(psuedoEnd);
                else left.push_back(s.top().second);
                s.push({a[i], i});
            }
        }
        for(int i = 0; i < a.size(); i++){
            ans[i] = a[i] * (right[i] - left[i] - 1);
        }
        return *max_element(ans.begin(), ans.end());
    }
};

int main()
{   
    int M[4][4] = {{1,0,0,0},{0,1,1,1},{0,0,1,0},{0,1,1,1}};
    int n = 4;
    int m = 4;
    Solution s;
    vector<int> height;
        int ans = INT_MIN;
        for(int i = 0; i < m; i++){
            height.push_back(M[0][i]);
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == n-1 && M[i][j] == 0){
                    height[j] = 0;
                }
                else{
                    height[j] += M[i][j];
                }
                
            }
            int temp = s.MAH(height, m);
            ans = max(ans,temp);
        }
        cout << ans<<endl;
    
    return 0;
}

