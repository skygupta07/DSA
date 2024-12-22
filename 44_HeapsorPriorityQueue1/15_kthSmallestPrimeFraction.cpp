#include <bits/stdc++.h>
using namespace std;

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