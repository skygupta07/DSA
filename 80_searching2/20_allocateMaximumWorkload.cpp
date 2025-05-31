/*

you are given an array tasks[] of integers, where each element tasks[i] represents 
the time (in minutes) required to complete the i-th task. 
You also have an integer W representing the number of workers available. 
The task is to allocate tasks to each worker such that:

Each worker gets at least one task.
Each worker is assigned a contiguous sequence of tasks.
No task is assigned to more than one worker.

The objective is to maximize the minimum workload among all workers. 
In other words, find the allocation where the worker with the least workload gets the maximum possible
workload.

Input Format

An integer n denoting the number of tasks.

An array tasks[] of size N, where tasks[i] represents the time required for the i-th task.

An integer W representing the number of available workers.

--- Output Format ---- 

Print a single integer, which is the maximum possible minimum workload that a worker can have 
under an optimal task allocation.

Constraints

1 ≤ N ≤ 10^6

1 ≤ tasks[i] ≤ 10^3

1 ≤  W  ≤ 10^3

Sample Testcase 0

Testcase Input
4
20 30 40 50
2
Testcase Output
90

Explanation



Possible allocations:


[20, 30] & [40, 50] → Max pages = 90 ✅ (Optimal)

[20, 30, 40] & [50] → Max pages = 90



Minimum possible max pages = 90
*/

#include <bits/stdc++.h>
using namespace std;

/*
🔍 Problem Intuition:

Hume ek array diya gaya hai `tasks[]` jisme har element ek task ka time batata hai.
Aur ek integer `W` diya hai jo number of workers ko represent karta hai.

💡 Hume tasks ko is tareeke se distribute karna hai:
1. Har worker ko kam se kam ek task mile.
2. Har worker ko **contiguous (lagataar)** tasks assign hon.
3. Koi task kisi aur worker ke saath **share nahi** karega.

Objective: 
-> Sabse kam kaam karne wale worker ka workload **maximize** karna hai.
Yaane ki, "minimum workload among all workers ko maximum possible banana hai".

==> Ye **Book Allocation Problem** ka ek variation hai.
*/

// ✅ Check function: Kya given max workload ke saath k workers me allocation possible hai?
bool isPossible(vector<int>& arr, int n, int k, int maxPages) {
    int workerCount = 1;      // Ek worker se shuru karo
    int currentSum = 0;       // Har worker ka current workload

    for (int pages : arr) {
        // Agar current task milaake workload limit cross kar gaya
        if (currentSum + pages > maxPages) {
            workerCount++;        // Naye worker ko assign karo
            currentSum = pages;   // Naya worker apna kaam start karega
            if (workerCount > k)  // Agar workers zyada lag gaye to ye allocation possible nahi
                return false;
        } else {
            currentSum += pages;  // Otherwise current worker hi handle kare
        }
    }
    return true; // Agar sab tasks assign ho gaye k ya usse kam workers me to true return karo
}

// 📌 Binary Search approach to find optimal minimum workload (maximize the minimum)
int allocateBooks(vector<int> &arr, int k) {
    int n = arr.size();
    
    // Edge case: agar workers zyada hain aur tasks kam, to har kisi ko ek task nahi mil sakta
    //  - berojgaari at its peak

    if (k > n) return -1;

    // 📌 Binary Search boundaries:
    // Lower bound = sabse bada single task (kyunki koi worker usse kam to nahi le sakta)
    // Upper bound = total sum of tasks (worst case: 1 worker kare sab kuch)
    int lo = *max_element(arr.begin(), arr.end());
    int hi = accumulate(arr.begin(), arr.end(), 0);

    int result = hi;

    // 🔁 Binary Search
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Mid is current maximum workload limit

        // Agar ye workload limit ke andar kaam distribute ho sakta hai
        if (isPossible(arr, n, k, mid)) {
            result = mid;       // Store current result (may be this is our answer)
            hi = mid - 1;       // Try to find even better (lesser) maximum workload
        } 
        else {
            lo = mid + 1;       // Nahi ho paaya to workload badhao
        }
    }

    return result; // 🔚 Final optimized minimum workload jo maximize karta hai min. worker load
}

int main() {
    int n;
    cin >> n; // Number of tasks
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i]; // Task durations
    int k;
    cin >> k; // Number of workers

    cout << allocateBooks(arr, k) << endl; // Print the answer
    return 0;
}
