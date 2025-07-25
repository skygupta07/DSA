// sumOfSubarrayMinimums.cpp

/*

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray 
of arr. Since the answer may be large, return the answer modulo 1e9 + 7.


Example 1:

Input: arr = [3,1,2,4]
Output: 17


Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.

Sum is 17.


Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    using ll = long long; // long long ko short mein ll likhne ke liye
    const int MOD = 1e9 + 7; // Modulo value (10^9 + 7)

    int sumSubarrayMins(vector<int>& nums) {
        
        int n = nums.size();
        stack <int> stk; // Stack banaya to track indices

        vector <int> left(n, -1); // Har element ke left boundary ka index
        vector <int> right(n, n); // Har element ke right boundary ka index

        // Left boundary find karne ke liye
        for (int i = 0; i < n; i++) {
            // Jab tak stack ka top current element se bada ya barabar ho, pop karte jao
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();

            if (!stk.empty()) {
                left[i] = stk.top(); // Agar stack empty nahi hai, to top element left boundary hai
            }

            stk.push(i); // Current index ko stack mein push karo
        }

        stk = stack <int> (); // Stack ko reset kar diya

        // Right boundary find karne ke liye
        for (int i = n - 1; i >= 0; i--) {
            // Jab tak stack ka top current element se strictly bada ho, pop karte jao 
            // {ek jagah to strict inequality lagani hi padti h..}
            while (!stk.empty() && nums[stk.top()] > nums[i]) stk.pop();

            if (!stk.empty()) {
                right[i] = stk.top(); // Agar stack empty nahi hai, to top element right boundary hai
            }

            stk.push(i); // Current index ko stack mein push karo
        }

        ll sum = 0; // Subarray mins ka sum store karne ke liye

        // Har element ka contribution calculate karo
        for (int i = 0; i < n; i++) {
            // Contribution formula:
            // (i - left[i]) -> left side ke subarrays count
            // (right[i] - i) -> right side ke subarrays count
            // nums[i] -> current element
            sum += static_cast<ll> (i - left[i]) * (right[i] - i) * nums[i] % MOD;
            
            sum %= MOD; // Har step par modulo le lo
        }

        return sum; // Final sum return karo
    }
};
