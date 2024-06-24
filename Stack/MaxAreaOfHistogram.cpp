#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{

    public:
    vector<int> NSR(vector<int>& a, int psuedoEnd){
        stack<pair<int , int>> s;
        vector<int> right;
        psuedoEnd = 7;
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
                while(!s.empty() && s.top().first > a[i]){
                    s.pop();
                }
                if(s.empty()) right.push_back(psuedoEnd);
                else right.push_back(s.top().second);
                s.push({a[i], i});
            }
        }
        reverse(right.begin() , right.end());
        return right;
    }

    vector<int> NSL(vector<int>& a, int psuedoEnd){
        stack<pair<int , int>> s;
        vector<int> left;
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
                while(!s.empty() && s.top().first > a[i]){
                    s.pop();
                }
                if(s.empty()) left.push_back(psuedoEnd);
                else left.push_back(s.top().second);
                s.push({a[i], i});
            }
        }
        return left;
    }

    int MAH(vector<int>& a){
        stack<int> s;
        vector<int> right(a.size(), a.size());
        vector<int> left(a.size(), -1);
        vector<int> area(a.size());

        // Greatest smaller to left
        for(int i = 0; i < a.size(); i++){
            while(!s.empty() && a[s.top()] >= a[i]){
                s.pop();
            }
            if(!s.empty()){
                left[i] = s.top();
            }
            s.push(i);
        }
        s = stack<int>();
        
        //Greater smaller to right
        for(int i = a.size()-1; i >= 0;  i--){
            while(!s.empty() && a[s.top()] >= a[i]){
                s.pop();
            }
            if(!s.empty()){
                right[i] = s.top();
            }
            s.push(i);
        }
        for(int i = 0; i < a.size(); i++){
            area[i] = a[i] * (right[i] - left[i] -1);
        }
        return  *max_element(area.begin(), area.end());
    }

};

int main()
{
    vector<int> a = {6,2,5,4,5,1,6}; // test case
    int psuedoEnd;
    Solution s; //creating an instance of the class
    // vector<int> right = s.NSR(a, psuedoEnd); //right limit vector
    // vector<int> left = s.NSL(a, psuedoEnd); // left limit vector
    // vector<int> ans(a.size()); // why? -> cuz we are using the index of an empty vector with no elements
    // for(int i = 0; i < a.size() ; i++){
    //     ans[i] = a[i] * (right[i] - left[i] -1);
    //     cout << ans[i] << " ";
    // }
    // cout << "\n" << *max_element(ans.begin() , ans.end());
    cout<< s.MAH(a) << endl;
    return 0;
}