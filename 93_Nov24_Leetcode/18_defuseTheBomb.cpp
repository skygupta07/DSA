#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) return ans; // If k is 0, all elements remain 0.

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) { // Sum the next k elements.
                    sum += code[(i + j) % n]; // Wrap around using modulo.
                }
                ans[i] = sum;
            }
        } else { // k < 0
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= -k; j++) { // Sum the previous k elements.
                    sum += code[(i - j + n) % n]; // Wrap around using modulo.
                }
                ans[i] = sum;
            }
        }

        return ans;
    }
};
