#include <iostream>
using namespace std;


int main(){
    int a,b,t;
    cout<<"enter two numbers:"<<endl;
    cin>>a>>b;
    t = a;
    a = b;
    b = t;

    cout<<"swapped numbers are: "<<endl;
    cout<<a<<" "<<b<<endl;
}