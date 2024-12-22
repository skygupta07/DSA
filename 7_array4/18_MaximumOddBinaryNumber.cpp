#include <bits/stdc++.h>
using namespace std;

/*
You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary
number that can be created from this combination.
Return a string representing the maximum odd binary number that can be created from the given combination.
Note that the resulting string can have leading zeros.
*/

class Solution {
public:
    string maximumOddBinaryNumber(string s){
        int n = s.length();
        int zeroCount = 0;
        int oneCount = 0;
        for (int i=0; i<n; i++){
            if (s[i] == '0') zeroCount++;
            else oneCount++;
        }
        string ans;
        // append n-1 ones at beginning then appen all zeroes then finally 1 at end...
        while (oneCount>1){
            ans += '1';
            oneCount--;
        }

        while (zeroCount--){
            ans += '0';
        }
        ans+= '1';

        return ans;
    }
};


// for odd -> keep single 1 at end and for remaining oneCount add them in very beginning...