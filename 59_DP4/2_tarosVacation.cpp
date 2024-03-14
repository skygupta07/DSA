#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;  // no. of days
    cin>>n;
    vector<vector <int> > dp(n, vector<int> (3,0)); // initialised with zero happiness

    // base case
    int a,b,c;  // a->0, b->1, c->1 
    cin>>a>>b>>c;
    dp[0][0] = a;   // 0th day par 0th activity choose karne par a happiness
    dp[0][1] = b;
    dp[0][2] = c;

    for (int i=1; i<n; i++){    // fbu
        cin>>a>>b>>c;
        // if we choose 0th (or activity a) on ith day then surely we would have
        // chosen activity 1 or 2 (b or c) on i-1 th day whichever is maximum...
        dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]); 
        dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]); 
        dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]); 

    }
    cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));

    return 0;

}



/*

Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the 
following activities and do it on the i-th day:

A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains


fbu (function bottom up) likha as to compute the ith state we need to compute the i-1 th
state as well...

-> here 2d vector will be required because to identify each state two variables are 
required...ith day and activity number also..
*/