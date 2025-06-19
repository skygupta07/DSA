// countMagicalPlantId.cpp

#include <bits/stdc++.h>
using namespace std;

bool hasFiveFactor(int x) {
    int count = 0;

    // Count factors of x
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            count++; // Count i as a factor
            if (i != x / i) count++; // Count x / i as a separate factor if it's different
        }
    }

    return (count == 5);
}

bool isPerfectSquare(int x) {
    int root = static_cast<int>(sqrt(x));
    return root * root == x;
}

bool isMagical(int x) {
    return hasFiveFactor(x) && isPerfectSquare(x);
}

std::pair<int, std::vector<int>> find_magical_ids(int n) {
    int count = 0;
    std::vector<int> magicalPlants;

    for (int i = 1; i <= n; i++) {
        if (isMagical(i)) {
            count++;
            magicalPlants.push_back(i);
        }
    }

    return {count, magicalPlants};
}

int main() {
    int N;
    std::cin >> N;

    auto result = find_magical_ids(N);
    std::cout << result.first << std::endl;

    for (int id : result.second) {
        std::cout << id << " ";
    }
    
    std::cout << std::endl;

    return 0;
}
