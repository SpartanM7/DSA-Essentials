#include<iostream>
using namespace std;

void printDigits(int& n){
    
    //base condition
    if(n == 0){ 
        return;
    }
    // cout << n%10 ; this will print the values in the reverse order as we are printing the remainder or the value at the TENTH'S PLACE
    int newN = n/10;
    // recursive relation
     printDigits(newN);
    
    //putting COUT here will print the value in non-reverse order as it is head recursion and the last function call will start giving the ooutput first 
    cout << n%10 ;  
}



int main() {


    // here if we give input leading with 0, it will take it as OCTAL NUMBER. e.g: 0647(octal) = 423(decimal)
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;

    printDigits(n);
    cout << endl;
    return 0;
}