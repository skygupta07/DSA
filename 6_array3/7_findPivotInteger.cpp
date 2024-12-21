#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between
x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. 
It is guaranteed that there will be at most one pivot index for the given input.
*/

class Solution {
public:
    int sum(int i, int j){
        return j*(j+1)/2;
    }

    int pivotInteger(int n) {
        int total = 0;
        for (int i=1; i<=n; i++){
            total += i;
        }

        for (int j=1; j<=n; j++){
            if ( sum(1,j) == total - sum(1,j) + j) return j;    // better do with basics....
        }
        return -1;
    }
};

