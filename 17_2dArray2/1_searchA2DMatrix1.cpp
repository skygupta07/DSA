// searchA2DMatrix.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.


Example 1:

Input: matrix = [[1,3,5,7],
                [10,11,16,20],
                [23,30,34,60]],       target = 3
Output: true


Example 2:

Input: matrix = [[1,3,5,7],
                [10,11,16,20],
                [23,30,34,60]],        target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10pow4 <= matrix[i][j], target <= 10pow4


*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target){
        int r = arr.size();
        int c = arr[0].size();

        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (arr[i][j] == target){
                    return true;
                    break; // jab true ussi time return kar diya to phir as such break likhne ki koi need hi nahi h..
                    // control kabhi iss line tak pahuchega hi nahi...
                }
            }
        }
        return false;
        
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target){
        int m = v.size();
        int n = v[0].size();

        int lo = 0;
        int hi = m*n - 1;

        while (lo <= hi){
            int mid = lo + (hi-lo)/2;

            // when you are assuming matrix to be in linear form and then
            // actually want to fetch element... from the matrix itself...

            int el = v[mid/n][mid%n];  
            

            if (el == target) return true;
            
            else if (el < target) lo = mid +1;
            else hi = mid - 1;
        }
        
        return false;  
    }
};