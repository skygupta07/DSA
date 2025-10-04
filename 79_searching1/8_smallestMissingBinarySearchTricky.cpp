// smallestMissingPositiveNumber_BinarySearch.cpp

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
    // Given a sorted array where we assume arr[i] == i for each index `i`, 
    // but due to an issue one element is missing, and elements after that are shifted.
    
    int arr[] = {0,1,2,3,4,5,9}; // Here, ideally arr[6] should be 6 but it's 9. 
    // So from index 6 onward, the pattern breaks.
    
    int n = sizeof(arr)/sizeof(arr[0]); // Size of the array

    int lo = 0;
    int hi = n - 1;

    int ans = -1; // Default answer if no mismatch is found (i.e., all arr[i] == i)

    // Perform binary search to find the first index where arr[i] != i
    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;  // Avoid overflow compared to (lo + hi) / 2

        if (arr[mid] == mid){  
            // If the value at current index is same as index (no mismatch yet)
            // This means everything before and including `mid` is correct
            // So, look in the right half for the first mismatch
            lo = mid + 1;
        } 
        else {
            // If value is not equal to index, we found a potential answer
            // But we want the *first* such index where this happens
            // So, store this index and keep looking in the left half
            ans = mid; //kyuki mere ko aur smaller value chahiye isliye yaha par answer store kar raha hu..
            // and aur acche option ko search kar raha hu....
            hi = mid - 1;
        }
    }

    // Final answer: First index where arr[i] != i (i.e., first "missing" index)
    cout << ans << endl;
}





#include <iostream>
using namespace std;

int main(){

    int arr[] = {0,1,2,3,4,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int lo = 0;
    int hi = n-1;

    int ans = -1;   // in case if not present 

    while (lo <= hi){
        int mid = lo + (hi-lo)/2;

        if (arr[mid] == mid){   // agar mid index wala element apne sahi index pe ho
            //  to..pehle ki bhi sahi hi honge.. aage badhte jao...
            lo = mid+1;
        } 
        else{
            ans = mid;  // yes update the answer each time...
            hi = mid-1; // ab aage jaane ki jarurat nahi culprits ko peeche hi search karo..
        }

    }
    
    cout<<ans<<endl;

}