// differentWaysToAddParanthesis.cpp


/*

Given a string expression of numbers and operators, 
return all possible results from computing all the different possible ways 
to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer 
and the number of different results does not exceed 10pow4

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2


Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔧 Helper function: Performs the operation on two integers
    int perform(int x, int y, char op) {

        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;

        return 0; // default case (should not occur)
    }
    
    // 💡 Main function: Computes all possible results from different ways of parenthesizing the expression
    vector<int> diffWaysToCompute(string exp) {

        vector <int> results; // Stores all possible results
        bool isNumber = true; // Flag to check if the string is just a number

        /*
         🧠 Intuition & Logic:
         -------------------------------------
         Har operator par expression ko tod kar 
         left aur right substrings ke results nikalte hain recursively.
         Fir un sab combinations ko evaluate karte hain.
         */

        for(int i = 0; i < exp.length(); i++) {
            // Agar current character koi operator hai ('+', '-', '*')
            if(!isdigit(exp[i])) {
                isNumber = false; // means it's not just a number anymore

                // ✂️ Divide expression into two parts: left and right
                string leftExpr = exp.substr(0, i);        // [0...i-1]
                string rightExpr = exp.substr(i + 1);      // [i+1...end]

                // 🔁 Recursive calls to compute results of sub-expressions
                vector<int> left = diffWaysToCompute(leftExpr);
                vector<int> right = diffWaysToCompute(rightExpr);

                // 🧮 Combine results from left and right parts using current operator
                for(int x : left) {
                    for(int y : right) {
                        int val = perform(x, y, exp[i]);
                        results.push_back(val); // Store each computed value
                    }
                }
            }
        }

        // 📌 Base case: If the expression is just a number (no operator)
        if(isNumber) results.push_back(stoi(exp)); // Convert string to integer and return

        return results;
    }
};
