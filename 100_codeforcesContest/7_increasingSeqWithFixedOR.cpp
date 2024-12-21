#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;

        vector<unsigned long long> sequence;
        unsigned long long current = 0;

        // Generate sequence starting from the smallest number 1
        for (unsigned long long i = 1; i <= n; ++i) {
            if ((current | i) == n) {
                sequence.push_back(i);
                current = i;
            }
        }

        // Output the results
        cout << sequence.size() << endl;
        for (unsigned long long num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
