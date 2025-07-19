// countOnesInBinaryArray.cpp


/*

You are given a binary array that is sorted in non-increasing order, 
meaning all the 1's appear before the 0's. Find the total number of 1's present in the array.

Examples:

Input: arr[] = [1, 1, 1, 1, 1, 0, 0, 0]
Output: 5
Explaination: Count of 1's in the array is 5.


Input: arr[] = [1, 1, 1, 1, 1, 1, 1]
Output: 7
Explaination: Count of 1's in the array is 7.


Constraints:
1 ≤ arr.size() ≤ 1e5 
0 ≤ arr[i] ≤ 1

*/

#include <bits/stdc++.h>
using namespace std;

int countOne(int *arr, int n) {
    if (n == 0) return 0;

    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == 1) {    
        // agar OR mai first condition true hogayi to.. next condition check hi nahi hoti 
        // isliye ye sahi trick hai ki OR mai aap pehle index out of bound wali condition check kar liya karo...
            if (mid == 0 || arr[mid - 1] == 0) {
                // Found the first occurrence of 1
                return n - mid;   // (n-1 - mid + 1 ==== n-mid) to simply count the number of ones
            }
            hi = mid - 1;
        } 
        else {
            lo = mid + 1;
        }
    }

    // If no 1 is found in the array
    return 0;

}

int main() {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int ans = countOne(arr, n);
    cout << ans << endl;
}

