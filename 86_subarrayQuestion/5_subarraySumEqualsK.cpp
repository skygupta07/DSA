#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> pref(n, 0); // Step 1: Initialize a prefix sum array

        // Step 2: Calculate prefix sums
        pref[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pref[i] = arr[i] + pref[i - 1];
        }

        unordered_map<int, int> mp; // Step 3: Map to store prefix sums and their frequencies
        int count = 0; // Variable to store the count of subarrays with sum equal to k

        // Step 4: Iterate through the array and use the prefix sum to count valid subarrays
        for (int i = 0; i < n; i++) {
            // If the prefix sum up to index `i` itself equals `k`, increment count
            if (pref[i] == k) count++;

            // Calculate the remainder needed to form a subarray with sum `k`
            int rem = pref[i] - k;

            // If the remainder exists in the map, add its frequency to count
            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            // Increment the frequency of the current prefix sum in the map
            mp[pref[i]]++;
        }

        return count; // Return the total count of subarrays with sum `k`
    }
};


class Solution {    // gave tle most of time (in gfg, leetcode passed)
public:
    int subarraySum(vector<int>& arr, int target) {
        int n = arr.size();
        int count = 0;
        
        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=i; j<n; j++){
                sum += arr[j];
                if (sum == target) count++;
            }
        }
        return count;
    }
};