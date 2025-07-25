// shortestUnsortedContinuousSubarray.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size(); // Array ka size
        int l = -1, r = -1; // Unsorted subarray ke left aur right boundary track karne ke liye

        // Left boundary find karne ke liye
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) { // Jab current element next se bada ho
                l = i;
                break;
            }
        }

        // Right boundary find karne ke liye
        for (int i = n - 1; i >= 1; i--) {
            if (arr[i] < arr[i - 1]) { // Jab current element previous se chhota ho
                r = i;
                break;
            }
        }

        // Agar l == -1 hai, iska matlab array pehle se sorted hai
        if (l == -1) return 0;

        // Subarray ka minimum aur maximum find karte hain
        int mini = arr[l], maxi = arr[l];
        for (int i = l; i <= r; i++) {
            mini = min(mini, arr[i]); // Subarray ka minimum
            maxi = max(maxi, arr[i]); // Subarray ka maximum
        }

        // Left boundary ko adjust karo to include elements jo `mini` se chhote hain
        l = upper_bound(arr.begin(), arr.begin() + l, mini) - arr.begin();

        // Right boundary ko adjust karo to include elements jo `maxi` se bade hain
        r = lower_bound(arr.begin() + r + 1, arr.end(), maxi) - arr.begin();

        // Return length of unsorted subarray
        return r - l;
    }
};


/*
It finds the first position in a sorted range where an element is strictly greater than the given value.
After finding the first position greater than mini using upper_bound, we subtract arr.begin() to convert the iterator returned by upper_bound into an index

*/