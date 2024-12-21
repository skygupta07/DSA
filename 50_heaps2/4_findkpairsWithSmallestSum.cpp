#include <bits/stdc++.h>
using namespace std;


#define pp pair <int, pair <int, int> > 

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // Priority queue to store pairs with their sums
        priority_queue < pp, vector<pp>, greater<pp> > pq;

        // Insert the smallest pairs initially (first element from nums1 and each element from nums2)
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> result;

        // Extract the k smallest pairs
        while (!pq.empty() && k--) {
            auto p = pq.top();
            pq.pop();

            int i = p.second.first;
            int j = p.second.second;

            result.push_back({nums1[i], nums2[j]});

            // If there is any more elements in nums2 for the current nums1 element, add the next pair
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return result;
    }
};
