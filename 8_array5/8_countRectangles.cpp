#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// jis tarah number ko negative karne ke liye (-1) se multiply kar sakte h... theek usi tarah
// number ko long long banane ke liye (1LL) se multiply karte h...


int countRectangles(int N) {
    // Total rectangles in the chessboard
    long long totalRectangles = (1LL * N * (N + 1) / 2) * (1LL * N * (N + 1) / 2);

    // Total squares in the chessboard
    long long totalSquares = 1LL * N * (N + 1) * (2 * N + 1) / 6;

    // Rectangles excluding squares
    return totalRectangles - totalSquares;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << countRectangles(N) << endl;
    }
    
    return 0;
}



/*

A simple approach to solve this problem is to find the total number of possible rectangles, including squares, and then subtract the number of possible squares.
We can easily determine the total number of rectangles if we think of a rectangle as a pair of horizontal lines and a pair of vertical lines, intersecting at four points.
The given board will have (N+1) horizontal and (N+1) vertical lines.
So, the total number of rectangles (including squares) would be the number of ways to choose two distinct horizontal lines and two distinct vertical lines.
This can be found by using combinations as: (N + 1)C2 * (N + 1)C2, where ‘C’ stands for combination. This is equal to (N * (N + 1) / 2) * (N * (N + 1) / 2) = (N * (N + 1) / 2) ^ 2
Now, to determine the number of possible squares, we try to determine the pattern between the dimension of the square and the number of such squares present in the N x N board.
Number of squares with dimension 1x1 = N^2
Number of squares with dimension 2x2 = (N - 1)^2
Number of squares with dimension 3x3 = (N - 2)^2
And so on, till number of squares with dimension NxN = (N - (N-1))^2 = 1^2
Adding the above values, we get total number of possible squares in a N x N board = 1^2 + 2^2 + ……. (N-1)^2 + N^2 = N * (N + 1) * (2 * N + 1) / 6 (using the formula for sum of the squares of first ‘N’ natural numbers).
Therefore, the number of rectangles (excluding squares) = (N*(N+1)/2)^2 - (N*(N + 1)*(2*N + 1)/6). This can be easily calculated in constant time.



*/