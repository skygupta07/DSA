#include <bits/stdc++.h>
using namespace std;

/*

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return the maximum number of points that lie on the same straight line.


Example 1:

Input: points = [[1,1],[2,2],[3,3]]
Output: 3


Example 2:

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

*/



class Solution {
public:
    int maxPoints(vector <vector<int>> &points) {

        int n = points.size();
        if (n <= 2) return n;

        int maxi = 2; // At least two points are needed to form a line
        
        for (int i = 0; i < n; i++) {

            int x1 = points[i][0];
            int y1 = points[i][1];
            
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int count = 2; // Points i and j are on the line
                
                for (int k = 0; k < n; k++) {
                    // same points nahi hone chahiye...
                    if (k != i && k != j) {
                        int xk = points[k][0];
                        int yk = points[k][1];

                        // Check if the slope between points (i, j) matches (i, k)
                        if ((y2 - y1) * (x1 - xk) == (y1 - yk) * (x2 - x1)) {
                            count++;
                        }
                    }
                }

                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};
