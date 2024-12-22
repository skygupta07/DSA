#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
vector <int> dp(1000005, -2);  // -2 means the state not computed


int f(int x){   // fn f will calculate the min. no. of coins required to 
                    // sum upto x...
    if (x==0) return 0;
    if (dp[x]!= -2) return dp[x];   // if already computed then return directly from dp
    // traversing over each coin
    int result = INT_MAX;   // trick to find min. value-> i.e. first initialise it with
                            // min. value then compare it with other
    for (int i=0; i<coins.size(); i++){
        if (x-coins[i]<0) continue;
        result = min(result, f(x-coins[i]));
    }

    if (result == INT_MAX) return dp[x] = INT_MAX;  // it means ek bhi coins use nahi ki
    return dp[x] = 1 + result;
}


int main(){
    int n,x;
    cout<<"enter number of coins (n) and target sum (x): ";
    // n = number of coins   x = target sum
    cin>>n>>x;

    for (int i=0; i<n; i++){
        int cost;
        cin>>cost;
        coins.push_back(cost);  
    }
    int ans = f(x);
    if (ans == INT_MAX) cout<<"-1\n";
    else cout<<ans<<"\n";
    return 0;
}

/*
coins vector given, int x, 
to print min. no. of coins required to sum up to x...



*/