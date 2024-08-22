#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cout<<"enter number n:";

    cin>>n; 
    // 32 bit (4bytes) ke size mai aapke integer ki binary representation show 
    // kar dega...
    cout<<bitset<32>(n)<<endl;
}

/*
kisi bhi number (positive, negative, float(round off to integer kar dega..)) 
ki binary representation chahiye ho to bitset <32> (n)
 ko yadd karna hoga...
*/