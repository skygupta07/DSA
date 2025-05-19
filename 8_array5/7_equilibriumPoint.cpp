#include <bits/stdc++.h>
using namespace std;


/*

Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that the
sum of all elements before that index is the same as the sum of elements after it. 
Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2 
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.


Input: arr[] = [1, 1, 1, 1]
Output: -1
Explanation: There is no equilibrium index in the array.
Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.



*/

int main() {
    return 0;
}


class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector <int> &arr) {
        // code here
        
        int left_sum = 0;
        int right_sum = 0;
        int arr_sum = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            arr_sum = arr_sum + arr[i];
        }
        
        for(int i = 0 ; i < arr.size() ; i++){
            right_sum = arr_sum - left_sum - arr[i];
            if(left_sum == right_sum){
                return i;
            }
            left_sum = left_sum + arr[i];
        }
        return -1;
    }
};