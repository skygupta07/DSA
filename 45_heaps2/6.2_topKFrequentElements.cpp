// topKFrequentElements.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map <int, int> mp;
        for (auto el: nums){
            mp[el]++;
        }

        // unordered_map <int, int> mp2;

        // for (auto el : mp){
        //     mp2[el.second] = el.first;
        // }

        // freq, element
        priority_queue <pair <int, int> >  pq;

        for (auto el: mp){
            pq.push({el.second, el.first}); // freq, element
        }

        while (k-- && !pq.empty()){
            int x = pq.top().second;    // element
            pq.pop();

            ans.push_back(x);
        }

        return ans;
    }
};


/*
map of freq, element
now create maxHeap and put map elements there 

now while (k-- and ) fetch and store in ans

*/