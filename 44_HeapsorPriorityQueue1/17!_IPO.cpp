#include <bits/stdc++.h>
using namespace std;

/*

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital,
LeetCode would like to work on some projects to increase its capital before the IPO. 
Since it has limited resources, it can only finish at most k distinct projects before the IPO. 

Help LeetCode design the best way to maximize its total capital after finishing
at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] 
and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, 
you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, 
and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.


Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.

Since you can choose at most 2 projects, 
you need to finish the project indexed 2 to get the maximum capital.

Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.


Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6
 


Constraints:

1 <= k <= 10pow5
0 <= w <= 10pow9
n == profits.length
n == capital.length
1 <= n <= 10pow5
0 <= profits[i] <= 10pow4
0 <= capital[i] <= 10pow9

*/


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // ✅ Step 1: Pair every project with its capital requirement
        vector<pair<int, int>> projects;  // {capital_needed, profit}

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // ✅ Step 2: Sort all projects by required capital in ascending order
        sort(projects.begin(), projects.end());

        // ✅ Max heap to store profits of projects we can currently afford
        priority_queue <int> pq;

        int totalCapital = w;  // Initially we have `w` amount
        int j = 0;             // Index for projects that are affordable so far

        // ✅ We can do at most 'k' projects
        for (int i = 0; i < k; i++) {
            
            // 🔁 Add all projects whose required capital <= current capital
            while (j < n && projects[j].first <= totalCapital) {
                pq.push(projects[j].second);  // Push profit into max heap
                j++;
            }

            // ❌ If no project is affordable at this stage, break early
            if (pq.empty()) break;

            // ✅ Pick the project with maximum profit (greedy choice)
            totalCapital += pq.top();  // Increase our capital by the profit
            pq.pop();                  // Remove that project from heap
        }

        return totalCapital;  // Return the maximized capital after up to k projects
    }
};


// try consuming less capital and gaining more profit for a given capital...
// jiska kaam ho jaega usko heap se nikal dunga....
// and now ab itne profit mai jitne kharidne layak ban gya hu to unhe daal dunga....

/*


Greedy approach: Har step pe maximum profit wala project uthate ho from the pool of currently affordable ones.
Heap (Max Heap): Kyunki hume highest profit chahiye out of affordable projects.
Sorting: Taaki hum quickly dekh sakein ki ab tak kaunse projects affordable hain (capital <= currentCapital).
Priority Queue Logic:
Jab bhi naye paisa aaye, check karo ab kaunse naye projects afford ho gaye.
Jo kaam ho gaya (profit mil gaya), usko heap se hata do.

*/