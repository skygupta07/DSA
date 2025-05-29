// eggDropping

/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor 
hier than f will break, and any egg dropped at or belo floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n).
If the egg breaks, you can no longer use it. However, if the egg does not break, 
you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.


Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 

Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.


Example 2:

Input: k = 2, n = 6
Output: 3


Example 3:

Input: k = 3, n = 14
Output: 4
 
Constraints:

1 <= k <= 100
1 <= n <= 104

*/



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int dp[201][201];
    
    int helper(int eggs, int floors){
        //base case
        if (floors == 0 || floors == 1) return floors;
        if (eggs == 1) return floors;
        
        // dp help
        if (dp[eggs][floors] != -1) return dp[eggs][floors];
        int ans = INT_MAX;
        
        // kaam
        for (int k=1; k<=floors; k++){
            int temp = 1 + max(helper(eggs-1, k-1), helper(eggs, floors - k));
            
            ans = min(ans, temp);
        }
        return dp[eggs][floors] = ans;
    }
    
    
    int eggDrop(int n, int k){
        memset(dp, -1, sizeof(dp)); // bahar dp declare karo and andar initialise karo..
        return helper(n,k);
    }
};


// Class banayi hai Solution naam ki, jisme logic likha hai egg dropping ka
class Solution {
    public:

        // constraints dekho and ussey ek ya paach jyada ke dp array declare karo...
        // then memset ka use karke ussey initialise karna main function mai...

        // dp[k][n] => yeh batata hai minimum kitni moves chahiye k eggs aur n floors ke liye
        // Initialize globally for memoization (to store already computed answers)
        int dp[101][10005];

        // Helper function banayi hai jo recursive + memoization se kaam karti hai'

        // Yeh function return karega min moves for k eggs and n floors
        int solve(int k, int n) {
            // Base cases:

            // Agar floor hi 0 ya 1 hai toh:
            // - 0 floor => koi move nahi chahiye
            // - 1 floor => ek hi baar girana padega
            if(n == 0 || n == 1) return n;

            // Agar sirf 1 egg hai, toh safe strategy yahi hai ki har floor pe sequentially test karein
            // i.e., 1 se lekar n tak har floor pe test karna padega
            if(k == 1) return n;

            // Agar answer already calculate kiya hua hai toh use return kar do
            if(dp[k][n] != -1) return dp[k][n];

            // Binary search ka setup
            int lo = 1; // loest floor possible for this binary search
            int hi = n; // highest floor possible 

            int minMoves = INT_MAX;

            // lo aur hi ko mini-maxi sochne wale ladke meethe hote h... 😄
            
            // Ab binary search se optimal mid dhundenge jahan se egg girana best ho

            while(lo <= hi) {

                // mid floor pe egg girane ka try karenge
                int mid = lo + (hi - lo)/2;

                // Case 1: egg breaks => k-1 eggs bache aur neeche ke (mid - 1) floors check karne padenge
                int broken = solve(k - 1, mid - 1);

                // Case 2: egg does NOT break => egg bacha raha, upar ke (n - mid) floors check karne padenge
                int notBroken = solve(k, n - mid);

                // Ek move to lag hi gayi (egg giraya mid floor pe),
                // Uske baad worst-case lena padega kyunki humein sabse worst scenario ke liye ready rehna hai
                int currMoves = 1 + max(broken, notBroken);

                // Minimum moves update karo agar yeh move better nikli previous se
                minMoves = min(minMoves, currMoves);

                // Binary search ka smart logic yahaan apply ho raha hai:
                // Agar `broken > notBroken` hai, iska matlab:
                //     - Egg tootne wala case zyada worst hai
                //     - i.e., agar mid floor se girate hi egg toot gaya, toh neeche wale floors zyada risky hai
                //     - Isliye humein neeche ke floors par focus karna chahiye (lower floors try karo)
                //     => isliye high = mid - 1
                if(broken > notBroken) hi = mid - 1;
                

                // Agar `notBroken >= broken` hai, iska matlab:
                //     - Egg nahi toota, ya tootne wala case kam worst tha
                //     - i.e., upar ke floors zyada risky ho sakte hain
                //     - Isliye humein upar ke floors par focus karna chahiye (higher floors try karo)
                //     => isliye low = mid + 1

                else lo = mid + 1;
                

            }

            // DP table ko update karo taaki same state dobara call na ho
            return dp[k][n] = minMoves;
        }

        // Main function jise user call karega => k eggs, n floors
        int superEggDrop(int k, int n) {
            // Sabhi dp values ko -1 se initialize kar do (meaning: not yet computed)
            memset(dp, -1, sizeof(dp));

            // Solve function ko call karo actual answer ke liye
            return solve(k, n);
        }
};

    