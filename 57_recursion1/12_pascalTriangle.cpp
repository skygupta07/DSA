#include <bits/stdc++.h>
using namespace std;


/*

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]


Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:
1 <= numRows <= 30

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // recursion -> base case kaam fn call
        if (numRows == 1) return {{1}};
        
         // fn call pehle likh diya taaki reverse mai aata huye phir kaam ho...
        vector<vector<int>> prevRows = generate(numRows-1);    
        
        vector <int> newRow(numRows, 1);    // sabko hi 1 se initialise kiya..but now fill karte time index 1 se start karenge and end se ek kam tak jayenge...
        
        for (int i=1; i<numRows-1; i++){
            newRow[i] = prevRows.back()[i-1] + prevRows.back()[i];
        }

        prevRows.push_back(newRow);
        return prevRows;
    }
};