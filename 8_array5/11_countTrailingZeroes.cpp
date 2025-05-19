#include <bits/stdc++.h>
using namespace std;


/*
The trailing zeros in a number's factorial are determined by the number of factors of 5 (and 2) 
in the factorial. Since there are always more factors of 2 than 5, counting the factors of 5 suffices.(limiting reagent)
For a number n, the count of factors of 5 in n! can be calculated as:

*/

// Function to count trailing zeros in n!
int countTrailingZeros(int n) {
    int count = 0;
    while (n > 0) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

// Main function
int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }
    
    // Calculate the sum of trailing zeros for valid numbers
    long long totalTrailingZeros = 0;
    for (int i = 0; i < N; ++i) {
        if (numbers[i] <= M) {
            totalTrailingZeros += countTrailingZeros(numbers[i]);
        }
    }
    
    cout << totalTrailingZeros << endl;
    return 0;
}
