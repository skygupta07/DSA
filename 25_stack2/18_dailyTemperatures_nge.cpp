#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        // Create a vector `nge` to store the result (Next Greater Element), initialized to 0.
        vector<int> nge(n, 0);
       
        // Stack to store indices of temperatures that are waiting for their next greater element.
        stack<int> st;

        // Traverse the temperature array.
        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current temperature is greater than the temperature
            // at the index stored at the top of the stack:
            while (!st.empty() && arr[st.top()] < arr[i]) {
                // Calculate the difference in indices and update the `nge` vector.
                nge[st.top()] = i - st.top();
                // Remove the resolved index from the stack.
                st.pop();
            }
            // Push the current index into the stack for future comparison.
            st.push(i);
        }

        // Return the result vector, which contains the number of days to wait for a warmer day.
        return nge;
    }
};
