// houseRobber1.cpp


/*

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing 
each of them is that adjacent houses have security systems connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
 

Example 1:

Input: nums = [1,2,3,1]
Output: 4

Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12

Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    // Declare dp globally to avoid passing it in every function
    vector <int> dp; 

    // Top-Down Approach (Memoization)
    int ftd(vector<int>& arr, int i) {

        int n = arr.size();

        // base cases
        // if you are land at last house please chor ji lut lijiye...
        if (i == n - 1) return arr[n - 1];

        // if you are at second last house rob the max of both of them...
        if (i == n - 2) return max(arr[i], arr[i + 1]);

        // Check if result is already computed or take dp help
        if (dp[i] != -1) return dp[i];

        // Recurrence relation
        // agar current ghar loota to phir ab next nahi loot sakte .. isliye i+2 ki call lagao..
        int lootPath = arr[i] + ftd(arr, i + 2);

        // current ghar nahi loota to phir ha phir next ghar pe chalo...
        int notLootPath = ftd(arr, i + 1);

        return dp[i] = max(lootPath, notLootPath);
    }


    // fbu ke base cases ke liye ftd se bhi inspire ho sakte ho...
    // fbu ka loop ulta chalta h ... as the loop you described above in ftd

    // Bottom-Up Approach (Tabulation)
    int fbu(vector <int> &arr){

        int n = arr.size();

        if (n == 1) return arr[0];

        dp.clear();
        dp.resize(n);   

        // base cases
        dp[n - 1] = arr[n - 1];
        dp[n - 2] = max(arr[n - 1], arr[n - 2]);

        for (int i = n - 3; i >= 0; i--){
            dp[i] = max(arr[i] + dp[i + 2], dp[i + 1]);
        }

        // here dp[i] stores the max you can rob starting from index i to last house n - 1

        return dp[0]; // Answer is stored at dp[0]
    }

    int rob(vector <int> &nums) {

        dp.clear();        // Clear dp

        dp.resize(nums.size(), -1); // Resize dp to the size of nums with initial value -1

        // Use either Top-Down or Bottom-Up approach
        // return ftd(nums, 0);   // Uncomment to use Top-Down approach
        return fbu(nums);       // Use Bottom-Up approach
    }
};


/*

brute force
taking those subsets only where no adjacent elements taken

// recursive fn mai array ke saath *index bhi pass karna hota hai...

// f(arr,i) -> this recursive function returns max profit by looting houses from index 
'i' to n-1  (last house) such that no two adjacent houses are looted

last ke base cases isliye handle ho rahe hai kyuki kisi bhi nayi ith state ko as a fresh state treat kar rahe hai 
and waha se recursive fn kaam karega acche se 

main fn se hum f(arr, 0) 0th index pass kar rahe hai because hume starting from first house saare include karne hai...
-> state of the dp can be identified by the single variable index i

optimal substructure bhi hai yaha because choti subproblem ko combined use  karke badi problem ka solution 
ban rahi hai...

vector <int> dp maine globally banayi now leetcode alag alag testcases ke liye check karta hai...
jisme ki purane waale testcase ka garbage value store ho sakta hai... =>so better is that you 
clear your dp vector from the main fn ..


------bottom up------
LHS nikalne ke liye aapko RHS compute karna hoga => to compute the ith index you need to find the
i+1 and i+2th index first...


*/
