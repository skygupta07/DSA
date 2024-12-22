#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int r = image.size();
        int c = image[0].size();

        vector<vector<int>> ans(r, vector <int> (c,0));

        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                ans[i][j] = !(image[i][c-1-j]);
            }
        }
        return ans;
    }
};