#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NearestSmallerLeft(vector<int>& a){
    vector<int> ans;
    stack<int> s;
    for(auto x: a){
        if(s.empty()) {
            ans.push_back(-1);
            s.push(x);
        }
        else if(!s.empty() && s.top() < x){
            ans.push_back(s.top());
            s.push(x);
        }
        else{
            while(!s.empty() && s.top() >= x){
                s.pop();
            }
            if(s.empty()) {
                ans.push_back(-1);
                s.push(x);
            }
            else{
                ans.push_back(s.top());
                s.push(x);
            }
        }
    }
    return ans;
}


int main(){

    vector<int> a = {5,2,3,4,1,6,8};
    vector<int> result = NearestSmallerLeft(a);
    for(auto x : result){
        cout << x << " ";
    }
    return 0;
}