#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector <int> incoming(n, 0);

        for (const auto& edge: edges){
            incoming[edge[1]]++;   // accha jo bhi incoming honge wo to winner nahi honge ofcourse to unhe hi blacklist kiya..
        }

        vector <int> champions;
        
        for (int i=0; i<n; i++){
            if (incoming[i] == 0){  // dudh ke dhule...
                champions.push_back(i);
            }
        }

        if (champions.size() > 1) return -1;
        return champions[0];
    }
};