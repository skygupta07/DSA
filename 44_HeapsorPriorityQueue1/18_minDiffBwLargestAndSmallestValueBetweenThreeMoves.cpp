#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minDiff(vector <int> nums){
        int n = nums.size();
        return min({nums[n-1] - nums[3] , nums[n-2] - nums[2], nums[n-3] - nums[1], nums[n-4] - nums[0]});
    }


    int minDiffViaPq(vector <int> nums){
        priority_queue <int> mxheap;    //maxheap
        priority_queue < int, vector <int> , greater <int> > mnheap;

        for (auto el : nums){
            mxheap.push(el);
            mnheap.push(el);

            if (mxheap.size() > 4) mxheap.pop();
            if (mnheap.size() > 4) mnheap.pop();
        }

        int l = 3 , r = nums.size() - 4;

        while (!mxheap.empty()){
            nums[l--] = mxheap.top();
            mxheap.pop();

            nums[r++] = mnheap.top();
            mnheap.pop();
        }

        return minDiff(nums);
    }



    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4 ) return 0;
        return minDiffViaPq(nums);
    }
};







// ------------------m2-----



class Solution {
public:

    int minDiff(vector <int> nums){
        int n = nums.size();
        return min({nums[n-1] - nums[3] , nums[n-2] - nums[2], nums[n-3] - nums[1], nums[n-4] - nums[0]});
    }


    int minDiffViaPq(vector <int> nums){
        priority_queue <int> mxheap;    //maxheap
        priority_queue < int, vector <int> , greater <int> > mnheap;

        for (auto el : nums){
            mxheap.push(el);
            mnheap.push(el);

            if (mxheap.size() > 4) mxheap.pop();
            if (mnheap.size() > 4) mnheap.pop();
        }

        int l = 3 , r = nums.size() - 4;

        while (!mxheap.empty()){
            nums[l--] = mxheap.top();
            mxheap.pop();

            nums[r++] = mnheap.top();
            mnheap.pop();
        }

        return minDiff(nums);
    }



    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4 ) return 0;
        return minDiffViaPq(nums);
    }
};