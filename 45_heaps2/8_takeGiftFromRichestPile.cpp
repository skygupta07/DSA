#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue <int> pq;

        for (auto gift: gifts) pq.push(gift);

        while (!pq.empty() && k--){
            int tp = pq.top();
            pq.pop();

            pq.push(sqrt(tp));
        }

        long long sum = 0;
        
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};