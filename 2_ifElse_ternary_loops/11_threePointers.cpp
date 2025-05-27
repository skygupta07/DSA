#include <bits/stdc++.h>
using namespace std;

/*

You are given three arrays X, Y and Z of size A,B and C respectively.
Also, all three arrays are sorted in non-decreasing order. 
Find i, j, k such that : 0 <= i < A, 0 <= j < B, 0 <= k < C 

and max(abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i])) is minimized. 
Your task is to return the minimum of all the 

max( abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i]) )


Note:
1. All the arrays are sorted in non-decreasing order.
2. abs(x) denotes the absolute value of x, i.e. if x<0, 
the abs function returns (-x) so that the final value of x becomes positive.

Detailed explanation ( Input/output format, Notes, Images )


Constraints:
1 <= T <=  100
1 <= A,B,C <= 10^4
1 <= X[i] <= 10^4
1 <= Y[i] <= 10^4
1 <= Z[i] <= 10^4

Time Limit: 1 sec


Sample Input 1:
1
5
1 2 3 4 5
5
1 3 5 7 9
3
2 4 6
Sample Output 1:
1 
Explanation for Sample Input 1:
For firstestcase :
One of the possible answer is choose i = 0, j = 0 and k = 1.
Thus it will 1 answer.


Sample Input 2:
1
4
1 1 1 1
4
2 2 2 2
5
7 7 7 7 7
Sample Output 2:
6


*/

int threePointer(vector<int>& X, vector<int>& Y, vector<int>& Z) {
    int i = 0, j = 0, k = 0; // Pointers for X, Y, Z
    
    int a = X.size(), b = Y.size(), c = Z.size();

    int min_difference = INT_MAX;

    while (i < a && j < b && k < c) {
        int current_max = max({abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i])});
        min_difference = min(min_difference, current_max);

        // Increment the pointer of the smallest element only amongst the three...
        if (X[i] <= Y[j] && X[i] <= Z[k]) i++;
        else if (Y[j] <= X[i] && Y[j] <= Z[k]) j++;
        else k++;
    }

    return min_difference;
}

