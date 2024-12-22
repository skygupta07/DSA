#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector <int> h;
int k;  // jaan bhuj ke global kar diya taaki har jagah paas na karna pade...

vector <int> dp(100005, -1);    // change 1 -> dp ko waise mai state gin ke n ya n+1 around state mai 
                                // bhi kaam chala sakta tha....but competitive programming mai jaldi jaldi karte waqt bina jyada dimag laga max constraint size se 5 bada 
                                // size ka aur dp bana dete hai....

int f(int i){   // f(i) calculates the minimum cost required to reach nth position starting from ith position...

    if (i >= h.size()) return INT_MAX;  // as you can't return from that stone
    if (i == h.size()-1) return 0;  // last se last tak pahuchne ki cost zero
    
    if (dp[i]!= -1) return dp[i];   // change 2

    int ans = INT_MAX;
    for (int j=1; j<=k; j++){
        if ( i+j >= h.size()) break;
        ans = min ( ans , abs(h[i] - h[j]) + f(i+j));
    }
    return dp[i] =  ans;    // change-3 -> ha hum dp[i] mai store bhi karte hai and return bhi karte hai...

}
// f(i) calculates the min. cost to reach the final stone starting from ith stone



int main(){
    int n;
    cout<<"enter number of stones ";
    cin>>n;
    
    cout<<"enter max jump size allowed ";
    cin>>k;
    
    h.resize(n);
    
    cout<<"enter the height of stones ";
    for (int i=0; i<n; i++) cin>>h[i];

    cout<<f(0)<<"\n";
    return 0;

}









/*
recurrence ko clean rakhne ke liye bas wahi parameters pass karey jo change ho rahe ho 
next call mai ...aur dusro ko you can put it as globally...

min. cost to reach the final stone starting from ith stone = 
min. ( (cost to reach the last stone from i+1 or i+2, or i+3 ) + (cost to reach that state) )

i.e, zeroth stone se last stone tak pahuchne ki cost is 1 se last tak pahuchne ki min. cost +
cost to reach the oneth stone or    2nd stone se last tak pahuchne ki min. cost + cost to
reach the second stone    => aur in sab cases mai jo sabse min. hoga wo path lenge


    tree banaya pura yaha bhi 

        0
        / \
       1 2 3
      /\ \   \
    234   34  4
*/