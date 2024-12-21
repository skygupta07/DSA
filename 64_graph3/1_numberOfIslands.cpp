#include <iostream>
#include <vector>
using namespace std;
int main(){

}


class Solution {
public:
        int numberOfIslands = 0;

        void dfs(vector<vector<char> > &grid, int rows, int cols, int currRow, int currCol , vector<vector <bool> > &visited){
            // base case 
            if (currRow < 0 || currRow >= rows || currCol < 0 || currCol >= cols){
                return;
            }

            if (grid[currRow][currCol] == '0' || visited[currRow][currCol]){
                return;
            }
            // jis bhi row pe aaye ho wo ab land hi hoga...so mark it visited...
            visited[currRow][currCol] = true;

            dfs(grid, rows, cols, currRow+1, currCol, visited); // down
            dfs(grid, rows, cols, currRow-1, currCol, visited); // up
            dfs(grid, rows, cols, currRow, currCol+1, visited); // right
            dfs(grid, rows, cols, currRow, currCol-1, visited);  // left
        }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();


        // visited array 
        vector <vector <bool> > visited(n, vector<bool>(m,false));

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if ( grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, n, m, i, j, visited);
                    numberOfIslands++;      // jaha se bhi dfs call ho paa rahi hai atleast ek cell ka hi ho magar wo .... island to banayega hi....
                }
            }
        }

        return numberOfIslands;
    }
};



----- bfs -----------

class Solution {
    private:
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>&vis)
    {
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    int row=grid.size();
    int col=grid[0].size();
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
        int newrow=r+delrow[k];
        int newcol=c+delcol[k];

        if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && grid[newrow][newcol]=='1' &&       !vis[newrow][newcol])
        {
            vis[newrow][newcol]=1;
            q.push({newrow,newcol});
        }
        }
        
    }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    bfs(grid,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }
};

/*
iterate kara ...jo bhi cell 1 hoga aur unvisited hoga waha se dfs chalu kar dunga...
and count bhi increase kar dunga...

dfs kewal 1 wale land ko hi include karna chahiye...

*/
