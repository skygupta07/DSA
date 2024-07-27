#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

vector <ll> factorial(int n){
    vector <ll> fact(n+1, 1);
    fact[0] = 1;
    fact[1] = 1;

    for (int i=2; i<=n; i++){
        fact[i] = ((i%mod)*(fact[i-1]%mod))%mod;
    }

    return fact;
}

int main(){
    vector <ll> res = factorial(25);
    
    // display
    for (int i=0; i<res.size(); i++){
        cout<<i<<"! = "<<res[i]<<"\n";
    }
}