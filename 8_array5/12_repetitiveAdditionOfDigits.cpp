// repetitiveAdditionOfDigits.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given a positive integer n, you need to add all the digits of n and create a new number. 
Perform this operation until the resultant number has only one digit in it. 
Return the final number obtained after performing the given operation.

Examples:

Input: n = 1234
Output: 1

Explanation: Step 1: 1 + 2 + 3 + 4 = 10. Step 2: 1 + 0 = 1

Input: n = 5674
Output: 4

Explanation: Step 1: 5 + 6 + 7 + 4 = 22. Step 2: 2 + 2 = 4


Input: n = 9
Output: 9
Explanation: Since 9 is a single-digit number hence we return 9.


Constraints:
1 <= n <= 1e9

*/


class Solution {
public:

    int singleDigit(int n) {
       int sum = n;
       
       while (sum > 9){
           
           int digitSum = 0;
           
           while (sum > 0){
               digitSum += sum % 10;
               sum = sum / 10;
           }
        
           // for nextStep
           sum = digitSum;
       }
       
       return sum;
    }
};
