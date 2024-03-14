#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c){
    // number of discs, source, helper, destination..
    // algorithm
    // 1. move n-1 disc from source to helper using destination
    //2. move nth disc from source to destination
    // 3. move n-1 disc from helper to destination.. using source
    if (n==0) return; // base case
    
    hanoi(n-1 , a,c,b); //step 1. fn call
    
    cout<<a<<"->"<<c<<endl; // kaam
    hanoi(n-1, b,a,c); //step 3.  // fn call
}

int main(){
    cout<<"possible ways are"<<endl;
    hanoi(3,'A','B','C');
}