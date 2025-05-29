// jobSequencingProblem.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given three arrays id[], deadline[], profit[], where each job i is associated with id[i], 
deadline[i], and profit[i]. Each job takes 1 unit of time to complete, 
and only one job can be scheduled at a time. You will earn the profit associated
with a job only if it is completed by its deadline. 
The task is to find the maximum profit that can be gained by completing the jobs 
and the count of jobs completed to earn the maximum profit.

Examples: 

Input: id[] = [1, 2, 3, 4]
deadline[] = [4, 1, 1, 1]
profit[] = [20, 10, 40, 30]
Output: 2 60
Explanation: All jobs other than the first job have a deadline of 1, 
thus only one of these and the first job can be completed, 
with the total profit gain of 20 + 40 = 60.


Input: id[] = [1, 2, 3, 4, 5]
deadline[] = [2, 1, 2, 1, 1]
profit[] = [100, 19, 27, 25, 15]

Output: 2 127
Explanation: The first and third job have a deadline of 2,
thus both** of them can be completed and other jobs have a deadline of 1, 
thus any one of them can be completed. Both the jobs with a deadline of 2 
is having the maximum associated profit, so these two will be completed, 
with the total profit gain of 100 + 27 = 127.

*/

// Job structure jo har ek job ka ID, deadline aur profit store karega
struct Job {
    int id;       // Job ID
    int deadline; // Job ki deadline
    int profit;   // Agar deadline se pehle complete ho to kitna profit milega
};

class Solution {
public:
    // Comparator function jo jobs ko descending order me sort karega profit ke basis pe
    static bool cmp(Job j1, Job j2) {
        return j1.profit > j2.profit; // Bade profit wale ko pehle rakhne ke liye
    }

    vector<int> JobScheduling(Job jobs[], int n) {
        // Pehle jobs ko profit ke descending order me sort karenge
        sort(jobs, jobs + n, cmp);

        // Sabse badi deadline find kar rahe hain taaki utne slots allocate kar sakein
        int maxDeadline = 0;
        
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].deadline);
        }

        // Slot array bana rahe hain, jo track karega ki kaunsa time slot available hai
        vector <bool> slots(maxDeadline + 1, false);

        int jobCount = 0, maxProfit = 0;

        // Sorted jobs pe iterate karenge
        for (int i = 0; i < n; i++) {
            // Har job ke liye uski deadline se peeche aate hue check karenge 
            // {engineers ki tarah ekdum end deadline jaha possible hogi waha completer karenge kaam ko or in 
            // in other words allocate karenge slot ko....}
            for (int j = jobs[i].deadline; j > 0; j--) {
                if (!slots[j]) { // Agar slot khali hai to waha job dal do
                    slots[j] = true;
                    jobCount++; // Job count badh gaya

                    maxProfit += jobs[i].profit; // Profit update kar diya
                    break; // Job assign ho gayi, ab agla job dekho
                }
            }
        }

        // Total jobs complete aur max profit return kar rahe hain
        return {jobCount, maxProfit};
    }
};

// Driver Code
int main() {
    int t;
    cin >> t; // Test cases input le rahe hain

    while (t--) {
        int n;
        cin >> n;
        Job arr[n];

        // Input jobs ke details le rahe hain
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i] = {x, y, z};
        }

        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        
        // Output: kitni jobs complete hui aur maximum profit kitna mila
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
