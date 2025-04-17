#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {

        // Step 1: Variable Initialization
        int n = s.length(); // String ki length store kar rahe hain.
        long long int sum = 0; // Final expression ka result yahan store hoga.
        int sign = 1; // Current sign (+1 ya -1) track karne ke liye.

        stack <pair <int, int> > st; 
        // Stack ko use kar rahe hain to handle nested parentheses. 
        // Stack me "sum" aur "sign" ka state push karenge jab parentheses milega.

        // Step 2: Iterate through the string

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) { 
                // Agar character ek digit hai, to number parse karenge.
                long long int num = 0;

                // Multiple digits ke liye loop chalayenge.
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0'); 
                    // Num ko construct kar rahe hain ek ek digit ko add karke.
                    i++;
                }

                i--; // Ek extra increment hua hai, to wapas ek step piche le aate hain.

                sum += num * sign; 
                // Current sign ke according number ko sum me add/subtract karenge.

                sign = 1; // Sign ko reset karna zaroori hai, kyunki default plus hi hai.
            } 

            // Parentheses ka opening mila.
            else if (s[i] == '(') { 

                // Current sum aur sign ko stack me push kar diya.
                st.push({sum, sign}); 
                sum = 0; // New scope ke liye sum ko reset kar diya.
                sign = 1; // Aur sign bhi reset kar diya.
            } 

            else if (s[i] == ')') { 
                // Closing parenthesis mila.    
                // ( 1 + () ) yes it handles that case as well...
                sum = st.top().first + (st.top().second * sum); 

                // Nested result ko combine karte hain.
                st.pop(); // Stack se state nikal diya.
            } 
            else if (s[i] == '-') { 
                // Minus sign mila, to current sign ko flip kar diya.
                sign = -1 * sign;
            }
        }

        return sum; 
        // Expression ka final result return karenge.
    }
};


/*
Approach

When the algorithm encounters a digit, it parses the digits as a number and pushes the number onto the stack.
When the algorithm encounters an operator, it pops two numbers off the stack, performs the operation, and pushes the result back onto the stack.
When the algorithm encounters a left parenthesis, it pushes the current state of the stack onto a new stack.
When the algorithm encounters a right parenthesis, it pops the top stack, performs the operations on the numbers on the top of the stack, and pushes the result back onto the stack.
After iterating over the entire string, the algorithm pops the top number off the stack and returns it as the result of the expression.

*/