// maximizeTaskAllocation.cpp


#include <bits/stdc++.h>
using namespace std;


/*

You are given a set of tasks with specific energy requirements and a set of batteries 
with varying power capacities.

Each task can only be allocated to one battery, and each battery can only be used for one task.
Find the maximum number of tasks that can be completed by assigning each task 
to a compatible battery such that the task's energy requirement 
does not exceed the battery's power supply.


Input Format

The first line contains two space-separated integers N and M 
representing a number of tasks and the batteries respectively.
The second line contains N space-separated integers representing the energy requirements of the tasks.
The third line contains M space-separated integers representing the power supplies of the batteries


Output Format

Print an integer representing the maximum number of tasks that can be completed.

 
Constraints
1 <= N, M <= 20

Values in both arrays can be range from 1 to 1000.

Sample Testcase 0

Testcase Input
3 3
5 3 7
4 6 2

Testcase Output
2


Explanation

We have 3 tasks and 3 batteries. Given the enegy requirements of each task and power supply 
of each batteries : 

Only Task 1 and task 2 can be completed using batteries of power 6 and 4 respectively. 
Task 3 needed 7 power of energy which can not be fulfilled by available batteries.

*/

int maximizeTasks(vector <int> &energy, vector <int> &power) {

    int count = 0;

    for(int i=0; i<energy.size(); i++){

        for(int j=0; j<power.size(); j++){

            if(energy[i] <= power[j]){
                count++;
                break;
            }
        }
    }
    
    return ( energy.size() > power.size() ) ? (count - 1) : count;
}



int main() {
    int n, m;
    cin >> n >> m;

    vector<int> energy(n);
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }

    vector<int> power(m);
    for (int i = 0; i < m; i++) {
        cin >> power[i];
    }

    int maxTasks = maximizeTasks(energy, power);
    cout << maxTasks << endl;

    return 0;
}

