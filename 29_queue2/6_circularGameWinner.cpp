#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue <int> q;
        for (int i=1; i<=n; i++) q.push(i);

        // start game 

        while (q.size() > 1){
            // to po push kar k-1 times then jo bhi front mai hoge ussey hamesa ke liye pop         
            for(int i=0; i<k-1; i++){
                int tp = q.front();
                q.pop();
                q.push(tp);
            }
            q.pop();
         
        }
        return q.front();
    }
};

// ------

class Solution {
public:
    int helper(int n, int k){
        int ans = 0;
        for (int i=1; i<=n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }

    int findTheWinner(int n, int k) {
        return helper(n,k) + 1;
    }
};