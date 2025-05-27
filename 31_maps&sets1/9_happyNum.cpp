#include <bits/stdc++.h>
using namespace std;

/*

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1.


Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 
Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1


Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 2pow31 - 1

*/


class Solution {
public:

    int digitSquareSum(int n){
        int sum = 0;

        while (n!=0){   // ha yaha not equal to zero tak hi chalana padega.. 
            // or it is equivalent to while (n > 0)
        /// ekdum usko tod tod ke zero kar dena h...

            int ld = n%10;
            sum += ld*ld;
            n = n/10; // for next iteration

        }

        return sum;
    }

    bool isHappy(int n){
       unordered_set <int> set;

       while (n!=1 && !set.count(n)){
           set.insert(n);
           n = digitSquareSum(n);   // for next iteration...
       }

        // is while loop se bahar aaye to do case either n == 1 => happ num => return true;
        // else set.count(n) =1 matlab element present mil gya hoga jo ki ab waha se loop start ho jaega...
        // otherwise saare hi unique aate they agar directly wo 1 as a sum de deta to...
        return (n==1);   
    }
};

// jab yaha mujhe uski frequency wagera store hi nahi karwani to hashmap kyu use karu... 
// I just have to check
// whether the element is present or not which can be done using the unordered_set itself..
// set.count(n) -> returns boolean value whether n has been encountered in the set once or not....
