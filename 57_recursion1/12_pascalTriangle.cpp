#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // recursion -> base case kaam fn call
        if (numRows == 1) return {{1}};
        
        vector<vector<int>> prevRows = generate(numRows-1);     // fn call pehle likh diya taaki reverse mai aata huye phir kaam ho...

        vector <int> newRow(numRows, 1);    // sabko hi 1 se initialise kiya..but now fill karte time index 1 se start karenge and end se ek kam tak jayenge...
        
        for (int i=1; i<numRows -1; i++){
            newRow[i] = prevRows.back()[i-1] + prevRows.back()[i];
        }

        prevRows.push_back(newRow);
        return prevRows;
    }
};