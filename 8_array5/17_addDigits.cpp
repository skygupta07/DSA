// addDigits.cpp

#include <bits/stdc++.h>
using namespace std;


/*
Given an integer num, repeatedly add all its digits until the result has only one digit, 
and return it.


Example 1:

Input: num = 38
Output: 2

Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.


Example 2:

Input: num = 0
Output: 0

*/

class Solution {
public:
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {   
            sum += num % 10; // kewal sum hi karna h
            num /= 10;
        }
        
        return sum;
    }

    int addDigits(int num) {

        while (num >= 10) {
            num = digitSum(num); // update the num variable accordingly...
        }

        return num;
    }
};


/*
Follow up: Could you do it without any loop/recursion in O(1) runtime?
*/


class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        else if (num % 9 == 0) return 9;
        else return num % 9;
    }
};


/*
N % 9 = sum_of_digits(N) % 9


Also simple idea why digital root equals to mod 9 if we've got an ABCD number
ABCD = 1000A+100B+10*C+D = (A + B + C + D) + 9 * (111 * A + 11 * B + C)
this equals (mod 9) to A + B + C + D.
*/