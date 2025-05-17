
// sumOfTwoIntegers.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given two integers a and b, return the sum of the two integers without 
using the operators + and -.


Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5

*/

class Solution {
    public:
        int getSum(int a, int b) {
            int sum = a;  // Sum ko initially 'a' se initialize kar diya
            
            uint32_t carry = b; // Carry ko 'b' se initialize kiya
            
            while (carry) {  // Jab tak carry non-zero hai, tab tak loop chalega
                sum = a ^ carry;  // XOR operation => bina carry ka sum nikalta hai (binary addition jaisa)
                
                carry = (a & carry) << 1;  // Carry nikalne ke liye AND operation, phir left shift (<< 1)
                
                a = sum;  // Updated sum ko a me store kar diya taaki next iteration ke liye kaam aaye
            }
    
            return sum;  // Final sum return ho jayega
        }
    };
    