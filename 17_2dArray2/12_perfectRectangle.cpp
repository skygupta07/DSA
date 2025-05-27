// perfectRectangle.cpp

#include <bits/stdc++.h>
using namespace std;

/*


Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] 
represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) 
and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.

 
Example 1:


Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.


Example 2:


Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
Output: false
Explanation: Because there is a gap between the two rectangular regions.


Example 3:

Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
Output: false
Explanation: Because two of the rectangles overlap with each other.
 

Constraints:

1 <= rectangles.length <= 2 * 104
rectangles[i].length == 4
-105 <= xi < ai <= 105
-105 <= yi < bi <= 105


*/


class Solution {
public:

     bool isRectangleCover(vector<vector<int>>& rectangles) {
       int n = rectangles.size();
   
       if (n == 1) return true;
   
       // maps all points to a respective calculation. If it is a valid rectangle,
       // all interior points should have count 0, bootom left most and top right
       // most point should have value 1, and top left and bottom right should have
       // count -1. If it is different than this, it is not a perfect rectangle.

       map <pair <int, int>, int> pointCounts; 
       // key bhai combination wali bhi to hoti h .. matlab do tarah ka pin combine karke 
       // ek final pin banaya....


      // a,b     and    x,y 
      //  A(x, b), B(a, b), 
      //  D(x, y), C(a, y),
   
       for (auto& rect : rectangles) {
         pointCounts[{rect[0], rect[1]}]++;  // (x, y) - bottom left
         pointCounts[{rect[2], rect[3]}]++;  // (a, b) - top right
         pointCounts[{rect[0], rect[3]}]--;  // (x, b) - top left
         pointCounts[{rect[2], rect[1]}]--;  // (a, y) - bottom right
       }
   
       int numMarks = 0;
   
       for (auto it = pointCounts.begin(); it != pointCounts.end(); it++) {
         
        if (it->second != 0) {
   
           // this condition is added because in not perfect 
           // rectangles, overlapping corners will cause the absolute
           // value of that corner to go beyond 1

           if (abs(it->second) != 1) return false;
   
           numMarks++;
         }
       }
   
       return numMarks == 4;
     }
   };


   class Solution {
    public:
        bool isRectangleCover(vector<vector<int>>& rectangles) {
            int n = rectangles.size();
    
            // If there's only one rectangle, it trivially forms a perfect rectangle
            if (n == 1) return true;
    
            // Map to track the frequency of each corner point
            map <pair<int, int>, int> pointCounts;
    
            // Process each rectangle in the input list
            for (auto &rect : rectangles) {
                // Increment count for bottom-left (x1, y1) and top-right (x2, y2)
                pointCounts[{rect[0], rect[1]}]++;  // Bottom-left corner
                pointCounts[{rect[2], rect[3]}]++;  // Top-right corner
    
                // Decrement count for top-left (x1, y2) and bottom-right (x2, y1)
                pointCounts[{rect[0], rect[3]}]--;  // Top-left corner
                pointCounts[{rect[2], rect[1]}]--;  // Bottom-right corner
            }
    
            int numMarks = 0;  // Count the number of unique corner points
    
            // Iterate through the point map to check the frequency of each point
            for (auto it = pointCounts.begin(); it != pointCounts.end(); it++) {
              // If the point is not neutralized
              if (it->second != 0) { 
                    if (abs(it->second) != 1) return false;  // If count is not ±1, invalid case
                   
                    numMarks++;  // Count unique corner points
                }
            }
    
            // A perfect rectangle should have exactly 4 unique corner points
            return numMarks == 4;
        }
    };
    