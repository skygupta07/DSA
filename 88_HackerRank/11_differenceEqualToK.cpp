#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int pairs(int k, vector<int>& arr) {
    unordered_set<int> elements(arr.begin(), arr.end());
    int count = 0;
    
    for (int num : arr) {
        if (elements.find(num + k) != elements.end()) {
            count++;
        }
        if (elements.find(num - k) != elements.end()) {
            count++;
        }
        // Remove the element from the set to avoid counting duplicates
        elements.erase(num);    // set se to remove karte hi chalo...har step mai
        // jise k wala contribution dena hoga....wo upar hi count increase kar chuka hoga...
    }
    
    return count;
}