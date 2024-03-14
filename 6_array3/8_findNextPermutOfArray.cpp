#include <iostream>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int idx = -1;
        // step 1. finding pivot index say idx
        for (int i=n-2; i>=0; i--){
            if (nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        // if i was unable to find the pivot index it means array is already sorted in descending order
        // corner case -> then simply reverse it 
        if (idx == -1){
            reverse(nums.begin(),nums.end());
            return;
        } 

        // step 2 ->reverse part of array after the pivot index...
        reverse(nums.begin()+idx+1, nums.end());   // reverse(nums.begin()+i , j+1) to reverse i se j tak idx

        // step 3. finding the just next greater element's index which is just greater than pivot
        int j = -1;
        for (int i=idx+1; i<n; i++){
            if (nums[i]>nums[idx]){
                j = i;
                break;
            }
        }

        // step 4. swapping idx and j
        int temp = nums[idx];
        nums[idx] = nums[j];
        nums[j] = temp;
        return;

        }

        
    
};

/*
find all permuations then arrange in asc order
then return the next index of matching original array index


*/












int main(){

}



/*
step 1. traversing from the back find the pivot index traverse karte raho aur check karo ki 
just previous waala element bada ho.. jaha ye condition false hogi....wahi pivot index hoga..

step 2. then sort all the elements after the pivot index.

step 3. find the just next greater element than index...

step 4. then swap the pivot index with its just next greater element...







*/