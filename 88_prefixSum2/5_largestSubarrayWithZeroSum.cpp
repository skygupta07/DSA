// largestSubarrayWithZeroSum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        int n = arr.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];

                if (sum == 0)
                    maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};

/*
iterating over the subarray calculate its sum
if sum == 0 then maximise length...

brute force approach...
O(n square) gives tle...

*/

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        int n = arr.size();

        unordered_map<int, int> prefixSumMap; // Stores prefix sum and its first occurrence index
        int sum = 0;                          // Tracks cumulative sum
        int maxLen = 0;                       // Stores maximum subarray length with sum 0

        for (int i = 0; i < n; i++)
        {
            sum += arr[i]; // Update prefix sum

            if (sum == 0)
            {
                // If sum becomes 0, entire subarray from index 0 to i has sum 0
                maxLen = i + 1;
            }

            if (prefixSumMap.find(sum) != prefixSumMap.end())
            {
                // If same prefix sum was seen before, it means subarray between previous index
                // and current index has sum 0 (because intermediate sum canceled out)
                maxLen = max(maxLen, i - prefixSumMap[sum]); // Update max length
            }

            else
            {
                // Store first occurrence of this prefix sum
                prefixSumMap[sum] = i;
            }
        }

        return maxLen; // Return max length of subarray with sum 0
    }
};
