#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    unordered_map <char, int> mp;
    
    for (auto ch: s){
        mp[ch]++;
    }
    
    int count = 0;
    for (auto el: mp){
        if (el.second >= n && el.first != '?') count++;
    }
    cout<<count<<"\n";
}




int main(){
    int t; 
    cin>>t;

    while (t--){
        solve();
    }
}