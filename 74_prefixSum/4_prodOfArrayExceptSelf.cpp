/*

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> pre(n);
        vector <int> suf(n);
        vector <int> ans(n);    // vector ka tujhe bhaiya size initialise karna hi padega

        // prefix product array except self
        int p = nums[0];
        pre[0] = 1;
        for (int i=1; i<n; i++){
            pre[i] = p;
            p*=nums[i];
        }

        // suffix product array except self
        p = nums[n-1];  // p variable ko kyu cheda? => arey bhai to phir uska karna hi kya hai...
                        // redefine to same variable karoge nahi => directly ched do...
        suf[n-1] = 1;
        for (int i=n-2; i>=0; i--){
            suf[i] = p; // imp
            p*=nums[i];
        }
        
        for (int i=0; i<n; i++){
            ans[i] = pre[i]*suf[i];
        }
        return ans;
    }
};





















*/