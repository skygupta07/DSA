// reduceToOneInMinSteps.cpp

#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1e5, -1);

int steps(int x) {
    // number 2 se chota to no steps needed
    if (x < 2) return 0;

    // dp help
    if (dp[x] != -1) return dp[x];


    int a = INT_MAX, b = INT_MAX, c = INT_MAX;

    if (x % 2 == 0) a = steps(x / 2);
    if (x % 3 == 0) b = steps(x / 3);

    c = steps(x - 1);

    dp[x] = 1 + min(a, min(b, c));
    
    // here dp[x] will store the minimum steps required to convert x to 1...
    return dp[x];
}


int main() {
    int n = 17;
    cout << "Minimum steps to reduce " << n << " to 1: " << steps(n) << endl;
    return 0;
}
