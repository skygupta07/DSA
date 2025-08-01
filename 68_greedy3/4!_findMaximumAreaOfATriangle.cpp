// findMaximumAreaOfATriangle.cpp


/*

You are given a 2D array coords of size n x 2, 
representing the coordinates of n points in an infinite Cartesian plane.

Find twice the maximum area of a triangle with its corners at any three elements from coords, 
such that at least one side of this triangle is parallel to the x-axis or y-axis. 
Formally, if the maximum area of such a triangle is A, return 2 * A.

If no such triangle exists, return -1.

Note that a triangle cannot have zero area.
 

Example 1:

Input: coords = [[1,1],[1,2],[3,2],[3,3]]
Output: 2

Explanation:
The triangle shown in the image has a base 1 and height 2. 
Hence its area is 1/2 * base * height = 1.


Example 2:

Input: coords = [[1,1],[2,2],[3,3]]

Output: -1

Explanation:
The only possible triangle has corners (1, 1), (2, 2), and (3, 3). 
None of its sides are parallel to the x-axis or the y-axis.

 

Constraints:

1 <= n == coords.length <= 1e5
1 <= coords[i][0], coords[i][1] <= 1e6
All coords[i] are unique.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long maxArea(vector<vector<int>> &coords) {

        // sameY[y] -> saare x-values jinke sath y common hai (i.e., same horizontal line par points)
        unordered_map<int, vector<int>> sameY;

        // sameX[x] -> saare y-values jinke sath x common hai (i.e., same vertical line par points)
        unordered_map<int, vector<int>> sameX;

        // xToY[x] -> har x ke corresponding set of y-values store kar rahe (to check if point (x,y) exists)
        unordered_map<int, unordered_set<int>> xToY;

        // yToX[y] -> har y ke corresponding set of x-values store kar rahe (for same reason as above)
        unordered_map<int, unordered_set<int>> yToX;

        // Step 1: Sare points ko upar ke data structures mein store karo
        for (const auto &pt : coords) {
            int x = pt[0];
            int y = pt[1];

            sameY[y].push_back(x);   // Same y-line par kaunse x hain
            sameX[x].push_back(y);   // Same x-line par kaunse y hain

            xToY[x].insert(y);       // Point existence check ke liye use hoga
            yToX[y].insert(x);
        }

        long long maxArea = 0; // Final answer: twice the area of max triangle

        // Step 2: Horizontal base wale triangles find karo
        // i.e., base lies on same y, points (x1, y), (x2, y)
        for (const auto &[y, xList] : sameY) {

            if (xList.size() < 2) continue;  // Kam se kam 2 x hone chahiye same y par to form base

            // Base = x difference between leftmost and rightmost point
            int minX = *min_element(xList.begin(), xList.end());
            int maxX = *max_element(xList.begin(), xList.end());

            int base = maxX - minX;

            // Triangle banane ke liye ek third point chahiye with same x as base point, 
            // but different y (i.e., vertical height)
            
            // Try both base ends: minX and maxX
            for (int xEnd : {minX, maxX}) {

                for (int y2 : xToY[xEnd]) {  // Check all y-coordinates jahan xEnd point hai

                    if (y2 != y) { // Same y par point ho to triangle nahi banega
                        int height = abs(y2 - y);

                        // Area = (1/2) * base * height
                        // But humein 2*A return karna hai, so base*height directly store karo
                        maxArea = max(maxArea, 1LL * base * height);
                    }

                }

            }
        }

        // Step 3: Vertical base wale triangles find karo
        // i.e., base lies on same x, points (x, y1), (x, y2)
        for (const auto &[x, yList] : sameX) {

            if (yList.size() < 2) continue;  // At least 2 y's required on same x

            // Base = y difference
            int minY = *min_element(yList.begin(), yList.end());
            int maxY = *max_element(yList.begin(), yList.end());
            int base = maxY - minY;

            // Try both base ends: minY and maxY
            for (int yEnd : {minY, maxY}) {

                for (int x2 : yToX[yEnd]) {  // Check all x where yEnd point exists

                    if (x2 != x) { // Ensure third point isn't collinear
                        int height = abs(x2 - x);

                        maxArea = max(maxArea, 1LL * base * height);
                    }

                }

            }

        }

        // Step 4: Return 2 * area if possible else -1
        return (maxArea > 0) ? maxArea : -1;
    }
};
