#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue <pair <int, pair<int,int>>, vector<pair <int, pair<int,int>>>, greater<pair <int, pair<int,int>>> > pq;  // min heap syntax 

        for(int i=0; i<matrix.size(); i++){
            pq.push({matrix[i][0], {i,0}});
        }
        pair <int, pair <int,int> > ans;
        while (k-- and not pq.empty()){

            // topo condition check then push
            ans = pq.top();
            pq.pop();

            int val = ans.first;
            int row = ans.second.first; // cool -> shivaji the boss
            int col = ans.second.second;
            if (col + 1 < matrix[row].size()){
                pq.push({matrix[row][col+1], {row,col+1}});
            }
        }
        return ans.first;

        
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