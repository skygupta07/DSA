#include <bits/stdc++.h>
using namespace std;

/*

Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2). 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], 
and the 8th smallest number is 13

Example 2:

Input: matrix = [[-5]], k = 1
Output: -5

*/


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Min-heap to store {value, {row, col}}.
        // The smallest element will be at the top.
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> minHeap;

        int n = matrix.size();

        // Step 1: Push the first element of every row into the heap
        for (int i = 0; i < n; i++) {
            minHeap.push({matrix[i][0], {i, 0}});
        }

        // Variable to store the current smallest value during extraction
        pair<int, pair<int, int>> current;

        // Step 2: Pop the smallest element k times
        while (k-- && !minHeap.empty()) {
            current = minHeap.top();
            minHeap.pop();

            int val = current.first;
            int row = current.second.first;
            int col = current.second.second;

            // Step 3: If the current element has a right neighbor in the row, push it
            if (col + 1 < n) {
                minHeap.push({matrix[row][col + 1], {row, col + 1}});
            }
        }

        // After k pops, current holds the kth smallest element
        return current.first;
    }
};


    class Solution {
        public:
           
            int kthSmallest(vector<vector<int>>& matrix, int k){
                int rows = matrix.size();
                int cols = matrix[0].size();
                vector <int> arr;
                for (int i=0; i<rows; i++){
                    for (int j=0; j<cols; j++){
                        arr.push_back(matrix[i][j]);
                    }
                }
                sort(arr.begin(), arr.end());
                return arr[k-1];
            }
        };
        
    /*
        sort vector
        return kth  
    */