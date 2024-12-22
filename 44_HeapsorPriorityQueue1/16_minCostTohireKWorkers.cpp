#include <bits/stdc++.h>
using namespace std;


/*
There are n workers. You are given two integer arrays quality and wage where quality[i]
is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
We want to hire exactly k workers to form a paid group. To hire a group of k workers, 
we must pay them according to the following rules:

Every worker in the paid group must be paid at least their minimum wage expectation.
In the group, each worker's pay must be directly proportional to their quality. 
This means if a worker’s quality is double that of another worker in the group, 
    then they must be paid twice as much as the other worker.
Given the integer k, return the least amount of money needed to form a paid group satisfying
 the above conditions. Answers within 10-5 of the actual answer will be accepted.
*/


class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        vector <pair<double,int>> workers;

        for (int i=0; i<q.size(); i++){
            workers.push_back({ w[i]*1.0 /q[i] , q[i]}); 
                                // bechara ratio, quality
        }

        // wbyq is ratio of bechara...
        sort(workers.begin() , workers.end());

        double ans = DBL_MAX;
        double qSum = 0;

        priority_queue <int> pq;

        for (auto worker : workers){
            double ratio = worker.first;
            qSum += worker.second;
            pq.push(worker.second);

            if (pq.size() > k) qSum -= pq.top() , pq.pop();
            if (pq.size() == k) ans = min(ans, qSum*ratio);
        }
        return ans;
    }
};

/*
jab bhi kmin ya kmax nikalne ki baat aati hai to priority_queue socha..

*/
