#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    // Read grid a
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }

    // Read grid b
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            b[i][j] = x - '0';
        }
    }

    // Check if they are equal modulo 3
    bool possible = true;
    for (int i = 0; i < n && possible; ++i) {
        for (int j = 0; j < m && possible; ++j) {
            if (a[i][j] % 3 != b[i][j] % 3) {
                possible = false;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
