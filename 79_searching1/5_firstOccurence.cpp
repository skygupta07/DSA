// firstOccurence.cpp


/*

You are given a sorted array (which may contain duplicate elements) and a target value x. 
Write a program in C++ to find the first occurrence (index) of x in the array using Binary Search.

If x is not present, print "Element not found in array.".
The solution should run in O(log n) time complexity.

Example 1:
Input: arr = [1, 2, 2, 2, 3, 3, 3, 5, 5, 8, 9], x = 3
Output: First occurrence of 3 is at index: 4

Example 2:
Input: arr = [1, 2, 4, 6, 7, 8], x = 5
Output: Element not found in array.


*/


#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 2, 2, 2, 3, 3, 3, 5, 5, 5, 5, 8, 8, 9};

    int n = sizeof(arr) / sizeof(arr[0]);  // Size of the array

    int x = 3; // Target element to search
    
    int lo = 0;
    int hi = n - 1;

    int ans = -1;  // Default answer if not found

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;  // Overflow-safe formula

        if (arr[mid] == x) {
            // 🟢 Mil gaya x, but we don't stop here
            // Check if it's the first occurrence
            if (mid == 0 || arr[mid - 1] != x) {
                ans = mid;  // This is the first occurrence
                break;
            }
            else {
                // Go left side if earlier occurrence might be there
                hi = mid - 1;
            }
        }
        else if (arr[mid] < x) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    if (ans != -1) cout << "First occurrence of " << x << " is at index: " << ans << endl;
    
    else cout << "Element not found in array." << endl;

    return 0;
}
