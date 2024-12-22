/*
Given an array nums of distinct integers, 
return all the possible permutations. 
You can return the answer in any order


class Solution {
public:

    void recurPermute(int idx , vector <int> &nums, vector <vector <int> > &result){
        if (idx == nums.size()){
            result.push_back(nums);
            return;
        }

        for (int i=idx; i<nums.size(); i++){
            swap(nums[idx] , nums[i]);
            recurPermute(idx+1 , nums, result);
            swap( nums[idx] , nums[i]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        recurPermute( 0, nums, result );
        return result;
        
    }
};


/*
without using any extra map or extra space 

nums[idx] ko swap karna hai ek ek karke sabke saath.....

*/


