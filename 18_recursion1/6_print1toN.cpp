#include <iostream>
using namespace std;

void print (int i, int n){  // i.e. by using extra variable                          
    if (i>n) return; // base case
    cout<<i<<" ";  // kaam
    print (i+1, n);  // fn call
}

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    print(1,n);
}




 














