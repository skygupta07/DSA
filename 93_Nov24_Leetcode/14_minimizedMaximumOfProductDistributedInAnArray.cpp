#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if it is possible to distribute quantities among `n` stores
    // such that the maximum items in any store is `mid`.
    bool isPossible(int n, vector<int>& quantities, int mid) {
        int stores = 0; // Stores required with this distribution limit
        for (auto x : quantities) {
            // Calculate the number of stores needed for the current quantity `x`
            // if each store has a max of `mid` items.
            stores += x / mid;
            
            // If there's a remainder when dividing, it means we need an extra store
            // to handle the remaining items.
            if (x % mid) stores++;
            
            // If the required number of stores exceeds `n`, it's not possible with this `mid`
            if (stores > n) return false;
        }
        
        // If the loop completes without exceeding `n` stores, this distribution is feasible
        return stores <= n;
    }

    // Main function to find the minimized maximum number of items in any store
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1, e = 100000, ans = -1;
        
        // Perform binary search on the potential maximum number of items per store
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate the midpoint
            
            // Check if it's possible to distribute items such that no store has more than `mid` items
            if (isPossible(n, quantities, mid)) {
                // If yes, store the answer and try to find a smaller feasible `mid`
                ans = mid;
                e = mid - 1;
            } else {
                // If no, increase the lower bound to try for a larger `mid`
                s = mid + 1;
            }
        }
        
        // The minimized maximum number of items in any store
        return ans;
    }
};
