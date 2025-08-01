// sieveOfEratosthenes.cpp

#include <bits/stdc++.h>
using namespace std;


void sieveOfEratosthenes(int n) {
    // Step 1: Create a boolean vector and initialize all entries as true
    vector <bool> isPrime(n + 1, true);

    // 0 and 1 are not prime
    isPrime[0] = isPrime[1] = false;

    // Step 2: Start marking multiples of each prime number
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            // Mark all multiples of i as not prime {understood the significance of multiple of i...}
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Step 3: Output all prime numbers
    cout << "Prime numbers up to " << n << " are:\n";

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }

    cout << endl;
}


int main() {

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    sieveOfEratosthenes(n);
    
    return 0;
}
