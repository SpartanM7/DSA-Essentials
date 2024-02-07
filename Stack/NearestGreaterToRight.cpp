#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

vector<int> NearestGreaterRight(vector<int>& arr){
    stack<int> s;
    vector <int> ans;
    for(int i = arr.size() - 1; i >= 0 ; i--){
        if(s.empty()) {
            ans.push_back(-1);
            s.push(arr[i]);
        }
        else if(!s.empty() && arr[i] < s.top()){
            ans.push_back(s.top());
            s.push(arr[i]);
        }
        else{
            while(!s.empty() && arr[i] >= s.top()){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top()); 
                s.push(arr[i]);
            }
           
        }
    }
    reverse(ans.begin() , ans.end());
    for(auto x : ans){
        cout << x << " ";
    }
    return ans;
    
};


int main()
{
    vector<int> input = {2,3,4,1,5};
    NearestGreaterRight(input);
    
    return 0;
}