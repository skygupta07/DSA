#include <bits/stdc++.h>
using namespace std;

/*

You are given a positive integer n, you need to add all the digits of n and create a new number.
Perform this operation until the resultant number has only one digit in it. 
Return the final number obtained after performing the given operation.

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
