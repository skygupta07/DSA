// #include <bits/stdc++.h>
// using namespace std;

// // Placeholder for user logic
// float calculate_distance(const std::vector<std::pair<int, int>>& creatures) {
//     // Write your logic here
//     float min = FLT_MAX, minIdx = -1, max = FLT_MIN, maxIdx = -1;
//     for(int i = 0; i < creatures.size(); i++){
//         int x = creatures[i].first;
//         int y = creatures[i].second;
//         float dist = sqrt((x * x) + (y * y));
//         if(dist > max){
//             max = dist;
//             maxIdx = i;
//         }
//         if(dist < min){
//             min = dist;
//             minIdx = i;
//         }
//     }
//     if(minIdx != -1 && maxIdx != -1){
//         int x1 = creatures[maxIdx].first;
//         int y1 = creatures[maxIdx].second;
//         int x2 = creatures[minIdx].first;
//         int y2 = creatures[minIdx].second;
//         return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
//     }
//     return 0;
// }

// int main() {
//     int N;
//     std::cin >> N;
//     std::vector<std::pair<int, int>> creatures(N);

//     for (int i = 0; i < N; i++) {
//         std::cin >> creatures[i].first >> creatures[i].second;
//     }

//     // Call user logic function and print the output
//     float result = calculate_distance(creatures);
//     printf("%.5f\n", result);

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

// Function to calculate the Euclidean distance between two points
double calculate_distance(const vector<pair<int, int>>& creatures) {
    double min_distance = DBL_MAX, max_distance = DBL_MIN;
    int min_idx = -1, max_idx = -1;

    for (int i = 0; i < creatures.size(); i++) {
        int x = creatures[i].first;
        int y = creatures[i].second;
        double dist = sqrt(x * x + y * y);

        // Update minimum distance and its index
        if (dist < min_distance) {
            min_distance = dist;
            min_idx = i;
        }

        // Update maximum distance and its index
        if (dist > max_distance) {
            max_distance = dist;
            max_idx = i;
        }
    }

    if (min_idx != -1 && max_idx != -1) {
        int x1 = creatures[max_idx].first;
        int y1 = creatures[max_idx].second;
        int x2 = creatures[min_idx].first;
        int y2 = creatures[min_idx].second;

        // Calculate the Euclidean distance between the closest and farthest creatures
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    return 0; // This case should not occur as N >= 2
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> creatures(N);

    for (int i = 0; i < N; i++) {
        cin >> creatures[i].first >> creatures[i].second;
    }

    // Calculate and print the result with 5 decimal places
    double result = calculate_distance(creatures);
    printf("%.5f\n", result);

    return 0;
}