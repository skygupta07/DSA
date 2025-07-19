// rowWithMaximumOne.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count 
of ones, and the number of ones in that row.

In case there are multiple rows that have the maximum count of ones, 
the row with the smallest row number should be selected.

Return an array containing the index of the row, and the number of ones in it.


Example 1:

Input: mat = [[0,1],[1,0]]
Output: [0,1]
Explanation: Both rows have the same number of 1's. 
So we return the index of the smaller row, 0, and the maximum count of ones (1). 
So, the answer is [0,1]. 


Example 2:

Input: mat = [[0,0,0],[0,1,1]]
Output: [1,2]
Explanation: The row indexed 1 has the maximum count of ones (2). 
So we return its index, 1, and the count. So, the answer is [1,2].


Example 3:

Input: mat = [[0,0],[1,1],[0,0]]
Output: [1,2]
Explanation: The row indexed 1 has the maximum count of ones (2). 
So the answer is [1,2].
 

Constraints:

m == mat.length 
n == mat[i].length 
1 <= m, n <= 100 
mat[i][j] is either 0 or 1.


*/


class Solution {
public:

    vector <int> rowAndMaximumOnes(vector<vector<int>> &mat) {
        int maxOneCount = 0;
        int maxIdx = 0;

        for (int i = 0; i < mat.size(); i++) {
            // Accumulate ka third parameter initial sum hota hai. Yahi bhoolte ho tum 😄
            int oneCount = accumulate(mat[i].begin(), mat[i].end(), 0);

            // Agar current row me jyada 1s hain, to update max values
            if (oneCount > maxOneCount) {
                maxOneCount = oneCount;
                maxIdx = i;
            }
        }

        return {maxIdx, maxOneCount};
    }
};


/*

TC = O(m * n)  
// because accumulate runs for n elements in each of m rows

SC = O(1)  
// No extra space used (ignoring output vector of size 2)

*/



class Solution {
public:
    // Helper function: binary search to find first occurrence of 1
    int countOnes(vector<int> &row) {
        int lo = 0;
        int hi = row.size() - 1;

        int firstOneIdx = row.size();  // default: if no 1 found, count will be 0

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (row[mid] == 1) {
                firstOneIdx = mid;  // possible candidate
                hi = mid - 1;       // search further left
            } 
            else {
                lo = mid + 1;
            }
        }

        return row.size() - firstOneIdx;  // number of 1s
    }

    vector <int> rowAndMaximumOnes(vector<vector<int>> &mat) {
        int maxOneCount = 0;
        int maxIdx = 0;

        for (int i = 0; i < mat.size(); i++) {
            int oneCount = countOnes(mat[i]);

            if (oneCount > maxOneCount) {
                maxOneCount = oneCount;
                maxIdx = i;
            }
        }

        return {maxIdx, maxOneCount};
    }
};



/*

O(m log n)

O(1) extra (excluding output)

*/