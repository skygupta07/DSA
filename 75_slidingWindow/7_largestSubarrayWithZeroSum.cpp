#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> prefixSumMap; // To store (sum, index)
        int sum = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == 0) {
                maxi = i + 1; // Subarray from 0 to i
            }

            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                // If the sum was seen before, calculate the subarray length
                maxi = max(maxi, i - prefixSumMap[sum]);
            } else {
                // Store the first occurrence of this sum
                prefixSumMap[sum] = i;
            }
        }

        return maxi;
    }
};