// smallestMissingPositiveNumber.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given a sorted array of distinct integers that represents a sequence of numbers, 
but exactly one number is missing from the sequence.

Your task is to find and print the first missing number using Binary Search in O(log n) time.


Constraints:
The array is sorted in ascending order.
Exactly one number from the sequence is missing.

Array size n ≥ 2.

Example 1:
Input: arr = [0, 1, 2, 3, 6, 7, 8]  
Output: 4
Explanation:
The sequence should be 0,1,2,3,4,5,6,7,8, but 4 is missing.


Example 2:
Input: arr = [5, 6, 7, 9, 10, 11]  
Output: 8
Explanation:
The sequence should be continuous, but 8 is missing.


Example 3:
Input: arr = [10, 11, 12, 13, 15]  
Output: 14


👉 Expected solution approach:
Use binary search to compare arr[mid] with the expected value (arr[0] + mid).
If they don’t match, the missing number lies in the left half; otherwise, in the right half.


*/


int main(){
    
    int arr[] = {0,1,2,3,6,7,8};    // given sorted arr
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=1; i<n; i++){
        if (arr[i] == arr[i-1] + 1) continue;

        else{
            cout<<arr[i-1]+1 <<endl;
            break;
        }
    }
    
}


