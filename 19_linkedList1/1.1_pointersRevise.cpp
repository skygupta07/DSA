#include <bits/stdc++.h>
using namespace std;


int main(){

    int x = 5;
    // storing the address of x into a special kind of variable called pointer variable
    int* ptr = &x;  // asked in interview
    // printing the value of integer x using the dereference operator...
    cout<<*ptr<<"\n";

    // changing the variable x using its pointer only...
    *ptr = 7;
    cout<<*ptr<<"\n";
    cout<<x<<"\n";
    
}