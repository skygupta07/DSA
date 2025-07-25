/*

Question Title:
Count Elements Less Than or Equal to A[i] from Array B

📄 Problem Statement:
You are given two integer arrays:

a[0...n-1]
b[0...n-1]

You are also given a query [0...q-1] array, where each element is an index into array a.

For each query, your task is to count how many elements in array b 
are less than or equal to a[query[i]], and return the result for each query.


🧪 Example:

Input:
a = [4, 8, 7, 5]
b = [1, 2, 8, 3]
query = [0, 1, 2]

Output:
3 4 4

Explanation:

- For query[0] = 0 → a[0] = 4 → elements in b ≤ 4 are [1, 2, 3] → count = 3
- For query[1] = 1 → a[1] = 8 → elements in b ≤ 8 are [1, 2, 3, 8] → count = 4
- For query[2] = 2 → a[2] = 7 → elements in b ≤ 7 are [1, 2, 3] → count = 3

*/



#include <bits/stdc++.h>
using namespace std;
  
vector <int> countElements(vector <int> &a, vector <int> &b, int n, vector <int> &query,
                              int q) {
        
        vector <int> pref(100002,0);

        for(int i=0; i<n; i++){
            pref[b[i]]++;
        }

        for(int i=1;i<100002;i++){
            pref[i] += pref[i-1];
        }

        vector<int> ans;

        for(const auto &i : query){
            ans.push_back(pref[a[i]]);
        }
        
        return ans;

}


    