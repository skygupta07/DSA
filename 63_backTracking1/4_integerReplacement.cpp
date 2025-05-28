#include <bits/stdc++.h>
using namespace std;

/*


Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.


Example 1:

Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1


Example 2:

Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1


Example 3:

Input: n = 4
Output: 2
 

Constraints:

1 <= n <= 2pow31 - 1

*/

class Solution {
public:

        // value, operation 
        unordered_map <long, int> dp; // Using unordered_map to handle large values of n (good learning for me !!)


        // dp[i] will store the minimum operation needed for i to become 1...
        
        int f(long n) {
            if (n == 1) return 0; // Base case: 1 requires 0 operations
            
            if (dp.find(n) != dp.end()) return dp[n]; // Memoization check
    
            if (n % 2 == 0) {
                dp[n] = 1 + f(n / 2); // Even case
            } 
            
            else {
                dp[n] = 1 + min(f(n - 1), f(n + 1)); // Odd case, trying both possibilities
            }

            return dp[n];
        }
    

        int integerReplacement(int n) {
            return f(n);
        }

};
    