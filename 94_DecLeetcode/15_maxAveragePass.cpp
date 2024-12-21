#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Custom comparator for max-heap
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max-heap using the gain as the priority
        priority_queue<pair<double, pair<int, int>>> pq;

        // Initialize the heap with all classes
        for (const auto& cls : classes) {
            int pass = cls[0];
            int total = cls[1];
            pq.push({gain(pass, total), {pass, total}});
        }

        // Allocate extra students
        while (extraStudents--) {
            auto [currentGain, classInfo] = pq.top();
            pq.pop();

            int pass = classInfo.first;
            int total = classInfo.second;

            // Add one student and push the updated class back
            pq.push({gain(pass + 1, total + 1), {pass + 1, total + 1}});
        }

        // Calculate the final average pass ratio
        double totalAverage = 0.0;
        while (!pq.empty()) {
            auto [_, classInfo] = pq.top();
            pq.pop();

            int pass = classInfo.first;
            int total = classInfo.second;

            totalAverage += (double)pass / total;
        }

        return totalAverage / classes.size();
    }
};
