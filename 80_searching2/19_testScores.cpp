#include <bits/stdc++.h>
using namespace std;


// Function to process queries efficiently
vector<int> user_logic(int n, int q, vector<int>& scores, vector<int>& queries) {
    sort(scores.begin(), scores.end());  // Step 1: Sort the scores
    vector<int> ans;

    for (int x : queries) {
        // Step 2: Use lower_bound to find first element >= x
        int idx = lower_bound(scores.begin(), scores.end(), x) - scores.begin();
        int count = n - idx;  // Step 3: Total students - idx = number of students with score >= x
        ans.push_back(count);
    }

    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }
    
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    vector<int> results = user_logic(n, q, scores, queries);

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
