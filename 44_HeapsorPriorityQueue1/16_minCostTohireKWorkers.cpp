#include <bits/stdc++.h>
using namespace std;


/*

There are n workers. You are given two integer arrays quality and wage where 
quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation 
for the ith worker.

We want to hire exactly k workers to form a paid group. 
To hire a group of k workers, we must pay them according to the following rules:

Every worker in the paid group must be paid at least their minimum wage expectation.
In the group, each worker's pay must be directly proportional to their quality. 
This means if a worker’s quality is double that of another worker in the group, 
then they must be paid twice as much as the other worker.

Given the integer k, return the least amount of money needed to form a paid group 
satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.

 
Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.


Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
 

Constraints:

n == quality.length == wage.length
1 <= k <= n <= 104
1 <= quality[i], wage[i] <= 104

 */


class Solution {
public:

    double mincostToHireWorkers(vector <int> &q, vector <int> &w, int k) {
        vector <pair <double, int>> workers;

        // ✅ Step 1: Create a vector of {wage/quality ratio, quality}
        for (int i = 0; i < q.size(); i++) {
            workers.push_back({ (double)w[i]/q[i], q[i]} );
            // w[i]/q[i] -> "bechara ratio" (minimum wage per quality unit that this worker demands)
        }

        // ✅ Step 2: Sort workers based on their wage/quality ratio (ascending) - kam dihadi wala pehle aayega..
        sort(workers.begin(), workers.end());

        // ✅ Initialize answer to a large value
        double ans = DBL_MAX;

        // ✅ Keep track of sum of qualities of selected workers
        double qSum = 0;

        // ✅ Max Heap to always remove the worker with the highest quality 
        // (because that increases total cost)
        priority_queue <int> pq;


        // ✅ Step 3: Traverse workers (sorted by increasing ratio)
        for (const auto &worker : workers) {
            double ratio = worker.first;       // Current worker's min wage per quality unit
            int quality = worker.second;

            // 🧮 Add this worker’s quality to our running sum
            qSum += quality;
            pq.push(quality);

            // ❌ If more than k workers, remove the one with the highest quality to minimize cost
            if (pq.size() > k) {
                qSum -= pq.top();
                pq.pop();
            }

            // ✅ If we have exactly k workers, calculate the cost
            
            if (pq.size() == k) {
                // Total cost = total quality sum * max ratio among selected workers
                // Because all workers must be paid *at least* their ratio * quality
                ans = min(ans, qSum * ratio);
            }
        }

        return ans; // Minimum cost to hire k workers under fair payment rule
    }
};


/*

🧠 Intuition:

Har worker ka minimum acceptable wage hota hai, jo hota hai w[i]/q[i]. Isko bolte hain wage-to-quality ratio.
Agar kisi ek worker ka ratio r hai, aur uske sath k-1 aur workers hire karne hain:
Sabko kam se kam r * quality dena padega to satisfy fairness.
So, cost ban jaata hai: r * (sum of all qualities)
Isliye, har ratio ke saath check karte jao ki agar yeh max ratio ho to uske according minimum k logon ki quality ka sum kya hoga.


✅ Priority Queue Use:
priority_queue (max heap) is used to maintain k workers with lowest possible total quality (since total cost depends on quality * ratio).
Jaise hi k+1 workers ho jaate hain, sabse zyada quality wale ko hata dete hain to minimize cost.

*/
