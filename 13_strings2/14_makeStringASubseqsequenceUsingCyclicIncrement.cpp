#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

    char nextChar(char ch) {
        return ch == 'z' ? 'a' : ch + 1;
    }


    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        if (n > m) return false;
        
        // two pointers
        int i = 0;
        int j = 0;

        while (i <= m-1 && j <= n-1){
            if (str1[i] == str2[j] || nextChar(str1[i]) == str2[j] ){
                i++;
                j++;
            }
            else i++;
        }

        if (j == n) return true;
        else return false;

    }
};




/*
string 1 mai changes karke ... usko aisa banana hi ki uska tukda str2 ban jaye..


*/