#include<iostream>
#include<string>
using namespace std;

int main() {
    string s = "pwwkew";
    string output;
    cout << output.empty() << endl;
    for(int i = 0; i < s.length() ; i++){
        if(output.find(s[i]) == std::string::npos){
            output.push_back(s[i]);
        }
        
    }
    cout << output << endl;
    return 0;

}