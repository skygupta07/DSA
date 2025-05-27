#include <bits/stdc++.h>
using namespace std;


int main() {

    int amount;
    cout << "Enter amount: " << endl;
    cin >> amount;

    int n1, n2, n5, n10, n20, n50, n100, n200, n500;
    n1 = n2 = n5 = n10 = n20 = n50 = n100 = n200 = n500 = 0;

    // real life se bhi inspired h.. like pehle tu khulle dete waqt bhi pehle bada note hi uthayega.. 
    // then ussey chota note then ussey chota jo bhi adjust ya fit ho jaye...

    if (amount >= 500) {
        n500 += amount / 500;
        amount -= n500 * 500;
    }

    if (amount >= 200) {
        n200 += amount / 200;
        amount -= n200 * 200;
    }

    if (amount >= 100) {
        n100 += amount / 100;
        amount -= n100 * 100;
    }

    if (amount >= 50) {
        n50 += amount / 50;
        amount -= n50 * 50;
    }

    if (amount >= 20) {
        n20 += amount / 20;
        amount -= n20 * 20;
    }

    if (amount >= 10) {
        n10 += amount / 10;
        amount -= n10 * 10;
    }

    if (amount >= 5) {
        n5 += amount / 5;
        amount -= n5 * 5;
    }

    if (amount >= 2) {
        n2 += amount / 2;
        amount -= n2 * 2;
    }

    if (amount >= 1) {
        n1 += amount / 1;
        amount -= n1 * 1;
    }

    cout << "Number of 500 notes needed are: " << n500 << endl;
    cout << "Number of 200 notes needed are: " << n200 << endl;
    cout << "Number of 100 notes needed are: " << n100 << endl;
    cout << "Number of 50 notes needed are: " << n50 << endl;
    cout << "Number of 20 notes needed are: " << n20 << endl;
    cout << "Number of 10 notes needed are: " << n10 << endl;
    cout << "Number of 5 notes needed are: " << n5 << endl;
    cout << "Number of 2 notes needed are: " << n2 << endl;
    cout << "Number of 1 notes needed are: " << n1 << endl;

    return 0;
}
