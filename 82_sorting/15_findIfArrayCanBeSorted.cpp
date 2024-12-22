#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSetBits(int n){
        int count = 0;
        while (n != 0){
            n = n & (n - 1);
            count++;
        }
        return count;
    }

    bool canSortArray(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n - 1; i++) {
            bool flag = true;  // Assume the array is sorted
            for (int j = 0; j < n - 1 - i; j++) { // Bubble sort with early stopping
                if (v[j] > v[j + 1] && countSetBits(v[j]) == countSetBits(v[j + 1])) {
                    swap(v[j], v[j + 1]);
                    flag = false; // Indicates a swap happened
                }
            }
            if (flag) {  // No swaps, array should be sorted
                break;
            }
        }

        // Check if array is sorted to tackle the case of : It can be shown that it is not possible to sort the input array using any number of operations.
        
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                return false;  // Return false if array is not sorted
            }
        }
        return true;  // Array is sorted
    }
};
