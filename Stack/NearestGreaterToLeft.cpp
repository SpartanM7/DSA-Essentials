#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector <int> NearestGreaterLeft(vector<int>& a){
    vector<int> ans;
    stack<int> s;
    for(int i = 0 ; i < a.size() ; i++){
        if(s.empty()){
            ans.push_back(-1);
            s.push(a[i]);
        }
        else if(!s.empty() && s.top() > a[i]){
            ans.push_back(s.top());
            s.push(a[i]);
        }
        else{
            while(!s.empty() && s.top() <= a[i]){
                s.pop();
            }
            if(s.empty()) ans.push_back(-1);
            else{
                ans.push_back(s.top());
                s.push(a[i]);
            }
        }
    }
    for(auto x: ans){
        cout << x << " " ;
    }
    return ans;
}


int main(){

    vector<int> a = {5,2,3,4,1};
    // for(auto x : a){
    //     cin >> x ;
    // }
    NearestGreaterLeft(a);

}