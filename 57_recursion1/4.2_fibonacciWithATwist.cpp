#include <bits/stdc++.h>
using namespace std;


int solve(int n, vector <int> &dp){
    // base case 
    if (n == 0) return 5;
    if (n == 1) return 3;

    // dp help
    if (dp[n] != -1) return dp[n];

    if (n % 2 == 0) return dp[n] = ( solve(n-1, dp) * solve(n-2, dp) ) % 999;
    else return dp[n] = ( solve(n - 1, dp) + solve(n - 2, dp) ) % 998;
}


int calculateX(int n) {
    vector <int> dp(n+1, -1);
    return solve(n, dp);
}

int main() {
    int N;
    std::cin >> N;  // Read the single integer input
    int result = calculateX(N);
    std::cout << result << std::endl;  // Print the result
    return 0;
}