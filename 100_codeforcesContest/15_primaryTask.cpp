#include <bits/stdc++.h>
using namespace std;



void solve(){
    int x; 
    cin>>x;

    string num = atoi(x);

    if (num.length() < 3){
        cout<<"no"<<endl;
        return;
    } 

    int base = (num[0] - '0') * 10 + (num[1] - '0');
    int power = 0;

    int i = 2;
    while (num[i] != '\n'){
        power *= 10;
        power += num[i];
    }

    // check both base and power

    if (base == 10 && power >= 2){
        cout<<"yes"<<endl;
        return;
    }

    else{
        cout<<"no"<<endl;
        return;
    }


}









int main(){
    int t;
    cin>>t;

    while(t--) solve();
}