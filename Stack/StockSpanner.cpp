#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> StockSpanner(vector<int>& prices){
    vector<int> ans;
    stack<pair<int , int>> s;
    for(int i = 0; i < prices.size() ; i++){
        if(s.empty()){
            ans.push_back(-1);
            s.push({prices[i], i});
        }
        else if(!s.empty() && s.top().first >= prices[i]){
            ans.push_back(s.top().second);
            s.push({prices[i], i});
        }
        else{
            while(!s.empty() && s.top().first < prices[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top().second);
            }
            s.push({prices[i], i});
        }
    }
    return ans;
};

vector<int> BruteStockSpanner(vector<int>& prices){
    vector<int> ans;
    int cnt;
    for(int i = 0; i < prices.size() ; i++){
        cnt = 1;
        int j = i-1;
        while(prices[i] > prices[j] && j>=0){
            cnt++;
            j--;
        }
        ans.push_back(cnt);
    }

    return ans;
};


int main(){

    vector<int> prices = {100,80,60,70,60,75,85};
    // vector<int> result = StockSpanner(prices);
    vector<int> result = BruteStockSpanner(prices);
    for(int i = 0; i < result.size() ; i++){
        result[i] = i - result[i];
        cout << result[i] << " ";
    }

    return 0;
}