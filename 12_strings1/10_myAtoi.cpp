#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isNumeric(char ch) {
        return ch >= '0' && ch <= '9';
    }

    int myAtoi(char *s) {
        int n = strlen(s);
        int maxInt = INT_MAX;
        int minInt = INT_MIN;

        int i = 0;
        // Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Handle optional sign
        bool isNegative = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            isNegative = (s[i] == '-');
            i++;
        }

        // Convert digits to integer
        int sum = 0;
        while (i < n && isNumeric(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow
            if (sum > (maxInt - digit) / 10) {
                return isNegative ? minInt : maxInt;
            }

            sum = sum * 10 + digit;
            i++;
        }

        return isNegative ? -sum : sum;
    }
};


/*
sign ke liye variable
zero positive negative nahi hota..

agar postive number jyadd bada h to max wla return kar dena h..
same for negative elements also...

number ke baad bakchodi not allowed....



*/