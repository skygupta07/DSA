// subarraySumDivisibleByK.cpp

#include <bits/stdc++.h>
using namespace std;



class Solution { // interview
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Map to store frequency of prefix sum remainders
        unordered_map<int, int> mp;


        int prefix = 0;  // Yeh prefix sum store karega current tak ka sum - pura vector na bana ke kewal ek variable se hi kaam chalwaya...
        int count = 0;   // Yeh final answer hai — kitne subarrays ka sum divisible hai by k
        
       
        // Har number ke liye prefix sum aur uska remainder calculate karenge
        for (int num : nums) {
            
            prefix += num;  // Prefix sum update karo

            int rem = prefix % k;  // Remainder nikalo


            // Agar remainder negative aaya toh usko positive banana padega,
            // kyunki C++ mein negative remainder aa sakta hai.
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

        return count;  // Final answer return karo

    }
};




class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
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
