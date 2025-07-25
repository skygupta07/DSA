// subarraySumDivisibleByK.cpp

/*

Given an integer array nums and an integer k, 
return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7

Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 1e4
-1e4 <= nums[i] <= 1e4
2 <= k <= 1e4

*/



#include <bits/stdc++.h>
using namespace std;

 // interview
class Solution {
public:

    int subarraysDivByK(vector <int> &nums, int k) {
        // Map to store frequency of prefix sum remainders
        unordered_map <int, int> mp;

        int prefix = 0;  // Yeh prefix sum store karega current tak ka sum - pura vector na bana ke kewal ek variable se hi kaam chalwaya...
        int count = 0;   // Yeh final answer hai — kitne subarrays ka sum divisible hai by k
        
       
        // Har number ke liye prefix sum aur uska remainder calculate karenge
        for (int num : nums) {
            
            prefix += num;  // Prefix sum update karo

            int rem = prefix % k;  // Remainder nikalo


            // Agar remainder negative aaya toh usko positive banana padega,
            // kyunki C++ mein negative remainder aa sakta hai. {aur usko positive wahi factor k ya n jo ho ...
            // usi ko add karke hota h .. Amit taught this}
            if (rem < 0) rem += k;

            if (rem == 0) count++;

            // Agar yeh remainder pehle aaya hai, iska matlab:
            // Beech mein koi aisa subarray hai jiska sum divisible hoga by k

            // (prefix1 % k == prefix2 % k => (prefix2 - prefix1) % k == 0)
            if (mp.find(rem) != mp.end()) {
                count += mp[rem];  // Us remainder ke frequency jitne subarrays honge
            }

            // Ab is remainder ko map mein update kar do for future subarrays
            mp[rem]++;
        }

        // Final answer return karo
        return count;  
    }
    
};




class Solution {
public:

    int subarraysDivByK(vector <int> &nums, int k) {
        unordered_map <int, int> mp;
        mp[0] = 1;  // Initialize to handle subarrays that start from index 0

        int prefix = 0, count = 0;
        
        for (int num : nums) {
            prefix += num;
            
            int rem = prefix % k;
            if (rem < 0) rem += k; // Handle negative remainders
            
            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }
            
            mp[rem]++;
        }

        return count;
    }

};
