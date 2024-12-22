#include <bits/stdc++.h>
using namespace std;

/*
There exists an undirected tree with n nodes numbered 0 to n - 1. 
You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi]
indicates that there is an edge between nodes ui and vi in the tree. 
You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n,
where nums[i] represents the value of the node numbered i.

Alice wants the sum of values of tree nodes to be maximum, 
for which Alice can perform the following operation any number of times (including zero) on the tree:

Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
nums[u] = nums[u] XOR k
nums[v] = nums[v] XOR k
Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.
*/

class Solution {
public:
    // using ll = long long;
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        ll count = 0;   // count of the persons who want to do xor operations on themselves
        ll baliKaBakra = INT_MAX;

        for (auto el: nums){
            if ((el^k) > el){
                sum += el^k;
                baliKaBakra = min(baliKaBakra, ll(el^k) - el);
                count++;
            }
            else{   // matlab incoming number ka xor karne se value increase nahi kar rahi to usko simply 
            // hi add kardo ...but bali ka bakra abhi bhi dundhdo...
                sum += el;
                baliKaBakra = min(baliKaBakra, el - ll(el^k));
            }
        }
        
        if (count % 2 == 0) return sum;
        else return (sum - baliKaBakra);

    }
};


/*
I know I can propagate the xor operation effect in the tree itself....


if there are even number of guys on which if i perform xor operation then their value increases is a simple case...
waha pe extra xor jo hai cancel bhi ho jaa rahe they.....

but agar yahi count odd hua to mujhe ek balikabakra choose karna hoga and uski value ko normally or xor 
karke add karke dekhni hogi jaha se max value contribution milega wo final answer hoga...

time : O(n) , Space: O(1)
*/