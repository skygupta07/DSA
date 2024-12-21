class Solution {
public:
    vector<int> dp; // Declare dp globally to avoid passing it in every function

    // Top-Down Approach (Memoization)
    int ftd(vector<int>& arr, int i) {
        int n = arr.size();
        if (i == n - 1) return arr[n - 1];
        if (i == n - 2) return max(arr[i], arr[i + 1]);

        // Check if result is already computed
        if (dp[i] != -1) return dp[i];

        // Recurrence relation
        int lootPath = arr[i] + ftd(arr, i + 2);
        int notLootPath = ftd(arr, i + 1);

        return dp[i] = max(lootPath, notLootPath);
    }

    // Bottom-Up Approach (Tabulation)
    int fbu(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        dp.clear();
        dp.resize(n);
        dp[n - 1] = arr[n - 1];
        dp[n - 2] = max(arr[n - 1], arr[n - 2]);

        for (int i = n - 3; i >= 0; i--) {
            dp[i] = max(arr[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[0]; // Answer is stored at dp[0]
    }

    int rob(vector<int>& nums) {
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



