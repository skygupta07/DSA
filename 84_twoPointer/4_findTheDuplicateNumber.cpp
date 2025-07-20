// findTheDuplicateNumber.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] 
inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2


Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


Example 3:

Input: nums = [3,3,3,3,3]
Output: 3

*/


// hashmap
class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_map <int, int> freqMap;

        for (int i=0; i<n; i++){
            freqMap[nums[i]]++;
        }

        for (auto [el, freq] : freqMap){
            if (freq > 1) return el;
        }

        return -1; 
    }
};

// sort and check next 
class Solution { // t.c. = O(nlogn)
public:
    int findDuplicate(vector<int>& arr) {
        sort (arr.begin() , arr.end());

        for (int i=0; i<arr.size()-1; i++){   // or loop ko 1 se start karke then n tak le jaake 
                                            // arr[i] == arr[i-1] bhi check kiya jaa sakta tha..
                                            // personally I prefer this one
            if (arr[i] == arr[i+1] ) return arr[i];
        }
        return -1;
    }
};


class Solution { // tle -> O(n^2) - pure brute force
public:

    int findDuplicate(vector <int> &nums) {
        int n = nums.size();

        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){

                if (nums[i] == nums[j]) return nums[i];

            }
        }
        
        return -1;
    }

};



// hare and tortoise - floyd cycle detection algorithm... {interviews expectation}

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize two pointers: hare and tortoise

        // hare and torotoise ko slow fast pointer bol to rahe ho....magar ye index nahi value store kar 
        // rahe h starting se hi...
        int hare = nums[0]; // Fast pointer (hare)
        int tortoise = nums[0]; // Slow pointer (tortoise)

        // Phase 1: Finding the intersection point in the cycle {kachua ek kadam, khargos do kadam}

        // This loop will run until hare meets tortoise - mene sach mai pehle baar dekha h sach mai while(true) wali
        // condition yaha real life mai use bhi hoti h ...

        while (true) {
            // Move hare two steps forward
            hare = nums[nums[hare]];

            // Move tortoise one step forward
            tortoise = nums[tortoise];

            // If they meet, break the loop
            if (hare == tortoise) break;
        }

        // Phase 2: Finding the entrance to the cycle {ab ek ek kadam hi chalna }

        // Move tortoise back to the start   --- yaha bhi tortoise ko hi bakra bana diya...
        tortoise = nums[0];

        while (hare != tortoise) {
            // Move both pointers one step forward
            hare = nums[hare];
            tortoise = nums[tortoise];
        }

        // At this point, hare and tortoise meet at the starting point of the cycle
        return hare; // The duplicate number

    }
};


/*

t.c. = O(n)
s.c. = O(1)

*/