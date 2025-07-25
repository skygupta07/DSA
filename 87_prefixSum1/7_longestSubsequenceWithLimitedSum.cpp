// longestSubsequenceWithLimitedSum.cpp

/*


You are given an integer array nums of length n, and an integer array queries of length m.

Return an array answer of length m where answer[i] is the maximum size of a subsequence 
that you can take from nums such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array 
by deleting some or no elements without changing the order of the remaining elements.
 

Example 1:

Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]

Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. 
It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.

- The subsequence [4,5,1] has a sum less than or equal to 10. 
It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. 
It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.


Example 2:

Input: nums = [2,3,4,5], queries = [1]
Output: [0]
Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1, 
so answer[0] = 0.
 

Constraints:

n == nums.length
m == queries.length
1 <= n, m <= 1000
1 <= nums[i], queries[i] <= 1e6

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector <int> answerQueries(vector <int> &nums, vector <int> &queries) {
        sort(nums.begin() , nums.end());
        // create prefix sum array...

        int n = nums.size();
        int m = queries.size();

        vector <int> ans;

       
        // modifying the nums array to prefix array itself..
        for (int i=1; i<n; i++){
            nums[i] = nums[i] + nums[i-1]; 
        }

        // for each queries check at what extent you can go in prefix array...

        for (int i=0; i<m; i++){
            int target = queries[i];

            // iterating over each prefix array element ....
            int count = 0;
            for (int j=0; j<n; j++){
                if (nums[j] > target) break;
                else count++; 
            }

            // har query ka answer store kara...
            ans.push_back(count);
        }

        return ans;
    }

};




// -------- --- --  -

class Solution {
public:

    vector <int> answerQueries(vector <int> &nums, vector <int> &queries) {
        sort(nums.begin() , nums.end());
        // create prefix sum array...

        int n = nums.size();
        int m = queries.size();

        vector <int> ans;

        vector <int> pref(n, 0);
        pref[0] = nums[0];
        for (int i=1; i<n; i++){
            pref[i] = nums[i] + pref[i-1]; 
        }

        // for each queries check at what extent you can go in prefix array...

        for (int i=0; i<m; i++){
            int target = queries[i];

            // iterating over each prefix array element ....
            int count = 0;

            for (int j=0; j<n; j++){

                if (pref[j] <= target){ // jab tak range mai rahega mera count par khud par khud hi update hota rahega...... agar kahi bhi bada hogaya to uss query ke liye loop break kar jaega...
                    count = j + 1;
                }

                else break;
            }

            // har query ka answer store kara...
            ans.push_back(count);
        }

        return ans;
    }
};

// t.c. = O(mn)




// 

class Solution { // t.c = O(mlogn)
public:

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin() , nums.end());

        // change nums to prefix (kaamal method)
        for (int i=1; i<n; i++){
            nums[i] += nums[i-1];
        }

        // now binary search in nums array the queries[i]
        vector <int> ans;

        for (int i=0; i<queries.size(); i++){
            int query = queries[i];

            int lo = 0;
            int hi = n-1;
            
            // {best trick to find the best index}
            //  in case binary search mai perfect ekdum equal waala element na search kar rahe ho...

            int best = 0;   
            while (lo <= hi){
                int mid = lo + (hi - lo)/2;

                if (nums[mid] <= query){
                   best = mid + 1;
                   lo = mid + 1;
                }

                else hi = mid-1;
            }

            ans.push_back(best);
        }

        return ans;
    }
};


/*


accha ek cheej note kari aapne ki jab aap nums ko sort kar chuke ho ..
and prefix array bhi aapka increasing sorted order mai hi hai...
now prefix array mai lineraly kis extent tak jaa sakte hai na check karke hum binary search 
bhi to laga sakte hai...har query ke liye...

*/