#include <bits/stdc++.h>
using namespace std;


/*
A frog is crossing a river. The river is divided into some number of units, and at each unit, 
there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones positions (in units) in sorted ascending order, 
determine if the frog can cross the river by landing on the last stone. 
Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. 
The frog can only jump in the forward direction. 

Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.

*/
// Recursive function with memoization to find minimum energy cost
int f(int idx, vector<int> &heights, vector<int> &dp) {

    // ✅ Base case:
    // Agar hum 0th index par aa gaye (starting step), toh koi energy use nahi hui
    if (idx == 0) return 0;

    // ✅ DP check:
    // Agar iss index ka answer pehle se calculate kiya hua hai (memoized), toh use wahi return kar do
    if (dp[idx] != -1) return dp[idx];

    // ✅ Option 1: Frog 1 step peeche se aaya
    // So, energy = energy of (idx-1) se jump + un dono height ka difference
    int left = f(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);

    // ✅ Option 2: Frog 2 steps peeche se aaya
    // Yeh tabhi possible hai jab idx >= 2 ho
    int right = INT_MAX;  // Initially kuch bhi nahi assume karte
    if (idx > 1)
        right = f(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);

    // ✅ Final answer for current index:
    // Dono options me se jo energy minimum lagi, wahi choose karo
    return dp[idx] = min(left, right);
}

// Main function to call our recursive + memoized function
int frogJump(int n, vector<int> &heights) {

    // DP array to store minimum energy at each step
    // Initialize sabhi elements with -1 (matlab abhi tak calculate nahi kiya)
    vector<int> dp(n + 1, -1);

    // Frog ko end tak pahuchna hai, i.e., index n-1 tak
    return f(n - 1, heights, dp);
}




// -----------
// memoization (top down) and tabulation (bottom up)


int frogJump(int n, vector<int> &heights) {
    vector <int> dp(n, 0);

    dp[0] = 0;

    for (int i=1; i<n; i++){
        // first step
        int fs = dp[i-1] + abs( heights[i] - heights[i-1] );
        int ss = INT_MAX;

        if (i>1) ss = dp[i-2] + abs( heights[i] - heights[i-2] );

        dp[i] = min(fs , ss);
     }
     return dp[n-1];
}

// now whenever there will be f(idx-1) and f(idx-2) => surely there will be space optimisation...

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights){
    int prev = 0;
    int prev2 = 0;

    for (int i=1; i<n; i++){
        int fs = prev + abs(heights[i] - heights[i-1]); // first step
        int ss = INT_MAX;

        if (i>1) ss = prev2 + abs(heights[i] - heights[i-2]);   // second step

        int curri = min(fs, ss);
        
        prev2 = prev;
        prev = curri;
    }

    return prev;
}



class Solution {
    public:
        bool canCross(vector<int>& stones) {
            int N = stones.size();
    
            // DP Table: dp[i][j] => stone 'i' pe 'j' jumps se aane ka possibility
            vector<vector<bool>> dp(N, vector<bool> (N+1, false));
    
            // Pehle stone se sirf 1 jump allowed hai (stones[0] se stones[1] tk jaane ka ek tarika)
            dp[0][1] = true;
            
            // Har stone ke liye check karenge ki kya wahan pahunch sakte hain
            for(int i = 1; i < N; ++i) {
                for(int j = 0; j < i; ++j) { // Previous stones traverse karenge
                    int diff = stones[i] - stones[j]; // Current stone tak aane ke liye required jump
    
                    // Agar required jump zyada hai ya is jump se pichle stone pe aana possible nahi tha
                    if(diff > N || !dp[j][diff]) 
                        continue; // Iska koi fayda nahi, next pe chalte hain
                    
                    // Agar last stone pe pahunch gaye, to seedha true return kar do
                    if(i == N - 1) 
                        return true;
                    
                    // Agar yeh jump possible hai, to is stone pe pahunch gaye
                    dp[i][diff] = true;
    
                    // Next possible jumps ko bhi mark karenge
                    if(diff - 1 >= 0) dp[i][diff - 1] = true; // Ek step chhota
                    if(diff + 1 <= N) dp[i][diff + 1] = true; // Ek step bada
                }
            }
    
            // Agar loop se bahar aa gaye, iska matlab last stone tak nahi pahunch sake
            return false;
        }
    };
    