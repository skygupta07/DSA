#include <bits/stdc++.h>
using namespace std;

/*

    Here, queries[i] is a vector of integer representing the ith query, 
    in which for different type of queries i.e -:
    1. PUSH 'X' -: queries[i][0] = 1, and queries[i][1] = 'X';
    2. POP -: queries[i][0] = 2;
    3. INC 'K', 'Y' -: queries[i][0] = 3, queries[i][1] = 'K' and queries[i][2] = 'Y';
    
*/

vector<int> answerQueries(vector<vector<int>> &queries, int limit) {
    vector <int> ans;
    stack <int> stk;
    stack <int> helper;

    for (auto &q : queries){

        // push 
        if (q[0] == 1){
            if (stk.size() < limit) stk.push(q[1]);
        }

        // pop
        else if (q[0] == 2){
            if (stk.empty()) ans.push_back(-1);
            else{
                ans.push_back(stk.top());
                stk.pop();
            }
        }

        // increment
        else if (q[0] == 3){
            int k = q[1];
            int y = q[2];

            while (!stk.empty()){
                helper.push(stk.top());
                stk.pop();
            }

            while (!helper.empty()){
                int value = helper.top();
                helper.pop();

                if (k > 0){
                    value += y;
                    k--;
                }

                stk.push(value);
            } 
        }
    }
    return ans;
}