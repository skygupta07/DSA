#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        // Corrected priority_queue declaration
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Fill the priority queue with elements and their indices
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});  // element, index
        }

        // Perform the operation k times
        while (!pq.empty() && k--) {
            pair<int, int> p = pq.top();  // Get the smallest element
            pq.pop();

            // Multiply the element by m and push it back with the same index
            pq.push({p.first * m, p.second});
        }

        // Prepare the final result array
        vector<int> ans(nums.size());

        // Fetch elements from the priority queue in the order of their original indices
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int idx = p.second;
            int el = p.first;

            ans[idx] = el;
        }

        return ans;
    }
};
