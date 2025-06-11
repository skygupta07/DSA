// frogJump2BottomUp.cpp

#include <bits/stdc++.h>
using namespace std;

vector <int> h;
int k;
vector <int> dp;


int fbu(){  // no parameters needed
    int n = h.size();
    dp.resize(10005 , INT_MAX);
    // base case
    dp[n-1] = 0;    // last se last par pahuchne ki cost zero..


    // second last stone se agar last stone pe pahuchna hota..
    // third last stone se last stone tak pahuchta  1 or 2 or 3 steps leke aage....
    // steps wala case j wala loop handle kar raha hai...
    for (int i=n-2; i>=0; i--){
        for(int j=1; j<=k; j++){
            if (i+j >= h.size()) break;
            dp[i] = min(dp[i] , abs(h[i] - h[i+j]) + dp[i+j]);
        }
    }
    return dp[0];
}


int main(){
    int n;
    cin>>n>>k;
    h.resize(n);

    for (int i=0; i<n; i++) cin>>h[i];
    cout<<fbu()<<"\n";
    return 0;


}