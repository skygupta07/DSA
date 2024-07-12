#include <bits/stdc++.h>
using namespace std;

// Function to find the smallest subarray starting from 'start_idx' with at least 'min_sum' sum
int findSubarray(const vector<int>& prefix_sums, int start_idx, int min_sum, int n) {
    for (int end_idx = start_idx; end_idx < n; ++end_idx) {
        if (prefix_sums[end_idx] - (start_idx > 0 ? prefix_sums[start_idx - 1] : 0) >= min_sum) {
            return end_idx;
        }
    }
    return -1;
}

// Function to process each test case
void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    int totalSum = accumulate(a.begin(), a.end(), 0);
    int min_sum = (totalSum + 2) / 3; // Ceiling division to find the minimum required sum for each person

    vector<int> prefix_a(n), prefix_b(n), prefix_c(n);
    prefix_a[0] = a[0];
    prefix_b[0] = b[0];
    prefix_c[0] = c[0];

    for (int i = 1; i < n; i++) {
        prefix_a[i] = a[i] + prefix_a[i - 1];
        prefix_b[i] = b[i] + prefix_b[i - 1];
        prefix_c[i] = c[i] + prefix_c[i - 1];
    }

    int la = -1, ra = -1, lb = -1, rb = -1, lc = -1, rc = -1;
    bool found = false;

    // Try to find valid subarrays for Alice, Bob, and Charlie
    for (la = 0; la < n; ++la) {
        ra = findSubarray(prefix_a, la, min_sum, n);
        if (ra == -1) continue;

        for (lb = ra + 1; lb < n; ++lb) {
            rb = findSubarray(prefix_b, lb, min_sum, n);
            if (rb == -1) continue;

            lc = rb + 1;
            rc = findSubarray(prefix_c, lc, min_sum, n);
            if (rc != -1 && rc >= lc) {
                cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << "\n";
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
