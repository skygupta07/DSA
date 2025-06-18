// minimumChangestToMakeAlternatingBinaryString.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given a string s consisting only of the characters '0' and '1'. 
In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. 
For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.


Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.


Example 2:

Input: s = "10"
Output: 0
Explanation: s is already alternating.


Example 3:

Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".
 

Constraints:

1 <= s.length <= 104
s[i] is either '0' or '1'.

*/


class Solution {
public:

    int minOperations(string s) {
        int n = s.length();

        if (n == 1) return 0;

        if (n == 2){
            if (s[0] != s[1]) return 0;
            else return 1;
        }

        // Two patterns possible: "010101..." or "101010..." - ya to zero se start ho ya phir one se start hoga..
        int count1 = 0, count2 = 0;
        
        // Count the changes needed for "010101..." case where string starts from zero....i.e. even index pe zero hona 
        // chahiye ideally and odd index pe 1... aur agar aisa nahi h to phir ussey count mai include karo...
        for (int i = 0; i < n; i++) {
            // agar even index par
            if (i % 2 == 0) {
                // element zero na mile to phir count to lagega..
                if (s[i] != '0') count1++;
            } 

            else {
                if (s[i] != '1') count1++;
            }
        }

        // Count the changes needed for "101010..."
        for (int i = 0; i < n; i++){

            if (i % 2 == 0) {
                if (s[i] != '1') count2++;
            }

            else {
                if (s[i] != '0') count2++;
            }

        }

        // Return the minimum of the two counts
        return min(count1, count2);
    }
};


/*
easy questions mai possible cases hi soch liya karo....
*/