#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int tortoise = nums[0];

        do{
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        } while (hare != tortoise);

        // to find the starting of cycle, make tortoise to start from beginning

        tortoise = nums[0];
        while(hare != tortoise){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }

        return hare;
    }
};

// using floyd cycle detection.....
