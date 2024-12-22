#include <iostream>
#include <vector>
using namespace std;
int main(){

}

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> result(n, vector <int> (m, INT_MAX));

        queue <pair <int,int>> q;
        // multisource bfs

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 0){
                    result[i][j] = 0;  // zero se zero ka distance is zero..
                    q.push({i,j});
                }
            }
        }

        // bfs ke liye direction array banai...
        vector <vector<int> > dirs {{-1,0} , {1,0} , {0,-1}, {0,1}};

        while (!q.empty()){
            pair <int,int> cell = q.front();
            q.pop();

            for (auto dir : dirs){
                int newRow = cell.first + dir[0];
                int newCol = cell.second + dir[1];
            

                if (newRow >=0 && newRow < n && newCol >=0 && newCol < m){
                    if (result[newRow][newCol] > result[cell.first][cell.second] + 1){
                        result[newRow][newCol] = result[cell.first][cell.second] + 1;
                        q.push({newRow, newCol});
                    }
                }
             }
        }
        return result;
    }
};


---- also try multisource bfs from the zero itself....

