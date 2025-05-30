#include <bits/stdc++.h>
using namespace std;


/*

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. 
Each CPU interval can be idle or allow the completion of one task. 
Tasks can be completed in any order, but there's a constraint: 
there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.


Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. 
The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. 
By the 4th interval, you can do A again as 2 intervals have passed.


Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. 
This leads to idling twice between repetitions of these tasks.


Constraints:

1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100

*/



class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {

        // ✅ Step 1: Frequency count of each task
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++; // A = index 0, B = index 1, ..., Z = index 25
        }

        // ✅ Step 2: Max-heap to process most frequent tasks first
        priority_queue <int> maxHeap;

        for (int f : freq) {
            if (f > 0) maxHeap.push(f); // Push only non-zero frequencies
        }

        int totalTime = 0;

        // ✅ Step 3: Process tasks in chunks of size (n + 1)
        // Because after executing a task, you have to wait n units before reusing it

        while (!maxHeap.empty()) {
            
            int cycle = n + 1;                // Fixed-size cycle
            vector <int> pendingTasks;         // To store tasks that are not finished yet

            // ✅ Fill the current cycle with available high-frequency tasks
            while (cycle > 0 && !maxHeap.empty()) {
                int freqTop = maxHeap.top(); maxHeap.pop();
                
                // Task performed, so reduce its frequency
                if (freqTop - 1 > 0) {
                    pendingTasks.push_back(freqTop - 1); // Will be scheduled again later
                }

                totalTime++;  // Time spent for executing a task
                cycle--;      // One slot of cycle used
            }

            // ✅ Push back remaining tasks for the next round
            for (int remFreq : pendingTasks) {
                maxHeap.push(remFreq);
            }

            // ✅ If heap is empty, no need to add idle time for the last cycle
            if (maxHeap.empty()) break;

            // ✅ If tasks remain, but cycle is incomplete, count idle time
            totalTime += cycle; // Idle slots (CPU remains idle in remaining cycle length)
        
        }

        return totalTime;
    }
};





/*

🔍 Intuition (in simple words):
Har task ke beech n time ka gap chahiye agar same task dobara karna ho.
So, hum ek (n + 1) sized window banate hain jisme maximum different tasks bharne ki koshish karte hain.


Sabse pehle frequent tasks ko complete karte hain using a max heap.
Agar kisi task ka frequency > 1 hai, toh usko pending rakhte hain 
aur next cycle mai dubara consider karte hain.


✅ Why n + 1?
Think of it like filling a row of n + 1 slots:

If a task is repeated, it must be placed at least n time apart, 
so you need n + 1 space to restart the same task again in the next row.

*/