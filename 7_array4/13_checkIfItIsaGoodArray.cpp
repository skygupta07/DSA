#include <bits/stdc++.h>
using namespace std;

/*

Given an array nums of positive integers.
Your task is to select some subset of nums, multiply each element by an integer
and add all these numbers. The array is said to be good if you can obtain a sum of 1
from the array by any possible subset and multiplicand.

Return True if the array is good otherwise return False.

Example 1:

Input: nums = [12,5,7,23]
Output: true
Explanation: Pick numbers 5 and 7.
5*3 + 7*(-2) = 1


Example 2:

Input: nums = [29,6,10]
Output: true
Explanation: Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1


Example 3:

Input: nums = [3,6]
Output: false


Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9



*/

class Solution
{
public:
    bool isGoodArray(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i <= n - 2; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                if (__gcd(nums[i], nums[j]) == 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
har do pair pe check kara jaise hi gcd 1 aagya loop break kar do...

yaha par mai O(n^2) wala kaam kar raha tha.... but same cheej threshold zeroth element and then
single loop mai iterate karte huye bhi update kar sakta tha.....
*/

class Solution
{
public:
    bool isGoodArray(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return false;

        int current_gcd = nums[0];
        for (int i = 1; i < n; ++i)
        {
            current_gcd = __gcd(current_gcd, nums[i]);
            if (current_gcd == 1)
            {
                return true;
            }
        }
        return current_gcd == 1; // or return false bhi chalega... simply non void wala bachane ke liye kiya....
    }
};