#include <bits/stdc++.h> 
using namespace std;

// Function to find the length of the longest subarray which has
// the maximum possible bitwise AND value
void maxAndVal(int *arr, int n) {
    int ans = 0;      // Stores the final answer (max subarray length)
    int maxi = INT_MIN;  // Stores the maximum element in the array
    int count = 0;    // Tracks the count of consecutive max elements

    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxi) {
            // Found a new maximum, update maxi and reset count to one
            maxi = arr[i];
            count = 1;
        }
        else if (arr[i] == maxi) {
            // If same as current maximum, increase count
            count++;
        }
        else {
            // If a smaller number appears, reset count to zero
            count = 0;
        }

        // Always update the answer with the maximum count found
        ans = max(ans, count);
    }

    // Print the final answer: length of longest contiguous subarray of max elements
    cout << ans << "\n";
}

int main() {
    int arr[] = {1, 2, 1, 3, 2, 5, 5, 9, 8, 8}; // Given array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of the array
    maxAndVal(arr, n); // Call function
    return 0; 
}

/*
Logic Explanation:

1. The problem is to find the longest subarray where the bitwise AND is maximum.
2. Maximum possible AND value will be achieved when all elements in that subarray are equal to the maximum element of the array.
3. If we take AND of different numbers, the result will always be smaller than the max element itself.
4. So, the problem reduces to finding the longest contiguous subarray of the maximum element.
5. The algorithm:
   - Traverse the array to find the max element.
   - Track its longest contiguous occurrence.
   - Return the length of that longest sequence.

Time Complexity: O(n) (since we traverse the array once).
Space Complexity: O(1) (only a few integer variables are used).
*/
