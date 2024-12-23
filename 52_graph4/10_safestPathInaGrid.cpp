#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rowDir = {-1, 1, 0, 0};
    vector<int> colDir = {0, 0, -1, 1};

    bool isValid(vector<vector<bool>> &visited, int i, int j)
    {
        if (i < 0 || j < 0 || i == visited.size() || j == visited[0].size() || visited[i][j])
            return false;
        return true;
    }

    bool isSafe(vector<vector<int>> &distToThief, int safeDist)
    {
        int n = distToThief.size();
        queue<pair<int, int>> q;

        if (distToThief[0][0] < safeDist)
            return false;
        q.push({0, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        visited[0][0] = true;

        // bfs traversal for traversal over the grid...
        while (!q.empty())
        {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            if (currRow == n - 1 && currRow == n - 1)
                return true;

            for (int dirIdx = 0; dirIdx < 4; dirIdx++)
            {
                int newRow = currRow + rowDir[dirIdx];
                int newCol = currCol + colDir[dirIdx];

                if (isValid(visited, newRow, newCol))
                {
                    if (distToThief[newRow][newCol] < safeDist)
                        continue;
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;

        vector<vector<bool>> visited(n, vector<bool>(n, false)); // smartly creating 2d vector...
        vector<vector<int>> distToThief(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                { // make the theif visited and push the theif into the queue..
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        int len = 0;
        // doing bfs traversal....
        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                int currRow = q.front().first;
                int currCol = q.front().second;
                q.pop();

                distToThief[currRow][currCol] = len;

                for (int dirIdx = 0; dirIdx < 4; dirIdx++)
                {
                    int newRow = currRow + rowDir[dirIdx];
                    int newCol = currCol + colDir[dirIdx];

                    if (!isValid(visited, newRow, newCol))
                        continue;

                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
            len++;
        }

        // doing binary search...

        int lo = 0;
        int hi = len;
        int ans = 0;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isSafe(distToThief, mid))
            {
                ans = mid;
                lo = mid + 1; // trying for higher safer distance...
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
};

/*
thinking reverse -> start bfs traversal from the theif itself..
binary search ka use karke hi safeness factor ko maximize kar raha hu....


*/

// -------

class Solution
{
public:
    vector<int> roww = {0, 0, -1, 1};
    vector<int> coll = {-1, 1, 0, 0};

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &score, int n)
    {
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();

            int x = t.first, y = t.second;
            int s = score[x][y];

            for (int i = 0; i < 4; i++)
            {
                int newX = x + roww[i];
                int newY = y + coll[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && score[newX][newY] > 1 + s)
                {

                    score[newX][newY] = 1 + s;
                    q.push({newX, newY});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;

        vector<vector<int>> score(n, vector<int>(n, INT_MAX));
        bfs(grid, score, n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({score[0][0], {0, 0}});

        while (!pq.empty())
        {
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            if (temp.first == n - 1 && temp.second == n - 1)
                return safe;
            vis[temp.first][temp.second] = true;

            for (int i = 0; i < 4; i++)
            {
                int newX = temp.first + roww[i];
                int newY = temp.second + coll[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY])
                {
                    int s = min(safe, score[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }

        return -1;
    }
};