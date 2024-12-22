#include <bits/stdc++.h>
using namespace std;

// binary search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Handle the edge case where there is only one element in the array.
        if (n == 1) return nums[0];

        int lo = 0;
        int hi = n - 1;

        while (lo < hi) { // Binary search until the search space reduces to a single element.
            int mid = lo + (hi - lo) / 2;

            // Check if `mid` is the single non-duplicate.
            // To avoid out-of-bound access, ensure `mid` isn't the first or last index.
            if ((mid == 0 || nums[mid] != nums[mid - 1]) && 
                (mid == n - 1 || nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }

            // Determine which half to search based on index parity.
            // If the left half up to `mid` contains an odd number of elements,
            // the single element must be in the left half; otherwise, it’s in the right.
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                lo = mid + 1; // Move to the right half.
            } else {
                hi = mid; // Move to the left half. -> dhyan rakhna hoga..
            }
        }

        // When `lo` == `hi`, we have found the single non-duplicate.
        return nums[lo];
    }
};




// single pointer

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // single to single hi rahega...
        if (n == 1) return nums[0];

        int i = 0;

        while (i <= n-2){
            if (nums[i] != nums[i+1]){
                return nums[i];
            }
            else i+=2;
        }

        // ekdum last wala element single bacha hoga...
        return nums[n-1];
    }
};


/*
hashmap -> store freq -> element with single freq is culprit

*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map <int,int> mp;
        for (auto el: nums) mp[el]++;
        for (auto el: mp){
            if (el.second == 1) return el.first;
        }
        return -1;
    }
};

