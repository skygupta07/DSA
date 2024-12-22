#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long count = 0;

        for (int i = 0; i < n; i++) {
            int min_required = lower - nums[i];
            int max_required = upper - nums[i];

            // Use binary search to find the range of indices j that satisfy:
            // lower <= nums[i] + nums[j] <= upper
            // Find the smallest j such that nums[j] >= min_required
            auto lower_bound_it = lower_bound(nums.begin() + i + 1, nums.end(), min_required);
            // Find the largest j such that nums[j] <= max_required
            auto upper_bound_it = upper_bound(nums.begin() + i + 1, nums.end(), max_required);

            count += distance(lower_bound_it, upper_bound_it);
        }

        return count;
    }
};
