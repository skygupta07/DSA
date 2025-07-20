// longestSubarrayWithSumK.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array arr[] containing integers and an integer k, 
your task is to find the length of the longest subarray where the sum of its elements 
is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. 
The length of the longest subarray with a sum of 15 is 6.

Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.

Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].


Constraints:

1 ≤ arr.size() ≤ 10pow5
-10pow4 ≤ arr[i] ≤ 10pow4
-10pow9 ≤ k ≤ 10pow9

*/


// extreme brute force - O(ncube)
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int target) {
        int n = arr.size();
        
        int maxLen = 0;
        
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                int sum = 0;
                for (int k=i; k<=j; k++){
                    sum += arr[k];
                }
                if (sum == target) maxLen = max(maxLen, j - i + 1); 
            }
        }
        
        return maxLen;
    }
};


// brute force - O(n square)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int target) {
        int n = arr.size();
        
        int maxLen = 0;
        
        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=i; j<n; j++){
                sum += arr[j];
                if (sum == target) maxLen = max(maxLen, j - i + 1); 
            }
        }
        
        return maxLen;
    }
};




class Solution {
public:
    int longestSubarray(vector <int> &arr, int k){

        // Maps prefix sum to its earliest index
        unordered_map <int, int> prefixSumIndex; 

        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            // If the sum of the subarray from the start is equal to k
            if (prefixSum == k) {
                maxLen = i + 1; // Update max length to include the current index
            }

            // Check if there is a prefix sum such that removing it results in sum = k
            if (prefixSumIndex.find(prefixSum - k) != prefixSumIndex.end()) {
                maxLen = max(maxLen, i - prefixSumIndex[prefixSum - k]);
            }

            // Only store the first occurrence of each(ha sabka hi store karna h ... this the 
            // reason why we have used if statement everywhere...)
            //  prefix sum -> matlab agar ye wala prefixSum 


            // already nahi paaya gaya h (important to check ki already naa paya gaya ho...
            // coz we need to increase the length... and agar zero wale elments se aur aage index update hoga to ussey 
            // fayda nahi h .....) to phir store its index...

            if (prefixSumIndex.find(prefixSum) == prefixSumIndex.end()) {
                prefixSumIndex[prefixSum] = i;
            }

        }

        return maxLen;
        
    }
};


/*

ordered_map ke case mai t.c. = O(n logn ) hoga ... 
O(n) for iterating over the array and logn for ordered_map

but if we are using unordered_map then for best case with very less collisions we have t.c. = O(n)*O(1) = O(n)
and for worst case with too much collisions we have O(n square)

s.c. = O(n)

this unordered_map solution is optimal solution for the cases when the array contain negative, zero and positive elements as well...

but in case if the array contains the positive elements only -> yes then there is one more optimal solution ...
i.e. using the two pointers soln..


*/

// prefixSum, twopointer, slidingwindow, map - frequently used datastructures in subarray questions



// most optimal for zero and postive elements...
// t.c. = O(2N) - kyuki yaha andar wala loop har baar n times nahi chal rha.. 


int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();

    int left = 0;
    int right = 0;

    long long sum = a[0];

    int maxLen = 0;

    while (right < n){
        // shrink window
        while (left <= right && sum > k){
            sum -= a[left];
            left++;
        }

        if (sum == k) maxLen = max(maxLen, right - left + 1);

        right++;

        if (right < n) sum += a[right];
    }

    return maxLen;

}