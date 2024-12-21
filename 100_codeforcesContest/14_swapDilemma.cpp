#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Helper function to check if two arrays are permutations of each other
bool arePermutations(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    unordered_map<int, int> count_a, count_b;
    for (int i = 0; i < a.size(); ++i) {
        count_a[a[i]]++;
        count_b[b[i]]++;
    }
    return count_a == count_b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Check if a and b are permutations of each other
    if (!arePermutations(a, b)) {
        cout << "NO" << endl;
        return;
    }

    // Check if the relative positions can be adjusted by sorting to match each other
    // This means that the relative order of equivalent groups must be the same.
    vector<pair<int, int>> pos_a(n), pos_b(n);
    for (int i = 0; i < n; ++i) {
        pos_a[i] = {a[i], i};
        pos_b[i] = {b[i], i};
    }

    // Sort based on the values to compare positions
    sort(pos_a.begin(), pos_a.end());
    sort(pos_b.begin(), pos_b.end());

    for (int i = 0; i < n; ++i) {
        if (pos_a[i].first != pos_b[i].first || pos_a[i].second % 2 != pos_b[i].second % 2) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
