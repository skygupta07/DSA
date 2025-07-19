// sqrt(x).cpp


/*

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2

Explanation: The square root of 4 is 2, so we return 2.


Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., 
and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 2e31 - 1

*/


class Solution {
public:

    int mySqrt(int x) {
        int lo = 0;
        int hi = x;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            long long m = (long long)mid; // typecasting and poh(principle of homogenity)
            long long y = (long long)x;

            if(m*m == y) return mid; // square nikal raha hai to square nikal bhi to...
            else if(m*m < y) lo = mid+1;
            else hi = mid-1;
        }

        return hi;  // in case number is not perfect square - return lower bound
    } 
};

// binary search mai hamesha main role mid aur target element ka hi hota hai....
// so we also modified them also...

// binary search mai jab bhi loop break hota hai.. "hi" pointer aapka lower bound pe hota hai..
// and "lo" pointer aapka upper bound pe hota hai.....



// -------- ----------

class Solution {
public:

    int mySqrt(int x){
        if (x == 0 || x == 1) return x;

        long long lo = 0;
        long long hi = x;

        while (lo <= hi){
            long long mid = lo + (hi-lo)/2;
            
            if (mid*mid == x) return mid;

            else if (mid*mid < x) lo = mid+1;
            
            else hi = mid-1;
        }

        return hi;    // in case number is not perfect square - return lower bound {sqrt(8) = 2}

        /*
        if the number is not perfect square then lower bound* return karwaya.
         jaha ki lower bound after the loop obviously hi hoga...(binary search mai loop hi iss tarah 
        se tutta hai...)
        */

    }
};