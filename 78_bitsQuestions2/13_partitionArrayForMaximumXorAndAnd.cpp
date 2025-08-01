#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximizeXorAndXor(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = 0;

        // CASE 1: B is empty → AND(B) = 0
        for (int mask = 0; mask < (1 << n); ++mask) {
            long long xorA = 0, xorC = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) xorA ^= nums[i]; // put in A
                else xorC ^= nums[i];                 // put in C
            }
            maxSum = max(maxSum, xorA + xorC); // AND(B) = 0
        }

        // CASE 2: B has exactly one element
        for (int bIndex = 0; bIndex < n; ++bIndex) {
            long long andB = nums[bIndex];

            vector<int> others;
            for (int i = 0; i < n; ++i) {
                if (i != bIndex) others.push_back(i);
            }

            int m = others.size();
            for (int mask = 0; mask < (1 << m); ++mask) {
                long long xorA = 0, xorC = 0;
                for (int bit = 0; bit < m; ++bit) {
                    int idx = others[bit];
                    if (mask & (1 << bit)) xorA ^= nums[idx];
                    else xorC ^= nums[idx];
                }
                maxSum = max(maxSum, xorA + andB + xorC);
            }
        }

        return maxSum;
    }
};
