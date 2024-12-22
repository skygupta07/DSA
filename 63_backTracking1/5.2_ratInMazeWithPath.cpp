class Solution {
public:
    // Check if the cell (i, j) is safe to visit
    bool isSafe(vector<vector<int>> &mat, int i, int j, int n) {
        // Cell is safe if it's within bounds, not blocked (1), and not visited (not 2)
        return (i >= 0 && j >= 0 && i < n && j < n && mat[i][j] == 1);
    }

    // Recursive function to find all paths
    void traverse(vector<vector<int>> &mat, int i, int j, string &path, vector<string> &ans, int n) {
        // Base case: Reached the destination cell
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path); // Add the path to the result
            return;
        }

        // Mark the current cell as visited
        mat[i][j] = 2;

        // Explore all 4 possible directions

        // Left
        if (isSafe(mat, i, j - 1, n)) {
            path += "L"; // Add "L" to the path
            traverse(mat, i, j - 1, path, ans, n);
            path.pop_back(); // Backtrack
        }

        // Right
        if (isSafe(mat, i, j + 1, n)) {
            path += "R"; // Add "R" to the path
            traverse(mat, i, j + 1, path, ans, n);
            path.pop_back(); // Backtrack
        }

        // Up
        if (isSafe(mat, i - 1, j, n)) {
            path += "U"; // Add "U" to the path
            traverse(mat, i - 1, j, path, ans, n);
            path.pop_back(); // Backtrack
        }

        // Down
        if (isSafe(mat, i + 1, j, n)) {
            path += "D"; // Add "D" to the path
            traverse(mat, i + 1, j, path, ans, n);
            path.pop_back(); // Backtrack
        }

        // Unmark the current cell (backtracking)
        mat[i][j] = 1;
    }

    // Main function to find all paths
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans; // To store all possible paths
        string path = "";   // Current path

        int n = mat.size(); // Size of the matrix

        // If the starting cell is blocked, return an empty result
        if (mat[0][0] == 0) return ans;

        // Call the recursive function starting from (0, 0)
        traverse(mat, 0, 0, path, ans, n);

        return ans; // Return the result
    }
};