#include <bits/stdc++.h>
using namespace std;

/*

Implement the Min Heap data structure.
You will be given 2 types of queries:-
0 X
Insert X in the heap.

1
Print the minimum element from the heap and remove it.

*/

vector<int> minHeap(int n, vector<vector<int>>& query) {
    priority_queue <int, vector <int> , greater <int> > pq;

    vector <int> ans;

    for (auto q : query){
        if (q[0] == 0) pq.push(q[1]);
        else{
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    return ans;
}
