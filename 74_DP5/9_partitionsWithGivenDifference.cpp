// partitionsWithGivenDifference.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array arr[], partition it into two subsets(possibly empty) such that 
each element must belong to only one subset. Let the sum of the elements of these two subsets 
be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 
is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Examples :

Input: arr[] =  [5, 2, 6, 4], d = 3
Output: 1
Explanation: There is only one possible partition of this array. 
Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

Input: arr[] = [1, 1, 1, 1], d = 0 
Output: 6 
Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3}
and put them in sum1 and remaning two 1's in sum2.

Thus there are total 6 ways for partition the array arr. 


Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
Output: 2

*/

class Solution {
    public:
        const int mod = 1e9 + 7;  // Modulo to prevent integer overflow (badi values ke liye)
    
        int countPartitions(vector<int>& arr, int d) {
            int n = arr.size();
            int range = 0;  // Total sum of array store karenge
    
            // Array ka total sum nikalenge
            for (int i = 0; i < n; i++) range = (range + arr[i]) % mod;
    
            // Agar (range - d) negative hai ya (d + range) odd hai, toh partition possible nahi hoga
            if (range - d < 0 || (d + range) % 2) return 0;
    
            // Required sum calculate karenge (partition ka ek subset sum)
            int sum = (d + range) / 2;
    
            // DP table initialize karenge (dp[i][j] -> first i elements se sum j bana sakte hain ya nahi)
            vector <vector <int>> dp(n + 1, vector <int>(sum + 1, 0));
    
            // Base case: Agar sum = 0 ho, toh ek subset to hamesha possible hota hai (empty subset)
            for (int i = 0; i <= n; i++) dp[i][0] = 1;
    
            // DP table ko fill karenge using subset sum logic
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= sum; j++) {

                    if (arr[i - 1] <= j) { 
                        // Element include karne ka option bhi hai ya nahi include karne ka
                        dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
                    }
                    
                    else {
                        // Agar element current sum se bada hai, toh sirf exclude kar sakte hain
                        dp[i][j] = dp[i - 1][j] % mod;
                    }

                }
            }
    
            // Required answer return karenge
            return dp[n][sum] % mod;
        }
    };
    