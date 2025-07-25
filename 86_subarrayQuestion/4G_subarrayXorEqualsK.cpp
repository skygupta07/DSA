//  CountSubarraysWithGivenXOR

/*

Given an array of integers arr[] and a number k, 
count the number of subarrays having XOR of their elements as k.

Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4

Explanation: The subarrays having XOR of their elements as 6 are 
[4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.


Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2

Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. 
Hence, the answer is 2.

Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4

Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
Constraints:

1 ≤ arr.size() ≤ 1e5
0 ≤ arr[i] ≤1e5
0 ≤ k ≤ 1e5

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long subarrayXor(vector <int> &arr, int k) {
        
        unordered_map <int, int> mp; // prefixXOR ke frequency track karne ke liye map
        
        long count = 0;             // Answer store karne ke liye
        int prefixXOR = 0;          // prefixXOR: 0 se lekar current element tak ka XOR

        // Array traverse karte hain
        for (int num : arr) {

            // prefixXOR update karo current element ke saath
            prefixXOR ^= num;

            // Agar prefixXOR hi k ke barabar ho gaya hai,
            // iska matlab 0 se i tak ka subarray ka XOR == k hai
            if (prefixXOR == k) count++;

            // prefixXOR ^ requiredXOR = k  --> requiredXOR = prefixXOR ^ k
            // Check karo kya aisa koi previous prefixXOR mila tha jis se current prefixXOR ^ old == k
            int requiredXOR = prefixXOR ^ k;

            // Agar requiredXOR map me already exist karta hai,
            // toh matlab us position ke baad se lekar ab tak ka subarray ka XOR == k
            if (mp.find(requiredXOR) != mp.end()) {
                count += mp[requiredXOR];
            }

            // Map me current prefixXOR ka frequency update karo
            mp[prefixXOR]++;
        }

        return count; 
    }

};
