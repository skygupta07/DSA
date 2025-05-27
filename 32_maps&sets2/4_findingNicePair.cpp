#include <bits/stdc++.h>
using namespace std;

// findingNicePairsInAnArray

/*

You are given an array nums that consists of non-negative integers. 
Let us define rev(x) as the reverse of the non-negative integer x. 
For example, rev(123) = 321, and rev(120) = 21.
A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])

Return the number of nice pairs of indices. 
Since that number can be too large, return it modulo 109 + 7.

 
Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.


Example 2:

Input: nums = [13,10,35,24,76]
Output: 4

*/


class Solution {
public:
    int rev(int n){
        int r = 0;

        while (n>0){
            r *= 10;
            r += n%10;

            n = n/10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums){
        int n = nums.size();
        int count = 0;

        unordered_map <int,int> mp;

        for (int i=0; i<n; i++){
            nums[i] -= rev(nums[i]); // modifying array...
        }

        // now finding if the number exist again in map...
        for (int i=0; i<n; i++){

            if (mp.find(nums[i]) != mp.end()){
                count = count % 1000000007;   // pehle count ko normalise karlo 
                count += mp[nums[i]];    // existing frequency ko add kardo..kitna contribution de rha h

                mp[nums[i]]++;   // then ek frequency badha do..
            }

            else mp[nums[i]]++; // agar wo element nahi bhi milta to kya atleast map mai to daalunga na uss 
                                    // element ko....
        }
        return count % 1000000007;    // and finally ek baar aur theek karke return kar do...
    }
};



// ---------- -----------

class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll;

    int rev(int num){
        int r = 0;
        while (num > 0){
            r *= 10;
            r += num%10;

            num /= 10;
        }
        return r;
    }
   
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map <int, ll> diffCount;
        ll count = 0;

        for (int num : nums) {
            int revNum = rev(num);
            int diff = num - revNum;
            
            count = (count + diffCount[diff]) % mod;    // increasing count by how many times that frequency has already been seen..... 
            
            diffCount[diff]++;  // increasing its frequency....
        }

        return count;
    }
};

/*

simply count the frequency of nums[i] - rev(nums[i]) 
and then see how much its frequency exists....


*/