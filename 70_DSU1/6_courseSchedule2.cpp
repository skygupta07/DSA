class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build the graph and indegree array
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> qu;
        
        // Enqueue nodes with zero indegree
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                qu.push(i);
            }
        }

        // Perform BFS
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            ans.push_back(node);

            for (int neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    qu.push(neighbor);
                }
            }
        }

        // Check if we have processed all courses
        if (ans.size() == numCourses) {
            return ans;
        } else {
            return {};
        }
    }
};