// frequently asked OA question

// jobSequencingProblem.cpp

/*

You are given two arrays: deadline[], and profit[], which represent a set of jobs, 
where each job is associated with a deadline, and a profit. 

Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. 
You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.


Examples :

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).


Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).



Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30)

*/

#include <bits/stdc++.h>
using namespace std;


class Solution { // gave tle
public:

      vector<int> jobSequencing(vector <int> &deadline, vector <int> &profit) {
          int n = deadline.size();
          
          // pata h sort karna h to better rehta h pehle joda bana lo..
          vector <pair <int, int>> jobs; // profit , deadline

          for (int i=0; i<n; i++) jobs.push_back({profit[i], deadline[i]});
          

            // maxProfit wala sabse pehle aajayega...
          sort(jobs.rbegin(), jobs.rend());


          // maxDeadline kya de rakhi h...uske hissab se room ya slot book honge..
          int maxDeadline = 0;
          for (int i=0; i<n; i++) maxDeadline = max(maxDeadline, jobs[i].second);
          
          // -1 indicates that slot or room is empty {DSA is all about pattern}
          vector <int> slot(maxDeadline + 1, -1);
          
          int countJobs = 0;
          int maxProfit = 0;
          
          // har job par gaye...
          for (int i=0; i<n; i++){

              int profit = jobs[i].first;
              int d = jobs[i].second;
              
              // engineers ki tarah ekdum kaam ko end moment par hi complete karo... isliye 
              // peeche se slots dekho..
              for (int j=d; j>0; j--){
                // agar jth slot free ho to 
                  if (slot[j] == -1){
                      slot[j] = i; // uss slot pe ith job assign kar di...
                      
                      countJobs++;
                      maxProfit += profit;
                      
                      break; //slot book ho gaya to chal chal bhai chal nikal le ab.. chal ab dusre job ko aane de..
                  }
              }
          }
          
          return {countJobs, maxProfit};
      }
  };
  

class Solution {
public:
  
    // DSU ka find function jo parent dhoondhne ke liye use hota hai
    int find(vector <int> &parent, int x){
        if (parent[x] == x) return x; // Agar apna hi parent hai toh return karo
        return parent[x] = find(parent, parent[x]); // Path compression ke saath parent update karte hue return
    }
  
      vector <int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          int n = deadline.size();
          vector <pair <int, int>> jobs; // (profit, deadline) pairs store karne ke liye
  
          // Sabhi jobs ko ek vector me store kar rahe hai
          for (int i=0; i<n; i++) jobs.push_back({profit[i], deadline[i]});
          
  
          // Jobs ko profit ke descending order me sort karenge
          sort(jobs.rbegin(), jobs.rend());
  
          int maxDeadline = 0; // Sabse bada deadline dhoondhne ke liye
  
          // Maximum deadline find kar rahe hain taaki slots allocate kar sakein
          for (int i=0; i<n; i++) maxDeadline = max(maxDeadline, jobs[i].second);
  
          // Parent array jo initially khud apne parent hai
          vector <int> parent(maxDeadline + 1);
          for (int i=0; i <= maxDeadline; i++) parent[i] = i;
  
          int countJobs = 0; // Kitni jobs schedule ho rahi hai
          int maxProfit = 0; // Total profit track karne ke liye
  
          // Har job ke liye try karenge ki use latest available slot me daal sakein
          for (int i=0; i<n; i++){
              int profit = jobs[i].first; // Current job ka profit
              int d = jobs[i].second; // Current job ka deadline
  
              // Check karo ki sabse late free slot kaunsa available hai
              int availableSlot = find(parent, d);
  
              // Agar slot available hai toh job assign karo
              if (availableSlot > 0){
                  countJobs++; // Job assign ho gayi
                  maxProfit += profit; // Profit update karo
  
                  // Parent ko update kar do, taki agli baar ye slot use na ho
                  parent[availableSlot] = find(parent, availableSlot - 1);
              }
          }
  
          return {countJobs, maxProfit}; // Job count aur max profit return karenge
      }
  };