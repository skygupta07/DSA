// binarySearch.cpp


#include <bits/stdc++.h>
using namespace std;

int main() {
    // Vector banaya, bina size diye kyunki hum push_back se elements daal rahe hain
    vector <int> v;

    // Vector me kuch elements insert kiye using push_back
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);
    v.push_back(10);
    v.push_back(15);
    v.push_back(18);
    v.push_back(50);

    // Binary Search tabhi kaam karega jab array sorted ho
    // Isliye pehle vector ko sort kar lo (ascending order me)
    sort(v.begin(), v.end());

    // Sorted vector print kar rahe hain
    cout << "Sorted vector: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Binary Search ke liye low aur high index define kiya
    int lo = 0;
    int hi = v.size() - 1;

    // User se target element input liya jo search karna hai
    int target;
    cout << "Enter the element you want to search: ";
    cin >> target;

    // Binary Search loop
    while (lo <= hi) {
        // Mid calculate kar rahe hain in a safe way to avoid overflow
        int mid = lo + (hi - lo) / 2;

        // Middle element ko compare karo target se
        if (v[mid] == target) {
            // Agar mil gaya to index return karo
            cout << "Element found at index (0-based): " << mid << endl;
            return 0;
        }
        else if (v[mid] < target) {
            // Agar mid wala element chhota hai target se, to right half me jao
            lo = mid + 1;
        }
        else {
            // Agar mid wala element bada hai target se, to left half me jao
            hi = mid - 1;
        }
    }

    // Agar loop ke baad bhi element nahi mila to -1 print karo
    cout << "Element not found in the array." << endl;
    return -1;
}
