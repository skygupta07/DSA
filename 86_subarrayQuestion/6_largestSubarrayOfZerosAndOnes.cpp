// largestSubarrayOfZerosAndOnes.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution { // O(n square) gives tle
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        int maxLen = 0;
        
        for (int i=0; i<n; i++){
            int zeroCount = 0, oneCount = 0;
            
            for (int j=i; j<n; j++){
                if (arr[j] == 0) zeroCount++;
                else oneCount++;
                
                if (zeroCount == oneCount){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
};



class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> prefixSumIndex;
        int sum = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            // Treat 0 as -1 for equal count of 0s and 1s
            sum += (arr[i] == 0) ? -1 : 1;

            if (sum == 0) {
                maxLen = i + 1; // Subarray from start has equal 0s and 1s
            }

            // If sum is already seen, update maxLen
            if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                maxLen = max(maxLen, i - prefixSumIndex[sum]);
            } else {
                // Store the first occurrence of this sum
                prefixSumIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
