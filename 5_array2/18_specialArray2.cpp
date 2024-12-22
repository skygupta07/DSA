#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> breakPoints(n, n); // Stores the next breaking index for parity alternation
        vector<bool> ans;

        // ekdum aakhri wale ka to koi next hai hi nahi comparison ke liye..

        // Precompute break points
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                breakPoints[i] = i + 1; // Parity does not alternate
            } else {
                // kamaal ki line
                breakPoints[i] = breakPoints[i + 1]; // Inherit the next breaking point
            }
        }

        // Answer each query in O(1) time
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];

            // Check if the parity alternation breaks within the range
            ans.push_back(breakPoints[start] > end);    // yaha khel gaye.. bool check kake push bhi kar diya...
        }

        return ans;
    }
};


/*

We can use a prefix array to precompute the parity alternation information.
Specifically, we'll preprocess the array to compute where the parity alternation
pattern breaks. This will allow us to answer each query in O(1) time
after preprocessing.
We use a breakPoints array where breakPoints[i] stores the first index after i 
where the parity alternation breaks.


For each query [start, end], we simply check if breakPoints[start] > end. 
This ensures that no parity alternation breaks occur in the range [start, end].

*/