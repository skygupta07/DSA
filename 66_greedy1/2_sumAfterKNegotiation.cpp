#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {   //O(klogn + n)
        priority_queue <int, vector<int>, greater<int> > pq(nums.begin() , nums.end()); //O(n)
        int sum = 0;
        for (int i=0; i<nums.size(); i++) sum += nums[i];   // O(n)

        while (k--){    // O(klogn)
            int el = pq.top();  // it will be min. available element of array since min heap
            if (el==0) break;   // no operation need to done if encountered zero
            pq.pop();
            sum -= el;
            pq.push(-1*el);
            sum += -el;
        }
        return sum;    
    }
};

// using priority queue to get the min. element of the available array
