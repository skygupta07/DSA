#include <iostream>
using namespace std;

int powIterative(int a, int b){
    int ans = 1;
    // a power b means multiply a b times...
    for (int i=0; i<b; i++){
        ans *= a;
    }
    return ans;
}


int power(int a, int b){ // recursive
    if (b==0) return 1;
    else if (b==1) return a;
    else return a*power(a, b-1);  // decreasing fn..
}


int main(){
    int a,b;
    cout<<"enter base: ";
    cin>>a;
    cout<<"enter power: ";
    cin>>b;

    cout<<power(a,b)<<endl;
    cout<<powIterative(3,4)<<endl;
}


