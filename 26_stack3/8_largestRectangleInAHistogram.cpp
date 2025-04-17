#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers heights representing the histogram's bar height 
where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/


class Solution {
public:

    vector <int> prevSmallerElement(vector <int> &heights, int n){
        stack <int> st; // stores index

        vector <int> prevSmaller(n);

        for (int i=0; i<n; i++){
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prevSmaller;
    }

    vector <int> nextSmallerElement(vector <int> &heights, int n){
        stack <int> st; // stores index

        vector <int> nextSmaller(n);

        // ha next smaller ke liye peeche se loop chalta h...
        for (int i=n-1; i>=0; i--){
            // chahiye to still next smaller hi to inequality to same hi rahegi...
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nextSmaller;
    }



    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector <int> prevSmaller = prevSmallerElement(heights, n);
        vector <int> nextSmaller = nextSmallerElement(heights, n);

        int maxArea = 0;

        for (int i=0; i<n; i++){
            // yes (j - i + 1) -> (ns[i] - ps[i] - 1)
            int area = (nextSmaller[i] - prevSmaller[i] - 1) * heights[i]; 
            maxArea = max(maxArea , area);
        }

        return maxArea;
    }
};