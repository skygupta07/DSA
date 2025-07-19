// firstOccurence.cpp

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
