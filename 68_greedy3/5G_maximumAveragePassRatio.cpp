// maximumAveragePassRatio.cpp

/*

There is a school that has classes of students and each class will be having a final exam. 
You are given a 2D integer array classes, where classes[i] = [passi, totali]. 
You know beforehand that in the ith class, there are totali total students, 
but only passi number of students will pass the exam.

You are also given an integer extraStudents. 
There are another extraStudents brilliant students that are guaranteed to pass the exam of any class 
they are assigned to. You want to assign each of the extraStudents students to a class 
in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam 
divided by the total number of students of the class. The average pass ratio is 
the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. 
Answers within 1e-5 of the actual answer will be accepted.


Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2

Output: 0.78333
Explanation: You can assign the two extra students to the first class.
The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.


Example 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485
 

Constraints:

1 <= classes.length <= 1e5
classes[i].length == 2
1 <= passi <= totali <= 1e5
1 <= extraStudents <= 1e5

*/


// interviews

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ✅ Intuition behind this helper function:
    // Jab bhi kisi class mein ek extra brilliant student assign karte hain,
    // toh us class ki pass ratio improve hoti hai.
    //
    // Hum ye measure karna chahte hain ki "kitna zyada improvement hoga"
    // i.e., gain = new pass ratio - old pass ratio

    double getGain(int pass, int total) {
        // Example:
        // If class = [3, 5], current pass ratio = 3/5 = 0.6
        // After adding a passing student: [4, 6], new ratio = 4/6 = 0.666...
        // So gain = 0.666 - 0.6 = 0.0666

        // Brackets ka dhyan rakhna zaroori hai (double type ke saath integer divide mat hone do)
        return ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
    }

    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {

        // ✅ Intuition:
        // Har extra student ko us class mein daalo jahan usse maximum benefit milega
        // Yaani jahan pass ratio sabse zyada increase hogi

        // 👉 To implement this greedily, we use a Max-Heap (Priority Queue)
        // Max heap will always give us the class with the highest "gain" on top

        // Heap format: {gain, {pass, total}} — gain ko descending order mein arrange karega
        priority_queue<pair<double, pair<int, int>>> pq;

        // Step 1: Sabhi classes ka current gain calculate karo aur heap mein daalo
        for (const auto &cls : classes) {
            int pass = cls[0];   // students who passed
            int total = cls[1];  // total students

            double gain = getGain(pass, total); // abhi ek student add karoge to kitna gain hoga?

            pq.push({gain, {pass, total}});
        }

        // Step 2: Har extra student ko greedily best class mein daalo
        while (extraStudents--) {

            // Step 2.1: Heap se top class nikaalo (jisme gain sabse zyada hoga)
            auto [gain, classInfo] = pq.top();
            pq.pop();

            int pass = classInfo.first;
            int total = classInfo.second;

            // Step 2.2: Ek brilliant student assign karo
            pass += 1;
            total += 1;

            // Step 2.3: Nayi gain calculate karo
            double newGain = getGain(pass, total);

            // Step 2.4: Updated class ko dobara heap mein daal do
            pq.push({newGain, {pass, total}});
        }

        // Step 3: Ab sabhi updated classes se final average calculate karo
        double totalAverage = 0.0;

        while (!pq.empty()) {
            auto [gain, classInfo] = pq.top();  // gain ignore kar sakte ho ab
            pq.pop();

            int pass = classInfo.first;
            int total = classInfo.second;

            // Total pass ratio accumulate karo
            totalAverage += (double)pass / total;
        }

        // Step 4: Average nikaalo — sum of pass ratios / number of classes
        return totalAverage / classes.size();
    }
};



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    // Function to calculate the 'gain' in pass ratio if we add one more passing student
    // Yeh basically difference batata hai between the new pass ratio and the current pass ratio
    double getGain(int pass, int total) {
        // New pass ratio after adding one passing student
        // Formula: (pass + 1) / (total + 1)
        // Gain = newRatio - oldRatio
        
                                                    // yaha pass / total ko bracket mai nahi likhna.. 
        // wahi double ko dikkat hone lagti h divison wale case mai.. pata nahi kyu bc
        return ( (double)(pass + 1) / (total + 1) ) - ( (double)pass / total );
    }


    double maxAverageRatio(vector <vector<int>> &classes, int extraStudents) {
        // Max-heap banate hain, jisme sabse upar wo class hogi jisme ek extra student 
        // add karne se max benefit (gain) milega
        
        // Heap ke andar: {gain, {pass, total}}
        priority_queue <pair <double, pair <int, int>>> pq;

        // Step 1: Sabhi classes ko heap mein daal do with their current gain
        
        for (const auto &cls : classes) {

            int pass = cls[0];     // Number of students who passed
            int total = cls[1];    // Total students in the class
            
            double gain = getGain(pass, total);  // Calculate gain for this class

            pq.push({gain, {pass, total}});  // Push in heap
        }

        // Step 2: Har extra student ko greedily assign karo us class ko jahan max gain mile
        while (extraStudents--) {
            
            // Heap se top class nikaalo — jisme ek aur student add karne se sabse zyada improvement milega
            auto [gain, classInfo] = pq.top();
            pq.pop();

            int pass = classInfo.first;
            int total = classInfo.second;

            // Ek extra student add karne ka matlab: pass bhi +1, total bhi +1
            pass += 1;
            total += 1;

            // Update hone ke baad new gain calculate karo
            double newGain = getGain(pass, total);

            // Heap mein dobara push karo updated value ke saath
            pq.push({newGain, {pass, total}});
        }

        // Step 3: Ab final average calculate karo
        double totalAverage = 0.0;

        while (!pq.empty()) {
            // Heap se sabhi elements nikaal ke average nikaalte hain
            auto [gain, classInfo] = pq.top();  // Gain ki zarurat nahi hai ab... chalo koi na tab bhi nikal lo..
            pq.pop();

            int pass = classInfo.first;
            int total = classInfo.second;

            // Average ratio: pass / total
            totalAverage += (double)pass / total;
        }

        // Final answer = total average divided by number of classes
        return totalAverage / classes.size();
    }

};
