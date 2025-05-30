// nextGreaterElement2.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution { // bruteforce
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> nge(n, -1);

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (nums[(i+j) % n] > nums[i]){
                    nge[i] = nums[(i+j) % n];
                    break;
                }
            }
        }

        return nge;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);  // Initialize result array with -1
        stack<int> st;  // Monotonic decreasing stack (stores indices)

        // Traverse the array twice to simulate circular behavior
        for (int i = 2 * n - 1; i >= 0; i--) {
            // Pop elements from stack that are smaller or equal to current element
            while (!st.empty() && nums[st.top()] <= nums[i % n]) {
                st.pop();
            }
            // Assign the next greater element if stack is not empty
            if (!st.empty()) {
                nge[i % n] = nums[st.top()];
            }
            // Push current index into stack
            st.push(i % n);
        }

        return nge;
    }
};
