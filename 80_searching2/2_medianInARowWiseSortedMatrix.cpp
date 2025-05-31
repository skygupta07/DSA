#include <bits/stdc++.h>
using namespace std;


/*

Given a row-wise sorted matrix where the number of rows and columns is always odd, 
find the median of the matrix.

Examples:

Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 


Input: mat = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives us {1,2,3}. Hence, 2 is median


Input: mat = [[3], [5], [8]]
Output: 5
Explanation: Sorting matrix elements gives us {3,5,8}. Hence, 5 is median.


Constraints:
1 <= mat.size(), mat[0].size() <= 400
1 <= mat[i][j] <= 2000

*/

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
    int upperBound(vector <int> &arr, int x, int c) { // c for column
        int lo = 0;
        int hi = c - 1;

        int ans = c; // Initialize ans to c (out-of-bounds index).

        while (lo <= hi){
            int mid = lo + (hi - lo) / 2;

            // upper bound chahiye tha.... accha arr[mid] chalo greater h x se sahi h jyada h...
            // magar mujhe just greater hi chahiye tha... chal theek h iss value ko to as a answer 
            // sambhal ke rakh leta hu... and uper bound chahiye tha to chal theek h issey thoda aur chota 
            // value dundhne ki kosis karta hu jo ki mere x ke ho sakta h aur paas hi ho ...wo jyada badhiya rahega..

            if (arr[mid] > x) {
                ans = mid; // Update ans and move to the left half.
                hi = mid - 1;
            } 
            
            // Move to the right half.
            else lo = mid + 1; 
        }

        return ans;
    }

    // Function to count the number of elements <= `mid` in the matrix.
    int countSmallEqual(vector <vector <int>> &mat, int mid, int r, int c) {
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

        //  chalo phir column mai search karte h ... matlab row vary karega...

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
            if (smallEqual <= req) lo = mid + 1;
             
            // Otherwise, move to the left half.
            else hi = mid - 1; 
            
        }

        // `lo` will point to the median.
        return lo; 
    }
};
