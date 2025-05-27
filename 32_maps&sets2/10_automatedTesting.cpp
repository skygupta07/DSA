#include <bits/stdc++.h>
using namespace std;

int user_logic(int n, int x, const std::string& s) {
    
    unordered_set<int> visited;  // Stores distinct positions
    visited.insert(x);
    
    for (char c : s) {
        x += (c == 'R') ? 1 : -1;  // Update position
        visited.insert(x);  // Mark position as visited
    }

    return visited.size();  // Return the number of distinct positions visited
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, x;
        string s;
        cin >> n >> x >> s;
        cout << user_logic(n, x, s) << endl;
    }
    
    return 0;
}
