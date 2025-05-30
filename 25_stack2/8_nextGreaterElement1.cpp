// nextGreaterElement1.cpp

/*
The next greater element of some element x in an array is the first greater element
that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] 
and determine the next greater element of nums2[j] in nums2. 
If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] 
is the next greater element as described above.


Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

*/



#include <bits/stdc++.h>
using namespace std;

class Solution { // stack + mp
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();  
        int n2 = nums2.size();  

        vector<int> ans(n1, -1);  
        
        stack<int> st;            // Stack to store elements of nums2 temporarily
        unordered_map <int, int> mp;  // Map to store the Next Greater Element (NGE) for each element in nums2

        // Step 1: Precompute the NGE for each element in nums2
        for (int i = 0; i < nums2.size(); i++) {
            int el = nums2[i];  // Current element of nums2

            // While stack is not empty and current element is greater than stack top
            while (!st.empty() && el > st.top()) {
                mp[st.top()] = el;  // Map the stack top's NGE as the current element
                st.pop();           // Remove the top element
            }

            st.push(el);  // Push the current element onto the stack
        }

        // Step 2: Find the NGE for elements in nums1 using the precomputed map
        for (int i = 0; i < n1; i++) {
            int el = nums1[i];  // Current element of nums1

            if (mp.find(el) != mp.end()) {  // If NGE is precomputed for this element
                int nge = mp[el];           // Get the NGE from the map
                ans[i] = nge;               // Update the result
            }
        }

        return ans;  // Return the result vector
    }
};


class Solution { // brute force
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector <int> ans(n1, -1);

        // go to every element of nums1
        for (int i=0; i<n1; i++){
            int el1 = nums1[i];

            // find this element in nums2

            for (int j=0; j<n2; j++){
                int nge = -1;
                if (nums2[j] == el1){
                    // now find nge for this el1 ..
                    for (int k = j+1; k<n2; k++){
                        if (nums2[k] > el1){
                            nge = nums2[k];
                            ans[i] = nge;
                            break;
                        }
                    }
                }
            }

        }
        return ans;
    }
};