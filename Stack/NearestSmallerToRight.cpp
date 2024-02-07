#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> NearestSmallerRight(vector<int>& a){
    vector<int> ans;
    stack<int> s;
    for(int i = a.size() - 1 ; i >= 0; i--){
        if(s.empty()){
            ans.push_back(-1);
            s.push(a[i]);
        }
        else if(!s.empty() && s.top() < a[i]){
            ans.push_back(s.top());
            s.push(a[i]);
        }
        else{
            while(!s.empty() && s.top() >= a[i]){
                s.pop();
            }
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top());
        }
        s.push(a[i]);
    }
    return ans;
    
}


int main()
{
    vector<int> a = {5,2,3,4,1,6,8};
    vector<int> result = NearestSmallerRight(a);    
    reverse(result.begin(), result.end());
    for(auto x : result){
        cout << x << " ";
    }
    return 0;
}