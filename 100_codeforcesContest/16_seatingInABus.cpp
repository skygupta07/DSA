#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; 
    cin>>n;

    int prev, curr;

    bool flag = true;

    for (int i=0; i<n; i++){
        if (i == 0) cin>>prev;
        else{
            cin>>curr;

            if (curr != prev-1 || curr != prev+1){
                flag = false;
                break;
            } 
            prev = curr;
        }
    }

    if (flag == true) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return;
}










int main(){
    int t;
    cin>>t;
    
    while(t--) solve();

    return 0;
}