#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0; // No transactions possible
        
        int res = 0; // Total profit
        int i = 0;

        while (i < n - 1) {
            // Find local minima (buy point)
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            if (i == n - 1) break; // No more transactions possible
            int lMin = prices[i];

            // Find local maxima (sell point)
            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            int lMax = prices[i];

            // Calculate profit
            res += (lMax - lMin);
        }

        return res;
    }
};

