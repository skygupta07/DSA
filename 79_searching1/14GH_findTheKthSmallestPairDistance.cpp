// findTheKthSmallestPairDistance.cpp

/*

The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance 
among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.


Example 1:

Input: nums = [1,3,1], k = 1
Output: 0

Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.


Example 2:

Input: nums = [1,1,1], k = 2
Output: 0


Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 

Constraints:

n == nums.length
2 <= n <= 1e4
0 <= nums[i] <= 1e6
1 <= k <= n * (n - 1) / 2

*/




#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int helper(vector <int> &nums, int diff){
        int count = 0;

        int j = 0;
        int n = nums.size();

        for (int i=0; i<n; i++){
            while (j<n && nums[j] - nums[i] <= diff) j++;
            count += j-i-1;
        }

        return count; 
    }



    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        // binary search on difference
        int lo = 0;
        int hi = nums[n-1] - nums[0];

        int ans = 0;

        while (lo <= hi){
            int mid = lo + (hi - lo)/2;

            // number of pairs that are smaller than mid difference..
            int count = helper(nums, mid);

            if (count >= k){
                ans = mid;
                hi = mid-1;
            }

            else{
                lo = mid + 1;
            }
        }
        return ans;
    }

};


// mehtod 2 

class Solution {
public:
    int helper(vector<int>&nums,int k,int diff){

        int count = 0;
        int j = 0;
        int n = nums.size();

        // har element ko pick karke uska uske aage waale elements ke saath difference calculate karenge and find karenge kitne elements esse hai jinka difference less than current difference(mid) hai
        for(int i=0;i<n;i++){

            // jab tak difference less hoga tab tak aage badhenge
            while(j<n && (nums[j]-nums[i])<=diff){
                j++;
            }

            // number of elements = number of pairs = start index - ending index - 1
            count += (j-i-1);
        }
        return count;
    }


    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Kyunki humne sort kardiya hai toh difference ki range 0 to (max-min) tak hi jaayegi
        int lo = 0;
        int hi = nums[n-1] - nums[0];

        int ans = -1;

        // hum har baar binary search ki help se ek difference {or kind of distance here} nikalenge 
        // and ye dekhenge ki kitne pairs 
        // jinka difference less than equal to hai iss current difference ke
        while(lo <= hi){

            int mid = lo + (hi-lo)/2;

            int count = helper(nums, k, mid);
            // agar number of pairs jinka difference less than current difference hai 
            // woh greater than equal to k hai toh {pehle jeb mai iss answer ko rakh lenge
            //  then better option ki talaash..} hume apne current difference ko aur kum karne
            //  ki try karenge left side move karke
            
            if(count >= k){
                ans = mid;
                hi = mid-1;
            }

            // agar number of pairs jinka difference less than current difference hai woh less than k hai
            //  toh hume apne current difference ko aur increase karne ki try karenge right side move karke
            
            else{
                lo = mid + 1;
            }

        }

        return ans;
    }
};

