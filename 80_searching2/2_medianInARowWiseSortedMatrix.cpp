#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        vector <int> v;
        
        for (int i=0; i<mat.size(); i++){
            for (int j=0; j<mat[0].size(); j++){
                v.push_back(mat[i][j]);
            }
        }
        
        sort(v.begin(), v.end());
        
        // yes it handles both odd and even size vector cases
        return v[v.size()/2];
    }
};


/*
Given a row-wise sorted matrix where the number of rows and columns is always odd,
find the median of the matrix.
*/


// ---- using binary search ---------


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the upper bound for a given `x` in a sorted array `arr`.
    // It returns the index of the smallest element greater than `x`.
    int upperBound(vector<int> &arr, int x, int c) {
        int lo = 0;
        int hi = c - 1;

        int ans = c; // Initialize ans to c (out-of-bounds index).

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] > x) {
                ans = mid; // Update ans and move to the left half.
                hi = mid - 1;
            } else {
                lo = mid + 1; // Move to the right half.
            }
        }

        return ans;
    }

    // Function to count the number of elements <= `mid` in the matrix.
    int countSmallEqual(vector<vector<int>> &mat, int mid, int r, int c) {
        int count = 0;

        // Traverse each row and find the upper bound for `mid` in that row.
        for (int i = 0; i < r; i++) {
            count += upperBound(mat[i], mid, c);
        }

        return count;
    }

    // Function to find the median of a row-wise sorted matrix.
    int median(vector<vector<int>> &mat) {
        int r = mat.size();    // Number of rows
        int c = mat[0].size(); // Number of columns

        // Find the minimum and maximum values in the matrix.
        // Since the matrix is row-wise sorted, minimum is in the first column 
        // and maximum is in the last column.
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < r; i++) {
            mini = min(mini, mat[i][0]);
            maxi = max(maxi, mat[i][c - 1]);
        }

        // Now, we perform binary search between `mini` and `maxi` to find the median.
        // The median condition is that the number of elements <= `mid` should be 
        // equal to `totalNumberOfElements / 2`.

        int req = (r * c) / 2; // Number of elements that should be <= the median.

        int lo = mini;
        int hi = maxi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int smallEqual = countSmallEqual(mat, mid, r, c);

            // If elements <= mid are less than or equal to `req`, move to the right half.
            if (smallEqual <= req) {
                lo = mid + 1;
            } else {
                hi = mid - 1; // Otherwise, move to the left half.
            }
        }

        return lo; // `lo` will point to the median.
    }
};
