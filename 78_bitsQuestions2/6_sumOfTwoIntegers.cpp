
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
    

class Solution {
public:
    int getSum(int a, int b) {

        // Edge cases: if one number is 0, return the other directly
        if (a == 0) return b;
        if (b == 0) return a;

        int sum = 0;        // Final result will be stored here
        int mask = 1;       // Mask to isolate bit positions (starting from LSB)
        
        int c = 0;          // Carry bit (0 or 1)

        // Loop until mask becomes 0 (i.e., passed all 32 bits)
        while (mask != 0) {

            // Extract current bits of a and b using mask
            int m1 = (a & mask) != 0 ? 1 : 0;
            int m2 = (b & mask) != 0 ? 1 : 0;

            // Case 1: Both bits are 1 (1 + 1)
            if (m1 == 1 && m2 == 1) {
                if (c == 1) sum |= mask; // 1 + 1 + 1 = 1 carry 1
                
                c = 1; // Always carry 1 in this case
            }

            // Case 2: One of the bits is 1, other is 0 (1 + 0 or 0 + 1)
            else if ((m1 ^ m2) == 1) {
                
                if (c == 1) c = 1; // 1 + 0 + 1 = 0 carry 1 (but no change to sum)
                else sum |= mask; // 1 + 0 = 1, carry 0
            }

            // Case 3: Both bits are 0
            else {
                if (c == 1) sum |= mask; // 0 + 0 + 1 = 1
                
                c = 0; // No carry forward
            }

            // Shift mask to next bit position
            mask = (0xffffffff & mask) << 1;

            // Early termination (custom condition to avoid infinite loop)
            // If mask goes beyond what's needed to represent both numbers
            if (mask > 2 * max((a & 0xffffffff) << 1, (b & 0xffffffff) << 1)) break;
        
        }

        return sum; // Return final result
    
    }

};