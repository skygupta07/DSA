// maxConsecutiveOnes3.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a binary array nums and an integer k, 
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.


Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(); 
        // start dono pointer to suru se hi honge na...
        int left = 0; // Left pointer, window ka shuru
        int right = 0; // Right pointer, window ka akhir

        while (right < n){ // Jab tak right pointer array ke andar hai
            if (nums[right] == 0) k--; // Agar current element 0 hai, to flips ka count ek kam kar do

            if (k < 0){ // Agar flips ka count negative ho gaya 
                if (nums[left] == 0) k++; // Agar left pointer pe bhi 0 hai, to flips ka count ek badhao
                left++; // Left pointer ko aage badhao -> is bande ki need nahi h..'
            }

            right++; // Right pointer ko aage badhao
        }

        return right - left; // Window ka size return karo
    }
};


/*
Window ko expand karte hain jab tak allowed flips ki limit nahi ho jati.
Agar flips ki limit ho jati hai, to window ko contract karte hain.
Har step pe, maximum window size ko track karte hain.
*/