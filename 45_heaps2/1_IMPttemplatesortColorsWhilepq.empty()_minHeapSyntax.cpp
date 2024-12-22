#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue < int, vector<int>, greater<int> > pq(nums.begin(), nums.end()); // minheap ka syntax sabse easy wala jab aap simply integer 
        // se khel rahe ho..
        
        int i = 0;
        while (!pq.empty()){
            nums[i] = pq.top(); // accha priority_queue mai element fetch karne ke liye top() ka use karte hai..
            pq.pop();
            i++;
        }
    }
};

/* using min heap

Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

*/