#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    
    int count0 = 0, count1 = 0;
    for (char c : a) {
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }
    
    bool possible = false;
    
    // Check if there's a running series of zeroes surrounded by ones
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == '0' && a[i - 1] == '1' && a[i + 1] == '1') {
            possible = true;
            break;
        }
    }

    // Check the edges if the sequence starts or ends with '0'
    if (!possible) {
        if (a[0] == '0' && n > 1 && a[1] == '1') {
            possible = true;
        }
        if (a[n - 1] == '0' && n > 1 && a[n - 2] == '1') {
            possible = true;
        }
    }
    
    // Check if number of ones is greater than the number of zeroes
    if (count1 > count0) {
        possible = true;
    }
    
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
