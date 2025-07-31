// countOfSmallerNumberAfterSelf.cpp

// isme tum kaise keh sakte ho ki merge sort lagega ?? 


#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, return an integer array counts where counts[i] 
is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]

Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

*/


class Solution {    // brute force => gives tle
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector <int> ans;
        int n = nums.size();

        for (int i=0; i<n-1; i++){
            int count = 0;
            for (int j=i+1; j<n; j++){
                if (nums[j] < nums[i]) count++;
            }
            ans.push_back(count);
        }

        // for very last element 
        ans.push_back(0);

        return ans;
    }
};



 // using mergeSort
class Solution {   
public:

    // Ye function merge kar raha hai aur sath hi count array update kar raha hai
    void merge(vector<int> &count, vector <pair<int, int>> &v, int left, int mid, int right) {
        
        vector <pair<int, int>> tmp(right-left+1); // Temporary array banaya for merging
        
        int i = left;  // Left half ka starting index
        int j = mid+1; // Right half ka starting index
        
        int k = 0;     // Temporary array ka index

        while (i <= mid && j <= right) {

            // Descending order me sort kar rahe hain
            if (v[i].first <= v[j].first) { 
                tmp[k++] = v[j++]; // Agar v[j] bada hai toh usko pehle daal do
            }

            else {
                // Yaha par count array ko update kar rahe hain
                // Kyunki v[i].first bada hai, toh jitne elements v[j] ke right me hain 
                // (including v[j] itself) sab chhote honge v[i] se
                count[v[i].second] += (right - j + 1);
                
                tmp[k++] = v[i++]; // v[i] ko daal do
            }
        }

        // Agar left half ke kuch elements reh gaye hain
        while (i <= mid) tmp[k++] = v[i++];
        

        // Agar right half ke kuch elements reh gaye hain
        while (j <= right) tmp[k++] = v[j++];
        

        // Original array ko update kar do
        for (int i = left; i <= right; i++) v[i] = tmp[i-left];
    }        

    // Ye function recursive merge sort perform karega
    void mergeSort(vector <int> &count, vector <pair<int, int>> &v, int left, int right) {
        // Base case: Jab ek hi element bache toh return kar do
        if (left >= right) return; 

        int mid = left + (right-left)/2; // Mid calculate kiya

        // Left half ko sort karo
        mergeSort(count, v, left, mid);
        // Right half ko sort karo
        mergeSort(count, v, mid+1, right);
        // Dono halves ko merge karo
        merge(count, v, left, mid, right);
    }

    // Main function jo input lega aur result return karega
    vector <int> countSmaller(vector <int> &nums) {
        int N = nums.size();

        // Pair bana rahe hain taaki original index store rahe
        vector <pair <int, int>> v(N);
        
        // (value, index) pair store kiya
        for (int i = 0; i < N; i++) v[i] = make_pair(nums[i], i);  // or {nums[i], i}

        vector <int> count(N, 0); // Har element ke liye count array initialize kiya

        // Merge sort call kiya jo descending order me sorting karega
        mergeSort(count, v, 0, N-1);

        // Final count array return kar diya
        return count; 
    }

};


