#include <bits/stdc++.h>
using namespace std;

/*

You are given a Binary Tree with the root node provided. 
Starting from the root, imagine traveling to the right until you reach a leaf node. 
During this traversal, collect the values of all the nodes encountered in your path.

At the end of the traversal:

Calculate the sum of the collected node values.
Determine whether the sum is a perfect square. A number is considered a perfect square 
if it can be expressed as the square of an integer (e.g., 1, 4, 9, 16, etc.).

Note: Tree node values are given in a level-order traversel, 
where N in the sequence represents the NULL node.

Input Format

The first line contains an integer M, representing the Nodes of the Tree.
The second line contains M space-separated values, representing the Tree Nodes in level order.

Output Format

Print "YES" if the sum of the collected values is a perfect square; otherwise, print "NO".

Constraints

1 ≤ N ≤ 10^4

1 ≤ arr[i] ≤ 10^4

Sample Testcase 0

Testcase Input
7
5 3 8 N N 6 10
Testcase Output
NO
Explanation

Level order traveral of the tree:
                             5
                           /     \ 
                        3         8
                                  /   \
                                6    10

Now we need to traverse toward right.
5 -> 8 -> 10
Sum = 23 (not a perfect square).

Sample Testcase 1

Testcase Input
15
1 2 3 4 5 6 7 8 9 N N N N 10 14
Testcase Output
YES
Explanation

Level order traveral of the tree:
                             1 
                           /     \ 
                        2         3 
                     /     \      /    \
                  4        5   6     7 
                /   \                  /   \
              8     9              10   14

Now we need to traverse toward right.
1 -> 3 -> 7 -> 14
Sum = 25 (perfect square).


*/


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to calculate the sum of the rightmost path
int solve(vector <int> &nodes) {
    int n = nodes.size();
    int idx = 0;
    int sum = 0;

    while (idx < n){
        if (nodes[idx] == -1) break; // Stop if the node is NULL

        sum += nodes[idx];
        int right = 2 * idx + 2; // Right child index

        if (right >= n || nodes[right] == -1) break; // Avoid out-of-bounds or NULL access
        idx = right;
        
    }

    return sum;
}

// Function to check if a number is a perfect square
bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return root * root == n;
}

// Main logic function
string user_logic(int M, vector<int>& nodes) {
    int sum = solve(nodes);
    return isPerfectSquare(sum) ? "YES" : "NO";
}

int main() {
    int M;
    cin >> M;
    
    if (M == 0) { // Handle empty tree case
        cout << "NO" << endl;
        return 0;
    }

    vector<int> nodes(M);
    for (int i = 0; i < M; ++i) {
        string val;
        cin >> val;
        if (val == "N") {
            nodes[i] = -1; // N represents NULL
        } else {
            nodes[i] = stoi(val);
        }
    }

    string result = user_logic(M, nodes);
    cout << result << endl;
    return 0;
}