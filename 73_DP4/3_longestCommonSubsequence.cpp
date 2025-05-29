#include <bits/stdc++.h>
using namespace std;

/*

Given two strings text1 and text2, 
return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

A subsequence of a string is a new string 
generated from the original string with some characters 
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.


Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.


Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.


Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

*/



class Solution {
public:

    int f(string &s, string &t, vector <vector <int> >& dp , int i, int j){
        // base case
        if (i < 0 || j < 0) return 0;

        // base case ke baad dp ki help 
        if (dp[i][j] != -1) return dp[i][j];

        // cases dekh ke dp ko bharna....
        // case 1 - agar dono character match ho gaye to phir dono index subtract honge...
        if (s[i] == t[j]){
            return dp[i][j] =  1 + f(s, t, dp, i-1, j-1);
        }
        // case 2 -> not equal - do phir yahi to dp ka asli use aaya ki dono case consider karo 
        // return karo max dono cases ka.... ha obviously return karna matlab dp mai store hi karna...

        else{
            return dp[i][j] = max(f(s, t,dp, i-1, j), f(s, t, dp, i, j-1));
        }
    }


    int longestCommonSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector <vector <int> > dp(m, vector <int> (n, -1));

        // iss question ki sabse sahi yahi baat lagi ki bc dono string ko ulta traverse kar rahe h...
        return f(s, t, dp, m-1, n-1);
    }
};


/*
dp on string
need two variable -> i and j keep both on end of string s and t respectively 

now at each index there will be two cases 
    case 1 -> either both of the index elements are equal then they contribute 1 length and both index will go back...

    case 2 -> not both are equal then... dono ko ek ek baar peeche karke dekha... 
    dono mai se jisme bhi max wala answer hoga wahi answer hoga.....

    base cases -> if any of the index goes negative theb return 0;

NOTice : ek cheej mene dekhi ki jab mene s aur t ko reference se pass nahi kara tha to TLE aa gaya tha.....
    uska reason yahi hai ki har call ke liye dono dono copy pass ho raha hoga .......

*/


// end solution ----- 


class Solution {
public:

    vector <vector<int>> dp;   // fbu

    int f(string &s1, string &s2, int i, int j){
        // base cases
        if (i >= s1.size()) return 0;
        if (j >= s2.size()) return 0;

         // already computed then return it from dp
        if (dp[i][j] != -1) return dp[i][j];   
        
        // fn calls and storing in dp
        if (s1[i] == s2[j]){
            return dp[i][j] = 1 + f(s1, s2 , i+1, j+1);
        }
        else{
            return dp[i][j] = max(f(s1,s2,i+1,j), f(s1,s2,i,j+1));
        }
    }
    // take i+1 and j or take i and j+1 while other case of not taking both is itself included
    // in the recursive calls...


    int longestCommonSubsequence(string s1, string s2){
        dp.clear();
        dp.resize(1005, vector <int>(1005,0));

        for (int i=s1.size()-1; i>=0; i--){
            for (int j=s2.size()-1; j>=0; j--){

                if (s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }

                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        } 

        return dp[0][0];       
    }
};


//now function bottom up likhne ke liye order dekhna padega... since yaha par ith state ko compute karne 
// ke liye...aapko i+1 aur i+2th and so on  state ka answer chahiye it means pehle aage wale hi 
// compute karke laao....i.e. go from right to left or LOOP ULTa ChalAWa

// -> agar kabhi aapko line by line output print karani pad jae tab fbu ki 


// grid ko print kara do...


int main(){

}



/*


Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with 
some characters (can be none) deleted without changing the relative order 
of the remaining characters.



*/