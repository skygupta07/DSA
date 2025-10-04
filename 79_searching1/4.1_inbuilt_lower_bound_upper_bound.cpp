#include <bits/stdc++.h>
using namespace std;


int main() {
    int arr[] = {1, 2, 4, 4, 4, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // lower_bound and upper_bound for value = 4
    auto lb = lower_bound(arr, arr + n, 4);  // first index >= 4
    auto ub = upper_bound(arr, arr + n, 4);  // first index > 4

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "lower_bound(4) is at index: " << (lb - arr) << endl;
    cout << "upper_bound(4) is at index: " << (ub - arr) << endl;

    return 0;
}


/*

🔹 1. lower_bound(first, last, value)

Returns an iterator (or pointer in case of arrays) pointing to the first element in the range 
[first, last) that is not less than (>=) the given value.

In other words:
If the value exists → gives the index of the first occurrence.
If the value doesn’t exist → gives the index where it can be inserted to keep the array sorted.


🔹 2. upper_bound(first, last, value)
Returns an iterator (or pointer) pointing to the first element in the range 
[first, last) that is greater than (>) the given value.

In other words:
If the value exists → gives the index of the first element greater than it.
If the value doesn’t exist → gives the index where it could be inserted after larger elements.

*/
