#include<iostream>
#include<string>
using namespace std;

int lastOccurence(string s, int& n, int& i, int& index, char& key){
    for (; i <= n; i++){
        if(s[i] == key)
        index = i;
    }
    return index;
}

int lastOccurenceRecursive(string s, int n, int& i, int& index, char& key){
    if(i > n){
    return index; }

    if(s[i] == key){
    index = i;  }

    return lastOccurenceRecursive(s, n, ++i, index, key);
}


int main() {

    string s = "abcddefdh";
    int n = s.length();
    int i = 0;
    int index = 0;
    char key = 'h';
    int ans1 = lastOccurence(s, n, i, index, key);
    cout << "THe answer we get without recursion : " << ans1 << endl;
    // might not work cus we will change the string and i
    i = 0;
    int ans2 = lastOccurenceRecursive(s, n,i, index, key);
    cout << "The answer we get after using recursion : " << ans2 << endl;
    return 0;

}