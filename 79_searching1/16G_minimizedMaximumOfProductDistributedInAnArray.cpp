// minimizeMaximumOfProductDistributedInAnArray.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given an integer n indicating there are n specialty retail stores. 
There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, 
where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). 

Let x represent the maximum number of products given to any store. 
You want x to be as small as possible, 

i.e., you want to minimize the maximum number of products 
that are given to any store.

Return the minimum possible x.


Example 1:

Input: n = 6, quantities = [11,6]
Output: 3

Explanation: One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.


Example 2:

Input: n = 7, quantities = [15,10,10]
Output: 5

Explanation: One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.


Example 3:

Input: n = 1, quantities = [100000]
Output: 100000
Explanation: The only optimal way is:
- The 100000 products of type 0 are distributed to the only store.
The maximum number of products given to any store is max(100000) = 100000.
 

Constraints:

m == quantities.length
1 <= m <= n <= 1e5
1 <= quantities[i] <= 1e5

*/


// binary search 

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
        int lo = 1, hi = 100000, ans = -1;
        
        // Perform binary search on the potential maximum number of items per store
        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2; // Calculate the midpoint
            
            // Check if it's possible to distribute items such that no store has more than `mid` items
            if (isPossible(n, quantities, mid)) {
                // If yes, store the answer and try to find a smaller feasible `mid`
                ans = mid;
                hi = mid - 1;
            } 
            
            else {
                // If no, increase the lower bound to try for a larger `mid`
                lo = mid + 1;
            }
            
        }
        
        // The minimized maximum number of items in any store
        return ans;
    }
};
