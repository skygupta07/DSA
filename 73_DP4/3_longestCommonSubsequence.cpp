#include <iostream>
using namespace std;

class Solution {
public:
    vector <vector<int> > dp;   // fbu
    int f(string &s1, string &s2, int i, int j){
        if (i>= s1.size()) return 0;
        if (j>= s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];    // already computed then return it from dp
        if (s1[i] == s2[j]){
            return dp[i][j] = 1 + f(s1, s2 , i+1, j+1);
        }else{
            return dp[i][j] = max(f(s1,s2,i+1,j), f(s1,s2,i,j+1));
        }
    }
    // take i+1 and j or take i and j+1 while other case of not taking both is itself included
    // in the recursive calls...


    int longestCommonSubsequence(string s1, string s2){
        dp.clear();
        dp.resize(1005, vector <int> (1005,0));

        for (int i=s1.size()-1; i>=0; i--){
            for (int j=s2.size()-1; j>=0; j--){
                if (s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        } 
        return dp[0][0];       
    }
};


//now function bottom up likhne ke liye order dekhna padega... since yaha par ith state ko compute karne 
// ke liye...aapko i+1 aur i+2 th and so on  state ka answer chahiye it means pehle aage wale hi 
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