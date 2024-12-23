#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkValidString(string s) {
        stack <int> openBrackets, asterisks;

        for (int i=0; i<s.length(); i++){
            char ch = s[i];
            
            if (ch == '(') openBrackets.push(i);    // index hi push kiya karo..
            else if (ch == '*') asterisks.push(i);

            else if (ch == ')'){
                // closing bracket aane par ab teen case ..
                if (!openBrackets.empty()) openBrackets.pop();
                else if (!asterisks.empty()) asterisks.pop();
                else return false;  // since you are stucked..
            } 
        }

        while (!openBrackets.empty() && !asterisks.empty()){ // condition false to openBrakckets ko hi empty karke hi hogi..
            // check that astersiks index should be greater than opening bracket..
            if (openBrackets.top() > asterisks.top()) return false;

            // dono se hi ek ek pop karwa diya...
            openBrackets.pop();
            asterisks.pop();
        }
        return openBrackets.empty();
    }
};

/*
I will maintain one stack to push opening brackets and will maintain another stack to maintain count of star...
starStack helps in case you need help by making pairs ....wo jaruri nahi ki end mai empty hi ho ....but ha hammara
opening bracket wala stack ko to khali hona hoga....

*/

// ---------------

class Solution {
public:
    bool isValidString(int i, int openCount, string &s, vector <vector<int> > &dp){
        if (i == s.size()) return (openCount == 0); // base case

        if (dp[i][openCount] != -1) return dp[i][openCount];

        bool isValid = false;
        if (s[i] == '*'){
            isValid |= isValidString(i+1, openCount+1, s, dp);  // treating * as '('
            if (openCount){
                isValid |= isValidString(i+1, openCount-1, s, dp);    // treating * as '(
            }

            isValid |= isValidString(i+1, openCount, s, dp);    // treat * as emtpy...
        }
        else{   // opening , closing bracket cases..
            if (s[i] == '('){
                isValid = isValidString(i+1, openCount+1, s, dp);
            }
            else if (openCount){    // matlab openCount > 0
                isValid = isValidString(i+1, openCount-1, s, dp);
            }
        }
        return dp[i][openCount] = isValid;
    }




    bool checkValidString(string s) {
        int n = s.size();
        vector <vector <int>> dp(n, vector <int> (n,-1));
        return isValidString(0,0,s,dp);
    }
};

/*
I have threee options to put on....

valid paranthesis wale question ke liye.....stack waala solution and opening bracket ko hi open ke liye increment
and close ke liye decrement karke finally zero pe leke aane waala solution...

method 1 -> Recursion (DP)

*/



//  ---------------- two pointer ----------

class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0;
        int closeCount = 0;
        int n = s.length();

        for (int i=0; i<n; i++){
            if (s[i] == '(' || s[i] == '*') openCount++;
            else openCount--;

            // ab back se iterate karenge and closeCount ko dekhte hai...

            if (s[n-i-1] == ')' || s[n-i-1] == '*') closeCount++;
            else closeCount--;

            // checking at any moment the status of openCount and closeCount if they become negative at anypoint then 
            // return false 
            if (openCount < 0 || closeCount < 0) return false; 
        }
        return true;
    }
};