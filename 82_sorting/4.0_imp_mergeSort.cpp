// mergeSort.cpp


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    // Merge two sorted halves arr[lo..mid] and arr[mid+1..hi]
    void merge(vector<int>& arr, int lo, int mid, int hi) {
        
        int n1 = mid - lo + 1;  // size of left half
        int n2 = hi - mid;      // size of right half

        // Temporary arrays to hold the halves
        vector <int> left(n1), right(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) left[i] = arr[lo + i];
        for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];

        // i -> left ka index, j -> right ka index, k -> original array ka index
        int i = 0, j = 0, k = lo;

        // Merge both halves into original array
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) arr[k++] = left[i++];
            else arr[k++] = right[j++];
        }

        // Copy remaining elements of left array (agar bache ho)
        while (i < n1) {
            arr[k++] = left[i++];
        }

        // Copy remaining elements of right array (agar bache ho)
        while (j < n2) {
            arr[k++] = right[j++];
        }
    }

    // Recursive merge sort function
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return; // Base case: single element or invalid range

        int mid = l + (r - l) / 2;

        // Recursively sort left half
        mergeSort(arr, l, mid);

        // Recursively sort right half
        mergeSort(arr, mid + 1, r);

        // Merge sorted halves
        merge(arr, l, mid, r);
    }
};
