#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector <int> &histo){
        stack <int> st;
        int maxA = 0;
        int n = histo.size();

        for (int i=0; i<=n; i++){
            while (!st.empty() && (i==n || histo[st.top()] >= histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width;

                if (st.empty()){
                    width = i;
                }
                else width = i - st.top() -1;
                
                maxA = max(maxA, width*height);
            }
            st.push(i);
        }
        return maxA;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int n = matrix.size();  // row
        int m = matrix[0].size(); // column
        vector <int> height(m, 0);

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            int area = largestRectangleArea(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};


// prerequisite -> largest rectangle in histogram ka function....
/*
In each iteration adding up the each iteration of each row -> if corresponding cell value is 1-> then add it...
while if the currently added cell value is zero then reset the rectangle height to zero...

*/