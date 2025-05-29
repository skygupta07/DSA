// editDistance.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given two strings word1 and word2, 
return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3


Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')


Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5

Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

class Solution {
    public:
    
        int f(string &word1, string &word2, vector <vector <int> > &dp, int i, int j){
            // base case 
            if (i < 0) return j + 1;
            if (j < 0) return i + 1;
    
            // base case ke baad dp ki help
            if (dp[i][j] != -1) return dp[i][j];
    
            // possible cases at index -> both chars will be same or will not be same...
            // if both are same..
            if (word1[i] == word2[j]) return dp[i][j] =  0 + f(word1, word2, dp, i-1, j-1);
    
            // if both characters are not same then do min of three options available ..
            else{
                    // insert kara bhartually ek aage badhaye and then dono ko peeche kiya...
                int opt1 = 1 + f(word1, word2, dp, i, j-1);
    
                // delete karna...
                int opt2 = 1 + f(word1, word2, dp, i-1, j);
    
                // replace kara char -> to ab to dono same ho gaye honge... so ek ek step back kiya..
                int opt3 = 1 + f(word1, word2, dp, i-1, j-1);
    
                return dp[i][j] = min(opt1, min(opt2, opt3));
            }
        }
    
        // word1 ko word2 banana hai to word1 par hi to operation karna hoga...
    
    
        int minDistance(string word1, string word2) {
            int m = word1.length();
            int n = word2.length();
    
            vector <vector <int> > dp(m, vector <int>(n, -1));
    
            return f(word1, word2, dp, m-1, n-1);
        }
    };
    
    
    
    /*
    f function will give me the minimum number of operations required to 
    convert word1(start from 0 index to last index..... calculate waise last index se zeroth index ki taraf hoga...)
     to word2.....
    
    */


    class Solution {
        public:
        
            // Recursive function to calculate the minimum edit distance
            int f(string &word1, string &word2, vector<vector<int>> &dp, int i, int j) {
                // Base cases:
                // If word1 is exhausted, the only option is to insert remaining characters of word2
                if (i < 0) return j + 1;
                // If word2 is exhausted, the only option is to delete remaining characters of word1
                if (j < 0) return i + 1;
        
                // If already computed, return the stored result to avoid recomputation
                if (dp[i][j] != -1) return dp[i][j];
        
                // Case when characters at index i and j are the same
                // No operation is needed, move to the previous characters
                if (word1[i] == word2[j]) 
                    return dp[i][j] = f(word1, word2, dp, i - 1, j - 1);
        
                // If characters are different, we have three choices:
                else {
                    // 1. Insert a character: Virtually insert word2[j] into word1 and move j back
                    int opt1 = 1 + f(word1, word2, dp, i, j - 1);
        
                    // 2. Delete a character: Remove word1[i] and move i back
                    int opt2 = 1 + f(word1, word2, dp, i - 1, j);
        
                    // 3. Replace a character: Change word1[i] to match word2[j], then move both back
                    int opt3 = 1 + f(word1, word2, dp, i - 1, j - 1);
        
                    // Return the minimum of the three operations
                    return dp[i][j] = min(opt1, min(opt2, opt3));
                }
            }
        
            // Function to find the minimum number of operations to convert word1 to word2
            int minDistance(string word1, string word2) {
                int m = word1.length();  // Length of word1
                int n = word2.length();  // Length of word2
        
                // DP table initialized with -1 (indicating uncomputed values)
                vector<vector<int>> dp(m, vector<int>(n, -1));
        
                // Start recursion from the last index of both words
                return f(word1, word2, dp, m - 1, n - 1);
            }
    };
    