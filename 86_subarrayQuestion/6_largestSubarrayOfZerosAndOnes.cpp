// largestSubarrayOfZerosAndOnes.cpp

/*

Given an array arr of 0s and 1s. 
Find and return the length of the longest subarray with equal number of 0s and 1s.

Examples:

Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6

Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.

Input: arr[] = [0, 0, 1, 1, 0]
Output: 4
Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.

Input: arr[] = [0]
Output: 0
Explnation: There is no subarray with an equal number of 0s and 1s.

Constraints:
1 <= arr.size() <= 1e5
0 <= arr[i] <= 1

*/


#include <bits/stdc++.h>
using namespace std;

class Solution { // O(n square) gives tle
public:

    int maxLen(vector <int> &arr) {
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

        unordered_map <int, int> prefixSumIndex;

        int sum = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            // Treat 0 as -1 for equal count of 0s and 1s {Brahmastra}
            sum += (arr[i] == 0) ? -1 : 1;

            if (sum == 0) {
                maxLen = i + 1; // Subarray from start has equal 0s and 1s
            }

            // If sum is already seen, update maxLen
            if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                maxLen = max(maxLen, i - prefixSumIndex[sum]);
            } 
            
            else {
                // Store the first occurrence of this sum
                prefixSumIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
