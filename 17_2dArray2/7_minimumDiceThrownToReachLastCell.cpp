#include <bits/stdc++.h>
using namespace std;


// Function to calculate the minimum dice throws to reach the last cell
int minDiceThrowToLastCell(vector<vector<int>>& board, int n) {
    // Flatten the board into a 1D array
    vector<int> flatBoard(n * n, -1);

    bool leftToRight = true;

    int idx = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (leftToRight) {
            for (int j = 0; j < n; ++j) {
                flatBoard[idx++] = board[i][j];
            }
        } 
        else {
            for (int j = n - 1; j >= 0; --j) {
                flatBoard[idx++] = board[i][j];
            }
        }
        leftToRight = !leftToRight;
    }

    // BFS setup
    queue<pair<int, int>> q; // Pair: {current_position, dice_throws}
    q.push({0, 0}); // Start from the first cell

    vector<bool> visited(n * n, false);
    visited[0] = true;

    while (!q.empty()) {
        auto [pos, throws] = q.front(); // good way to fetch values
        q.pop();

        // Check if we've reached the last cell
        if (pos == n * n - 1) {
            return throws;
        }

        // Explore all possible dice throws
        for (int dice = 1; dice <= 6; ++dice) {
            int nextPos = pos + dice;
            if (nextPos >= n * n) break;

            // Check destination cell after a snake/ladder
            int dest = (flatBoard[nextPos] != -1) ? flatBoard[nextPos] - 1 : nextPos;

            if (!visited[dest]) {
                visited[dest] = true;
                q.push({dest, throws + 1});
            }
        }
    }

    // If the last cell is unreachable (edge case)
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    cout << minDiceThrowToLastCell(board, n) << endl;
    return 0;
}
