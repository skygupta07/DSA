// findTheDuplicateNumber.cpp

#include <bits/stdc++.h>
using namespace std;

// hare matlab khargosh, jo ki tej bhaagta hai. {arey yrr tune starting mai hi hint de di... ab to 
// ho jaega aaram se..}


/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] 
inclusive.
There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2


Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


Example 3:

Input: nums = [3,3,3,3,3]
Output: 3

*/


class Solution {
public:

        int findDuplicate(vector<int>& nums) {
            int hare = nums[0];      // Hare (fast pointer) ko starting position pe rakhte hain
            int tortoise = nums[0];  // Tortoise (slow pointer) ko bhi wahi se start karwate hain
    
            // Pehle cycle detect karne ke liye hare ko 2 steps aage bhejenge aur tortoise ko 1 step aage
            do {
                hare = nums[nums[hare]]; // Hare ek baar jump karke fir ek aur jump karega (2 steps)
                tortoise = nums[tortoise]; // Tortoise sirf ek step aage badhega
            } while (hare != tortoise); // Jab dono mil jaayenge toh cycle mil chuki hai
    
            // Ab cycle ka starting point dhoondhna hai, toh tortoise ko wapas start position pe le aate hain
            tortoise = nums[0];
    
            // Dono ko ek-ek step aage badhate hain, jab tak firse nahi mil jaate
            while (hare != tortoise) {
                hare = nums[hare];         // Hare ko ek step aage le jao
                tortoise = nums[tortoise]; // Tortoise ko bhi ek step aage le jao
            }
    
            return hare; // Jab dono mil jaayein, wahi duplicate number hoga
        }
    };
    

// using floyd cycle detection.....
