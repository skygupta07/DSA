#include <bits/stdc++.h>
using namespace std;

/*
Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive
*/

class Solution{
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) right = (right & (right - 1));
        return right;  
    }
};


/*
bit wale questions mai testcases ke numbers ko bits mai likho then analyse karo...

always remember that right AND right-1    removes last set bit of numbers...(method 1)


method2 to remove last set bit of n....  n -= (n & -n)

and operation se basically hum reduction hi karte hai.  ab smartly bas un moves ko skip kar do...jin 
moves ko karne ya na karne se koi fark nahi padta brother....

reducing one bit at a time so say at most we will be removing 32 bits only

right ko right-1 karte chalo jab to left ko na reach kare...

*/
