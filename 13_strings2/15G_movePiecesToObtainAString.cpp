// movePiecesToObtainAString.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given two strings start and target, 
both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only 
if there is a blank space directly to its left, and a piece 'R' can move to the right only 
if there is a blank space directly to its right.

The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
Return true if it is possible to obtain the string target 
by moving the pieces of the string start any number of times. Otherwise, return false.
 

Example 1:

Input: start = "_L__R__R_", target = "L______RR"
Output: true

Explanation: We can obtain the string target from start by doing the following moves:

- Move the first piece one step to the left, start becomes equal to "L___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___R".
- Move the second piece three steps to the right, start becomes equal to "L______RR".

Since it is possible to get the string target from start, we return true.


Example 2:

Input: start = "R_L_", target = "__LR"
Output: false

Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.


Example 3:

Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
 

Constraints:

n == start.length == target.length
1 <= n <= 1e5
start and target consist of the characters 'L', 'R', and '_'.

*/

class Solution {
public:

    bool canChange(string start, string target) {
        int n = start.length();

        // Step 1: Check if relative order of 'L' and 'R' is same in both strings
        // '_' (underscore) doesn't matter for this part

        string startPieces, targetPieces;

        // only 'L' and 'R' store kar rahe hain
        for (char ch : start) {
            if (ch != '_') startPieces += ch; 
        }

        // only 'L' and 'R' store kar rahe hain
        for (char ch : target) {
            if (ch != '_') targetPieces += ch;
        }

        // Agar sequence of 'L' and 'R' match nahi karti, toh kabhi bhi match possible nahi hoga
        if (startPieces != targetPieces) return false;

        /*
            'L' sirf left move kar sakta hai
            'R' sirf right move kar sakta hai

            Hum yeh ensure karna chahte hain ki:
            1. 'L' jo bhi position pe hai start me, wo target me ussi ya left side me hi hona chahiye
            2. 'R' jo bhi position pe hai start me, wo target me ussi ya right side me hi hona chahiye
        
        */

        // Step 2: Check movement constraint for 'L'

        int j = 0; // pointer for target string

        for (int i = 0; i < n; i++) {

            if (start[i] == 'L') {
                // Jab tak target[j] me 'L' nahi milta, aage badhte jao
                while (target[j] != 'L') j++;

                // 'L' cannot move right (i < j => matlab start[i] pe 'L' hai 
                // but target[j] pe hona chahiye, which is right side)

                if (i < j) return false;

                j++; // next match ke liye
            }

        }

        // Step 3: Check movement constraint for 'R'

        j = 0; // Reset target pointer

        for (int i = 0; i < n; ++i) {
            if (start[i] == 'R') {

                // target me jab tak 'R' nahi milta, aage badho
                while (target[j] != 'R') j++;

                // 'R' cannot move left (i > j => matlab start[i] me 'R' hai but target[j] me wo left chala gaya, invalid)
                if (i > j) return false;

                j++; // next match ke liye
            }
        }

        // All constraints satisfied
        return true;
    }
};
