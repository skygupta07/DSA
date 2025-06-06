#include <bits/stdc++.h>
using namespace std;

/*

You are given a sorted integer array arr containing 1 and prime numbers, 
where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, 
where answer[0] == arr[i] and answer[1] == arr[j].


Example 1:

Input: arr = [1,2,3,5], k = 3
Output: [2,5]

Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.


Example 2:

Input: arr = [1,7], k = 1
Output: [1,7]
 

Constraints:

2 <= arr.length <= 1000
1 <= arr[i] <= 3 * 104
arr[0] == 1
arr[i] is a prime number for i > 0.
All the numbers of arr are unique and sorted in strictly increasing order.
1 <= k <= arr.length * (arr.length - 1) / 2
 

Follow up: Can you solve the problem with better than O(n2) complexity?

*/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        priority_queue <int, vector<int>, greater<int> > pq;

        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> minHeap;
        int n = arr.size();
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                minHeap.push( { (double)arr[i]/arr[j] , {arr[i] , arr[j]} });
            }
        }

        pair <int,int> result;

        // With our heap filled, we retrieve the kth smallest fraction by popping from the top k times
        for (int i=0; i<k; i++){
            result = minHeap.top().second;
            minHeap.pop();  // top is always followed by pop
        }

        return {result.first, result.second};
    }
};