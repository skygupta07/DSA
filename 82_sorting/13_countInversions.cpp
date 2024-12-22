#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int count = 0;
        
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                if (arr[j] < arr[i]) count++;
            }
        }
        
        return count;
    }
};


// 

class Solution {
  public:
    // Function to count inversions in the array using merge sort.
    int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        int count = 0;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays
        vector<int> leftArr(n1), rightArr(n2);
        for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
        for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

        // Merge the arrays and count inversions
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                count += (n1 - i); // Count inversions
            }
        }

        // Copy remaining elements
        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];

        return count;
    }

    int mergeSortAndCount(vector<int>& arr, int left, int right) {
        int count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Count inversions in left and right halves
            count += mergeSortAndCount(arr, left, mid);
            count += mergeSortAndCount(arr, mid + 1, right);

            // Count inversions during merge
            count += mergeAndCount(arr, left, mid, right);
        }
        return count;
    }

    int inversionCount(vector<int>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};
