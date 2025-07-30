#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cout<<"enter number n:";

    cin>>n; 
    // 32 bit (4bytes) ke size mai aapke integer ki binary representation show 
    // kar dega...
    cout<<bitset<32>(n)<<endl;

    cout<<0b1010<<endl;  // 10   - accha matlab 0b aage laga dene se binary representation mai convert kar dega...
}

/*
kisi bhi number (positive, negative, float(round off to integer kar dega..)) 
ki binary representation chahiye ho to bitset <32> (n)
 ko yadd karna hoga...
*/