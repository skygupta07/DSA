#include <bits/stdc++.h> 
using namespace std;

vector<int> getAllDivisors(int n) {
    vector<int> ans;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) { // Avoid duplicate for perfect square
                ans.push_back(n / i);
            }
        }
    }

    sort(ans.begin(), ans.end()); // Ensure divisors are sorted
    return ans;
}

int main() {
    int n = 36; // Example input
    vector<int> divisors = getAllDivisors(n);
    
    for (int d : divisors) {
        cout << d << " ";
    }
    return 0;
}
