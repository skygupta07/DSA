// subarraySumEqualsK.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers nums and an integer k, 
return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2


Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 1e4
-1000 <= nums[i] <= 1000
-1e7 <= k <= 1e7

*/

// brute force - O(n2)
class Solution {
public:

    int subarraySum(vector<int>& arr, int target) {
        int n = arr.size();
        int count = 0;
        
        for (int i=0; i<n; i++){
            // har starting point ke liye waha pe sum ko zero kar dete h
            int sum = 0;

            // ha j ko i se hi start karte h subarray wale loop mai..
            for (int j=i; j<n; j++){
                sum += arr[j];
                if (sum == target) count++;
            }
        }

        return count;
    }
};




class Solution {
public:

    int subarraySum(vector <int> &arr, int k){
        int n = arr.size();

        vector <int> pref(n,0);
        pref[0] = arr[0];
        for (int i=1; i<n; i++) pref[i] = arr[i] + pref[i-1];
        

        // prefixSum and its frequency
        unordered_map <int, int> mp;
        int count = 0;

        for (int i=0; i<n; i++){

            // agar prefixSum == k ho gaya matlab subarraySum == k hogaya so increase its count
            if (pref[i] == k) count++;

            // agar purti nahi ho payi prefSum se matlab kucch baaki reh gaya... 
            // wo baaki element map mai jitne baar
            // bhi present h wo count ko increase karwayega...

            int rem = pref[i] - k;
            if (mp.find(rem) != mp.end()) count += mp[rem];
            
            // in general jis bhi sum tak aagaye ho ussey track ya store to karte raho..
            mp[pref[i]]++;
        }
        
        return count;

    }

};



/*

calculated prefix sum -> since subarray wala prefix sum ke dost wala question...
at any moment if prefixSum[i] == k   count++

else sabhi element ka rem find kara and dekha ki kya remaining element present hai...
agar present hai to kitni baar present hai ...uska utni baar contribution dedo count mai....

*/