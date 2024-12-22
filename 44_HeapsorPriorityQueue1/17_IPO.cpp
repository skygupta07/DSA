#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       int n = profits.size();
       vector <pair <int,int>> vp;

       for (int i=0; i<n; i++){
            vp.push_back({capital[i] , profits[i]});
       }
       // will be sorted on basis of capital...
       sort(vp.begin(), vp.end());
       priority_queue <int> pq;

       int totalProfit = w;
       int j = 0;

       for (int i=0; i<k; i++){
            while (j<n && vp[j].first <= totalProfit){
                pq.push(vp[j].second);
                j++;
            }

            if (pq.size() == 0) break;
            totalProfit += pq.top();
            pq.pop();
       }

       return totalProfit;

    }
};


// try consuming less capital and gaining more profit for a given capital...
// jiska kaam ho jaega usko heap se nikal dunga....
// and now ab itne profit mai jitne kharidne layak ban gya hu to unhe daal dunga....
