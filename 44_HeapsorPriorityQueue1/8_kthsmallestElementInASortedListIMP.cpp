#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Min-heap ka syntax yaha likha hai. Ye heap pair of integers ko store karega,
        // jisme pehla integer matrix ka value hoga, aur doosra pair matrix ke row aur column ka index.
        priority_queue <pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;  // min heap syntax 

        // Pehle sabhi rows ke pehle element ko heap me push karenge, kyunki har row ke elements sorted hote hain.
        for(int i = 0; i < matrix.size(); i++){
            pq.push({matrix[i][0], {i, 0}});  // Matrix ke i-th row ka pehla element heap me push kar rahe hain.
        }

        pair <int, pair<int, int>> ans;  // Yeh pair answer ko store karega, jo heap ka top hoga (min element).

        // Jab tak k th smallest element nahi mil jata ya heap khali nahi hota, tab tak loop chalega.
        while (k-- and not pq.empty()) {
            // AND mai agar pehli condition false ho gayi to wo dusri check nahi karta...
            // Heap ke top pe jo element hoga, wo ab tak ka smallest element hoga. Use nikal kar ans me store karenge.
            ans = pq.top();
            pq.pop();

            int val = ans.first;  // Current smallest element (yehi answer ban sakta hai agar k == 0 ho gaya).
            
            int row = ans.second.first;  // Matrix ke uss element ka row index.
            int col = ans.second.second;  // Matrix ke uss element ka column index.

            // Ab hum us row ke next element ko heap me push karenge, agar row me aur elements bache hain to.
            if (col + 1 < matrix[row].size()) {
                pq.push({matrix[row][col + 1], {row, col + 1}});  // Next element push karo heap me.
            }
        }
        
        return ans.first;  // Jab loop khatam hoga, ans.first me k-th smallest element store hoga.
    }
};

/*

prirority_queue <datatype> pq;  // maxheap


// minheap
priority_queue < alpha, beta, gamma > 
priroity_queue <int, vector <int> , greater <int> > pq;

priority_queue < a, b, c > pq;


priority_queue < pair<int,int>, vector <pair <int, int> > , greater <pair <int,int> > > > pq;

*/