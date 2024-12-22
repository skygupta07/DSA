#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
#define ll long long int

// ha define wali line mai... aapka ; semicolon nahi aata...

vector <ll> dp(1e7+5, -1);

ll f(int n){    // calculates all possible ways to sum upto n when a dice is thrown
    if (n==0) return 1; // empty subset count as 1 -> base case 
        // one way is mat feko dice...

    if (dp[n] != -1) return dp[n];
    int sum = 0;

    // go and check each dice face
    for (int i=1; i<=6; i++){
        if (n-i < 0) break; // break because aage ke dice ke move se to aur negative result aaega
        sum = (sum%mod + f(n-1)%mod)%mod;  // initial sum and final sum                      
    }
    return dp[n] = sum%mod;
}


int main(){
    int n;
    cout<<"enter n: \n";
    cin>>n;
    cout<<f(n)<<"\n";
    return 0;
}


/*
loop ki intuition laane ke liye mene sigma ke terms mai likha and then..
constraints bhi lagaye...


*/