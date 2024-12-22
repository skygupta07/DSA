#include <iostream>  // fibonacci space optimised 
#include <vector>
using namespace std;

// instead of maintaining the whole dp array just store the last two variables

vector<int> dp;  // what is its use here ,if we remove then program not working

int fib(int n){
    int a = 0;
    int b = 1;

    if (n==0 || n==1) return n;
    int c;
    int i = 2;
    while(i<=n){
        c = a+b;
        a = b;
        b = c;
        i++;
    } 
    return c;
}


int main(){
    int n;
    cout<<"enter the value of n: ";

    cin>>n;
    cout<<fib(n)<<" ";
}