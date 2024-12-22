#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust){
        vector <int> indegree(n+1 , 0);
        vector <int> outdegree(n+1 , 0);

        for (auto v : trust){
            outdegree[v[0]]++;      // outdegree ke uss index pe rakhe element ko increase karega....
            indegree[v[1]]++;
        }
        
        for (int i=1; i<=n; i++){
            if (indegree[i] == n-1 && outdegree[i] == 0) return i;
        }
        
        return -1;
    }
};



/*
ai trust bi 
bi -> judge hoga....

iterate over trust if everyone;s second is same then return the same else return -1
// don't judge trust included....

koi ek dusre ko trust kare wo case nahi socha abhi
thought of superman intuition-> everyone touches superman and superman touches no one ....
i.e. if made graph of this by establishing relationship or connection 

if a given node is judge/superman -> then he must have n-1 indegree and 0 outdegree....
// same question as finding the celebrity..

// 1 based indexing ka dhyan rakhna direct index se compare karne ke liye...

// instead of creating the graph we can trace simply the create indegree of indegree and outdegree....
for [a,b] -> outdegree of a increases and indegree of b increases....

then finally check which one has indegree = n-1 && outdegree = 0


*/


/*
now reducing space complexity using single degree   because only possible case for 
degree to be n-1 = (n-1) - 0 
                    indegree - outdegree    and hence he is the judge himself...


*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust){
        vector <int> degree(n+1 , 0);

        for (auto v : trust){
            degree[v[0]]--;      // outdegree ke uss index pe rakhe element ko increase karega....
            degree[v[1]]++;
        }
        
        for (int i=1; i<=n; i++){
            if ( degree[i] == n-1 ) return i;
        }

        return -1;
    }
};



/*
ai trust bi 
bi -> judge hoga....

iterate over trust if everyone;s second is same then return the same else return -1
// don't judge trust included....

koi ek dusre ko trust kare wo case nahi socha abhi
thought of superman intuition-> everyone touches superman and superman touches no one ....
i.e. if made graph of this by establishing relationship or connection 

if a given node is judge/superman -> then he must have n-1 indegree and 0 outdegree....
// same question as finding the celebrity..

// 1 based indexing ka dhyan rakhna direct index se compare karne ke liye...

// instead of creating the graph we can trace simply the create indegree of indegree and outdegree....
for [a,b] -> outdegree of a increases and indegree of b increases....

then finally check which one has indegree = n-1 && outdegree = 0

-----your priority should be to optimise time first but try optimising space then 
because in case if memory(RAM) limit exceeds then it starts using disk space which is 
comparatively slower.....

*/






