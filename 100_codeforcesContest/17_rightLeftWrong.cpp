#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;

    vector <int> v(n);
    for (int i=0; i<n; i++) cin>>v[i];

    vector <char> s(n);
    for (int i=0; i<n; i++) cin>>s[i];

    int i = 0;
    int j = n-1;

    int left = 0, right = 0;

    
        while (i<=n-1 && s[i] != 'L') i++;
        while (j>=0 && s[j] != 'R') j--;

        
    

    int sum = 0;
    for (int k = i; k<=j; k++){
        sum += v[k];
    }

    cout<<sum<<endl;

 }



int main(){
    int t;
    cin>>t;

    while (t--) solve();
}