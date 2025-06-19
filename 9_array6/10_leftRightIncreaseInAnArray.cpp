// leftRightIncreaseInAnArray.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Problem Statement

There are N elements in an array. 
All the elements have their initial values, and their values increase with an element 
having a non-zero value increasing the value of surrounding elements by 2 each day.

For example, if the value of the ith element is non-zero, then the value of (i−1)th element 
will get incremented by 2 as well the value of (i+1)th element will get incremented by 2 (if they exist).

Let's call the initial day, day 0. And after that, each consecutive will be referred to as day 1, day 2, 
and so on.

Now you have to find the total extra value of all elements that would have been increased on day P 
compared to day 0.

Input Format

The first line contains two space seperated integers, N and P, 
representing the size of the array and the Pth day.
The second line contains N space seperated integers representing elements of the array.

Output Format

A single integer represents the total extra value of all elements that would have been 
increased on day P compared to day 0.

Constraints

1 <= N, P <= 10^5.
0 <= A[i] <= 10^5.


Sample Testcase 0

Testcase Input
1 7
10

Testcase Output
0

Explanation

There is no neighbor, so the value will not increase.


Sample Testcase 1

Testcase Input
5 2
0 5 0 4 0

Testcase Output
24

Explanation

Day 0 -> [0,5,0,4,0] Total Value is 9
Day 1 -> [2,5,4,4,2] Total Value is 17
Day 2 -> [4,9,8,8,4] Total Value is 33

Note that from day 0 to day 1, for element 3, 2 will be increased due to element 2, 
and 2 will be increased due to element 4. Hence total of 4 will be added.
Hence the total extra value will be 33−9 = 24

*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> current = arr;
    vector<int> next(N, 0);

    long long initialSum = accumulate(arr.begin(), arr.end(), 0LL);
    long long totalSum = initialSum;

    for (int day = 0; day < P; day++) {
        
        fill(next.begin(), next.end(), 0);
        
        for (int i = 0; i < N; i++) {
            if (current[i] > 0) {
                if (i - 1 >= 0) next[i - 1] += 2;
                if (i + 1 < N) next[i + 1] += 2;
            }
        }

        for (int i = 0; i < N; i++) {
            current[i] += next[i];
            totalSum += next[i];
        }
    }

    cout << totalSum - initialSum << endl;
    return 0;
}