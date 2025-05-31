#include <bits/stdc++.h>
using namespace std;

/*
Our friend John has given us an array consisting of N integers. In each question John has given Bob a value X, to find an element Ai in the array which is either greater than or equal to X and such that the difference between Ai and X is as small as possible.

John will ask Bob Q such questions, and we need to help Bob answer them.
*/


// Binary search function to find the first element >= target
int binary_search(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = -1; // Default result if no element >= target is found

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow
        if (arr[mid] >= target) {
            result = arr[mid];  // Update result
            high = mid - 1;     // Continue to search in the left half
        } else {
            low = mid + 1;      // Search in the right half
        }
    }

    return result;
}
