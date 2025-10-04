#include <bits/stdc++.h>
using namespace std;


int main() {
    
    // Sorted array diya gaya hai
    int arr[] = {1, 3, 5, 7, 10, 12, 15, 18, 20, 22, 26, 30};

    int n = sizeof(arr) / sizeof(arr[0]);  // n = 12

    int target = 19;  // jis element ka lower/upper bound find karna hai

    // ✅ Binary search based upper_bound and lower_bound using STL:
    // lower_bound -> first element which is >= target
    // upper_bound -> first element which is > target

    // Inbuilt STL function ka use kiya for better efficiency and clarity
    auto lb = lower_bound(arr, arr + n, target);  // returns pointer
    auto ub = upper_bound(arr, arr + n, target);

    // lb/ub are pointers, so index nikalne ke liye base pointer subtract karna padega
    int lbIndex = lb - arr;
    int ubIndex = ub - arr;

    cout << "Target element: " << target << endl;

    // Lower Bound Result
    if (lbIndex < n) {
        cout << "Lower Bound (>= target): " << arr[lbIndex] << " at index " << lbIndex << endl;
    } 
    
    else {
        cout << "Lower Bound not found (target greater than all elements)" << endl;
    }

    // Upper Bound Result
    if (ubIndex < n) {
        cout << "Upper Bound (> target): " << arr[ubIndex] << " at index " << ubIndex << endl;
    } 
    
    else {
        cout << "Upper Bound not found (target >= all elements)" << endl;
    }

    return 0;
}




/*

lower_bound(arr, arr+n, x)
→ Returns the first element which is ≥ x

upper_bound(arr, arr+n, x)
→ Returns the first element which is > x

*/