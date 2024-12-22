#include <bits/stdc++.h>
using namespace std;



/*

You are given an array of positive integers nums of length n.

A polygon is a closed plane figure that has at least 3 sides.
 The longest side of a polygon is smaller than the sum of its other sides.

Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ..., ak 
where a1 <= a2 <= a3 <= ... <= ak and a1 + a2 + a3 + ... + ak-1 > ak, then there
 always exists a polygon with k sides whose lengths are a1, a2, a3, ..., ak.

The perimeter of a polygon is the sum of lengths of its sides.
Return the largest possible perimeter of a polygon whose sides can be formed from nums, or -1 if it is not possible to create a polygon

*/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        sort(nums.begin(),nums.end());
        for(auto i : nums) sum += i;
        int n = nums.size();
        for(int i = n - 1; i >= 2; i--){
            sum -= nums[i];
            if(sum > nums[i]){
                return sum + nums[i];
            }
        }
        return -1;
    }
};


class Solution {
public:
    int arraySum(vector <int> arr, long long i, long long j){
        long long s = 0;
        for (long long i=0; i<=j; i++){
            s += arr[i];
        }
        return s;
    }

    long long largestPerimeter(vector<int>& arr){
        
        long long n = arr.size();
        sort(arr.begin() , arr.end());
        long long i = 0;
        long long j = n - 1;

        if (j<2) return -1;
        

        // polygon condition
        while (j>=2){
            long long sum = arraySum(arr,i,j);
            long long last = arr[j];
            if ( (sum-last) > last ){
                return sum;
            }
            j--;

        }
        
        return -1; 
    }
};



