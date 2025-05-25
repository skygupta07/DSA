#include <bits/stdc++.h>
using namespace std;

/*

Given two non-negative integers, num1 and num2 represented as string, 
return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers 
(such as BigInteger). You must also not convert the inputs to integers directly. 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"


Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"


Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 10pow4

num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeroes except for the zero itself.

*/


class Solution {
public:

        string addStrings(string num1, string num2) {
            int m = num1.length();
            int n = num2.length();
            
            // jaise sach mai multiply karte h waise hi simulate karna h ekdum...
            // so pointers ko last mai rakh dono numbers ke...

            int i = m - 1; // Pointer for num1
            int j = n - 1; // Pointer for num2
    
            int carry = 0; // Carry for addition
            string ans = ""; // Result string
            
            // Process until all digits and carry are handled
            while (carry || i >= 0 || j >= 0){

                int f = (i >= 0) ? (num1[i] - '0') : 0; // Get digit from num1 or 0
                //  {zero tab contribution count ho rha hoga jab ye wala number khatam ho chuka hoga 
                // dusre ke mukable..} if i < 0

                int s = (j >= 0) ? (num2[j] - '0') : 0; // Get digit from num2 or 0 if j < 0
                
                // Sum current digits + carry
                int sum = f + s + carry;
    
                ans += to_string(sum % 10); // Append last digit of sum to result
                carry = sum / 10; // Update carry
                
                // get ready for the next round
                i--; // Move to next digit in num1
                j--; // Move to next digit in num2
            }
            
            // Reverse the string as we built it from least significant digit
            reverse(ans.begin(), ans.end()); 
            return ans;
        }
    };
    