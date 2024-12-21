#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    int operations = 0;

    // Special case when n is already 1
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    while (n > 1) {
        if (n % k == 0) {
            cout<<n/k + 1 <<endl;
            return;
        } else {
            int remainder = n % k;
            operations += remainder;
            n -= remainder;
        }
    }
    
    cout << operations << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
