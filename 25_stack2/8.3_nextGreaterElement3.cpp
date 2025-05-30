#include <bits/stdc++.h>
using namespace std;

/*

Given a positive integer n, find the smallest integer which has exactly the same digits
existing in the integer n and is greater in value than n. 
If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, 
if there is a valid answer but it does not fit in 32-bit integer, return -1.
 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1

*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);  // Convert integer to string for easier manipulation

        // Step 1: Find the first decreasing digit from the right
        int i = num.length() - 2;
        while (i >= 0 && num[i] >= num[i + 1]) 
            i--;

        // If no such digit is found, it means the number is the largest permutation
        if (i == -1) return -1;

        // Step 2: Find the smallest digit to the right of 'i' that is larger than num[i]
        int k = num.size() - 1;
        while (num[i] >= num[k]) 
            k--;

        // Step 3: Swap the found digits to get the next greater arrangement
        swap(num[i], num[k]);

        // Step 4: Reverse the digits to the right of 'i' to get the smallest possible number*
        reverse(num.begin() + i + 1, num.end());

        // Convert back to integer
        long ans = stol(num);

        // Step 5: Check for 32-bit integer overflow
        if (ans > INT_MAX) return -1;

        return ans;
    }
};
