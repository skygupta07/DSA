// divideTwoIntegers.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two integers dividend and divisor, divide two integers without using multiplication, 
division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit 
signed integer range: [−2pow31, 2pow31 − 1]. For this problem, 
if the quotient is strictly greater than 2pow31 - 1, then return 2pow31 - 1, 
and if the quotient is strictly less than -2pow31, then return -2pow31.
 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0



*/



class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special case: INT_MIN ko -1 se divide karne pe overflow ho jaata hai
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Sign check kar rahe hain: agar ek negative hai aur dusra positive to answer negative hoga
        bool negative = (dividend < 0) ^ (divisor < 0); // XOR se sign ka pata chalta hai

        // Dividend aur divisor ko long long me convert karke unka absolute le rahe hain
        // Taaki INT_MIN ko safely handle kar saken
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long result = 0;

        // Jab tak dividend bada hai divisor se, tab tak subtract karte rahenge
        // But subtract directly nahi karenge, har baar double karenge taaki fast chale (bit shifting se)
        while (a >= b) {
            long long temp = b, multiple = 1;

            // Jab tak temp ka double a ke andar fit ho raha hai, double karte jao
            while (a >= (temp << 1)) {
                temp <<= 1;       // temp = temp * 2
                multiple <<= 1;   // multiple = multiple * 2
            }

            // temp ko a se subtract karo aur multiple ko result me add karo
            a -= temp;
            result += multiple;
        }

        // Agar result negative banna chahiye tha, to usko negative bana do
        result = negative ? -result : result;

        // Final check: result INT range ke andar hi hona chahiye
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return result;
    }
};
