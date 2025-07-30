// maximumConsecutiveTasks.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given N tasks to complete in a day, each having a fixed duration. 
These durations are provided in an array tasks[], 
where tasks[i] represents the time required to complete the i-th task in minutes. 

Additionally, you are given a total available time T (in minutes).

Your task is to return outputs while analyzing the maximum number of consecutive tasks 
that can be completed within T minutes.

Input Format

The first line contains an integer N, representing the number of tasks.
The second line contains N space-separated integers, 
where the i-th integer represents the duration of the i-th task in minutes.

The third line contains an integer T, representing the total available time in minutes.

Output Format

Print a single integer representing the maximum number of consecutive tasks 
that can be completed within T.

Constraints

1 ≤ N ≤ 10^5
1 < tasks[i] < 10^4
1 < T < 10^7

Sample Testcase 0

Testcase Input
6
1 2 3 4 5 6
10

Testcase Output
4

Explanation

We have N = 6 tasks with durations [1, 2, 3, 4, 5, 6].


The available time T = 10 minutes.
The longest sequence of consecutive tasks that fit within T is [1, 2, 3, 4] (sum = 10).
Maximum consecutive tasks: 4

Sample Testcase 1

Testcase Input
5
5 1 2 6 3
7

Testcase Output
2

Explanation

We have N = 5 tasks with durations [5, 1, 2, 6, 3].
The available time T = 7 minutes.
The longest sequence of consecutive tasks that fit within T is [5, 1] (sum = 6) 
Maximum consecutive tasks: 2

*/

void user_logic(int n, vector<int>& tasks, int T, int& max_tasks, vector<int>& subarray, int& sum_durations) {
    // two pointer starting both from starting...
    int left = 0, right = 0;
    int sum = 0, maxLen = 0;
    int startIdx = 0;  // To track the starting index of the longest valid subarray

    while (right < n) {
        // in general first include sum...
        sum += tasks[right];
        
        // adjust window
        while (sum > T && left <= right) {
            sum -= tasks[left];
            left++;
        }
        
        // if current window length is greater than previous seen window length.. then update maxLen
        if (right - left + 1 > maxLen) {
            maxLen = right - left + 1;
            
            startIdx = left;
            sum_durations = sum;  // Store the sum of the longest valid subarray
        }

        right++;
    }

    max_tasks = maxLen;

    // just for safety before wearing sleepers... just remove the dust...
    subarray.clear();
    
    if (maxLen > 0) {
        for (int i = startIdx; i < startIdx + maxLen; i++) {
            subarray.push_back(tasks[i]);
        }
    }
}


int main() {
    int n, T;
    cin >> n;
    vector<int> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }
    cin >> T;
    
    int max_tasks = 0;
    vector<int> subarray;
    int sum_durations = 0;
    
    user_logic(n, tasks, T, max_tasks, subarray, sum_durations);
    
    cout << max_tasks << endl;
    
    return 0;
}
