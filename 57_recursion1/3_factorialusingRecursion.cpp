#include <iostream>
using namespace std;

int fact = 1;

int factorial(int n){
    if (n==1 || n==0) return 1;  //base case..
    
    return n*factorial(n-1);  // abhi function khatam hi nahi hua tha 
                                    // ussey pehle hi call laga diya..
}


int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;

    cout<<factorial(n);
}