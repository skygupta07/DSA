#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums where every element appears three times except for one, 
which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99

*/

class Solution {
  public:
   int singleNumber(vector<int>& nums) {
     int ans = 0;
 
     // 32-bit integer ke har bit position (0 se 31) par kaam karenge
     for (int i = 0; i < 32; i++) {  
       int sum = 0;
 
       // Har number ke ith bit ko extract karke sum karenge
       for (const int num : nums) {
         sum += (num >> i) & 1;  // ith bit ko right shift karke extract kiya, phir & 1 se mask kar diya
       }  
 
       // Kyunki har number 3 baar repeat ho raha hai (except ek jo single hai),
       // toh agar sum % 3 != 0 hai, iska matlab ye bit single number me set hai.
       sum %= 3;    
 
       // ans ke ith bit par sum store kar diya -- extract right shift karke kiya tha... and waha 
      //  wapas left shift karke laga rahe h...

       ans |= (sum << i);
     }
 
     return ans;  // Final answer return kar diya
   }
   
 };
 
/*

Har bit ka alag count rakho: Kyunki numbers 3 baar repeat ho rahe hain, 
toh har bit ka total count nikal lo.

Modulo 3 lagao: Jo bhi bit sirf ek hi baar aayi hogi, woh sum % 3 != 0 karega.

Final number reconstruct karo: Har bit ko uski position pe sum << i karke OR se add kar do.

*/