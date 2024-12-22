#include <bits/stdc++.h>
using namespace std;

class Solution { // stack + mp
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();  
        int n2 = nums2.size();  

        vector<int> ans(n1, -1);  
        
        stack<int> st;            // Stack to store elements of nums2 temporarily
        unordered_map<int, int> mp;  // Map to store the Next Greater Element (NGE) for each element in nums2

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