#include <iostream>
using namespace std;

void print(int n){
    if (n==0) return;  //base case -> issey pehle waale element tak print hoga 
            // jaise hi ye condition hit hui fn return kar jaega neeche execute 
    // nahi karega...
    cout<<n<<" ";  // kaam
    print(n-1);     // fn call
}


int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    print(n);
}
