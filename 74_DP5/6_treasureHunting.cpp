#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX;

// DP array jo store karega minimum XOR sum ke results
vector <vector <long long>> dp;

int allSet; // Ye variable store karega ek mask jo batayega ki saare elements set ho gaye hain

// Recursive function jo minimum XOR sum calculate karega
long long helper(vector <int> &a, vector <int> &b, int n, int idx, int mask){
    // Base case: agar saare elements set ho gaye hain, toh minimum XOR sum 0 hoga
    if (mask == allSet) return 0;

    // DP ka use: agar pehle se computed hai toh directly return kar do
    if (dp[idx][mask] != -1) return dp[idx][mask];

    // Minimum XOR sum find karne ke liye initially INF set karte hain
    long long ans = INF;

    // Saare elements par iterate karna hai
    for (int i=0; i<n; i++){
        // Agar i-th element use nahi hua hai (mask check kar ke dekhte hain)
        if ((mask & (1 << i)) == 0){
            // XOR sum calculate kar rahe hain aur recursion se next step par ja rahe hain
            long long xorSum = (a[idx] ^ b[i]) + helper(a, b, n, idx + 1, mask | (1 << i));

            // Minimum value update kar rahe hain
            ans = min(ans, xorSum);
        }
    }

    // DP array ko update karna zaroori hai taaki baad mein reuse ho sake
    return dp[idx][mask] = ans;
}

// Solve function jo input lega aur answer compute karega
void solve(){
    int n; 
    cin>>n;

    vector <int> a(n), b(n);

    // Pehli array input le rahe hain
    for (int i=0; i<n; i++) cin>>a[i];

    // Dusri array input le rahe hain
    for (int i=0; i<n; i++) cin>>b[i];

    // DP array initialize kar rahe hain -1 se (matlab abhi tak kuch compute nahi kiya)
    dp = vector <vector <long long>> (n, vector <long long> (1 << n, -1));

    // Saare elements ke set hone ka bitmask
    allSet = (1 << n) - 1;

    // Helper function ko call karke final answer print kar do
    cout<<helper(a, b, n, 0, 0) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) solve(); // Sirf ek test case run kar rahe hain

    return 0;
}
