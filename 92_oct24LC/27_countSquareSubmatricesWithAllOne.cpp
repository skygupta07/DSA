#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector <vector <int>> dp(m, vector <int> (n, 0));

        // base case fill first row and first column as it is


        int count = 0;

        // first row fill => column will vary..
        for (int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
            count += dp[0][j];
        }

        // first col    
        for (int i=1; i<m; i++){    // 0, 0 upar include ho chuka h to phir thoda dhyan se..yaha
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }

        // now wo first row first col ke chod ke remaining dp ko bharo... 

        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){

                if (matrix[i][j] == 1){ // yahi to dekhna tha..
                     dp[i][j] = 1 + min( {dp[i][j-1], dp[i-1][j], dp[i-1][j-1]} );
                }
                count += dp[i][j];
            }
        }

        return count;
    }
};