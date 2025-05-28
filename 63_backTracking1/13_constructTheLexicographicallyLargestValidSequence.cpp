#include <bits/stdc++.h>
using namespace std;


/*

Given an integer n, find a sequence with elements in the range [1, n] 
that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], 
is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. 
It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) 
if in the first position where a and b differ, 
sequence a has a number greater than the corresponding number in b. 
For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] 
because the first position they differ is at the third number, and 9 is greater than 5.
 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, 
but [3,1,2,3,2] is the lexicographically largest valid sequence.


Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
 
Constraints:

1 <= n <= 20

*/


class Solution {
    public:
    
        bool backtrack(vector<int> &ans, vector<bool> &used, int n, int idx) {
            // Pehle next empty position tak chalein (jo 0 ho)
            while (idx < ans.size() && ans[idx] != 0) idx++;
    
            // Agar pura array fill ho gaya toh return true (base case)
            if (idx == ans.size()) return true;
    
            // Largest se smallest number tak try karenge (lexicographically largest sequence)
            for (int i = n; i >= 1; i--) {
                // Agar yeh number pehle se used hai toh skip kar do
                if (used[i]) continue;
    
                if (i == 1) { // Agar number 1 hai toh bas ek hi baar place karna hoga
                    ans[idx] = 1;
                    used[1] = true;
    
                    // Backtrack call kar rahe hain, agar true return hua toh answer mil gaya
                    if (backtrack(ans, used, n, idx + 1)) return true;
    
                    // Agar galat rasta nikla toh undo (backtracking)
                    ans[idx] = 0;
                    used[1] = false;
                } 
                
                // Baaki numbers ke liye, check karenge ki idx + i valid hai ya nahi
                else if (idx + i < ans.size() && ans[idx + i] == 0) {
                    ans[idx] = i;
                    ans[idx + i] = i;
                    used[i] = true;
    
                    // Agar sahi placement mil gaya toh return true
                    if (backtrack(ans, used, n, idx + 1)) return true;
    
                    // Nahi mila toh backtrack karke values reset karenge
                    ans[idx] = 0;
                    ans[idx + i] = 0;
                    used[i] = false;
                }
            }
    
            // Koi bhi valid placement nahi mili toh return false
            return false;
        }
    
    
    
        vector<int> constructDistancedSequence(int n) {
            // Result array ka size 2 * n - 1 hoga{kyuki sab do bar aayenge expect 1 single time aayega..},
            //  initially sab 0 se intialise kiya.. 
            vector<int> ans(2 * n - 1, 0);

            // Used array track karega ki kaunsa number place ho chuka hai
            vector<bool> used(n + 1, false);
    
            // Backtracking start kar rahe hain 0th index se
            backtrack(ans, used, n, 0);
            
            return ans;
        }

    };
    