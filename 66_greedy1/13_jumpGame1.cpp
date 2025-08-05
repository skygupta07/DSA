// jumpGame1.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


Example 1:

Input: nums = [2,3,1,1,4]
Output: true

Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.


Example 2:

Input: nums = [3,2,1,0,4]
Output: false

Explanation: You will always arrive at index 3 no matter what. 
Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 1e4
0 <= nums[i] <= 1e5

*/


class Solution {
public:

    // Function to check if we can reach the last index from the first
    bool canJump(vector <int> &arr){
        int n = arr.size();

        int minJump = 0; // Minimum jumps needed from the current index to reach the end

        // Traverse the array from second last element to the start
        for (int i = n - 2; i >= 0; i--){
            minJump++; // Har step pe ek jump toh lagega hi

            // Agar current index se minJump ya usse zyada door tak ja sakte hain
            if (arr[i] >= minJump){
                minJump = 0; // Yahan se jump possible hai, toh yeh index humare liye "safe" ban gaya
            }
        }

        // Agar first index se last tak pahuchna possible hai toh minJump 0 hona chahiye
        if (minJump == 0) return true;
        
        else return false;   
    }

};
