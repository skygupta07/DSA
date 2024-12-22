#include <bits/stdc++.h>
using namespace std;

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




class Solution {
public:

    void bfs(int row, int col, vector<vector<int>> &vis, vector <vector<char>> &grid ){
        vis[row][col] = 1;
        queue <pair <int,int>> q;

        int m = grid.size();    // row
        int n = grid[0].size();

        q.push({row, col}); // pushing the grid index...

        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second; 
            q.pop();

            // traverse in the neighbours and mark them if it is a land...

            for (int delrow = -1; delrow <= 1; delrow++){
                for (int delcol = -1; delcol <= 1; delcol++){
                    int nrow = row + delrow;    // nrow = neighbour row
                    int ncol = col + delcol;

                    if (nrow >= 0 && nrow < m && ncol >=0 && ncol < n 
                        && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                }
            }
        }


    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector <vector<int>> vis(m, vector <int> (n, 0));
        // we are initialising a 2d vector (grid) with m rows and n columns....each cell initialised with zero..
        // It's a common way to represent a grid where you want to keep track of whether each cell has been
        // visited or not, typically used in algorithms like graph traversal (e.g., BFS, DFS).

        int count = 0;

        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        
        return count;
    }
};







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
    };






-----  4 dirn --------         
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
