// makeSumDivisibleByP.cpp


#include <bits/stdc++.h>
using namespace std;


/*

Given an array of positive integers nums, remove the smallest subarray (possibly empty)
such that the sum of the remaining elements is divisible by p. 
It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

 
Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. 
We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.


Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. 
The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.


Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.

*/



class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {

        long totalSum = 0;

        // Step 1: Poore array ka total sum nikaal lo
        for (int num : nums) totalSum += num;

        //  Step 2: Dekho bacha kitna hai jab total sum ko p se divide kiya
        int rem = totalSum % p;

        // Agar remainder 0 hai, to matlab poora array divisible hai → kuch remove karne ki zarurat nahi
        if (rem == 0) return 0;

        //  Step 3: Prefix sum ka mod store karne ke liye hashmap
        unordered_map <int, int> prefixMod;

        prefixMod[0] = -1; // Important: agar starting se hi kuch prefix remove karna ho to ye kaam aayega

        long prefixSum = 0;
        int minLength = nums.size();  // Maximum length se initialize karo

        //  Step 4: Traverse karo aur prefix sums ka mod store karo
        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            // Current prefix ka mod lo
            int currentMod = prefixSum % p;

            // Target mod calculate karo jise hume remove karna hai
            int targetMod = (currentMod - rem + p) % p;

            // Agar target mod pehle kabhi mila hai, to hum potential subarray remove kar sakte hain
            if (prefixMod.find(targetMod) != prefixMod.end()) {
                // Minimize the length
                minLength = min(minLength, i - prefixMod[targetMod]);
            }

            //  Update karo current mod ka latest index
            prefixMod[currentMod] = i;
        }

        //  Final check: agar minLength same hai to matlab koi valid subarray nahi mila
        return minLength == nums.size() ? -1 : minLength;
    }
};



// chota modulus bada = chota   - this is the reason why we often mod with 
// const int mod = 1e9 + 7;