#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};


// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution {
  public:
  // const nahi chala to static bool cmp laga diya...
  static bool cmp(Job j1, Job j2){
      return j1.profit > j2.profit;
  }
  
  
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job jobs[], int n) {
        sort(jobs, jobs + n, cmp);

        int maxiDeadline = 0;
        
        for (int i=0; i<n; i++){
            maxiDeadline = max(maxiDeadline, jobs[i].deadline);
        }
        
        vector <int> slots(maxiDeadline + 1, -1);
        int jobCount = 0;
        int maxiProfit = 0;
            
        // iterate on all sorted jobs
        for (int i=0; i<n; i++){
            // picking deadline from end.. do it on end... 
            // agar repeated hoga to wahi nahi aaega.. first wala 
            // max profit leke aage walo ko chhod diya...
            for (int j=jobs[i].deadline; j>0; j--){
                if (slots[j] == -1){
                    slots[j] = jobs[i].id;
                    jobCount++;
                    maxiProfit += jobs[i].profit;
                    break;
                }
            }
        }
        
        return {jobCount, maxiProfit};
    }
};


/*
sort jobss on basis of profit in desc order -> max profit first.
int jobcount, int maxProfit.

sorted jobs array par iterate kara....and deadline ko back se approach 
kara agar slot free hai to slot mai uski id bhar ke profit wagere update kara 
finally return {jobCount, maxiProfit}

*/

//{ Driver Code Starts.
//    Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].deadline = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends