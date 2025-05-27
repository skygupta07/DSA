// countServersThatCommunicate.cpp

/*

You are given a map of a server center, 
represented as a m * n integer matrix grid, 
where 1 means that on that cell there is a server and 0 means that it is no server. 
Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server. 

Example 1:

Input: grid = [[1,0],
              [0,1]]
Output: 0
Explanation: No servers can communicate with others.


Example 2:

Input: grid = [[1,0], 
              [1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.


Example 3:

Input: grid = [[1,1,0,0],
              [0,0,1,0],
              [0,0,1,0],
              [0,0,0,1]]

Output: 4
Explanation: The two servers in the first row can communicate with each other. 
The two servers in the third column can communicate with each other. 
The server at right bottom corner can't communicate with any other server.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Vectors to store the count of servers in each row and column
        vector<int> rowServerCount(m, 0);
        vector<int> colServerCount(n, 0);

        // Count the number of servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    rowServerCount[i]++;
                    colServerCount[j]++;
                }
            }
        }

        int count = 0;

        // Count servers that can communicate
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    
                    // A server can communicate if there is another server in its row or column
                    if (rowServerCount[i] > 1 || colServerCount[j] > 1) {
                        count++;
                    }
                }

            }
        }

        return count;
    }
};
