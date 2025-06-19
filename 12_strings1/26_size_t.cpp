#include <bits/stdc++.h>
using namespace std;


/*

👉 size_t ek unsigned integer type hai jo typically array indexing aur memory sizes 
represent karne ke liye use hota hai.

Details:

Unsigned hota hai (matlab negative values nahi store karta).
Platform-dependent hota hai (32-bit system me size_t 4 bytes ka hota hai, 
aur 64-bit system me 8 bytes ka).
Zyada tar STL functions (like string::size(), vector::size()) ka return type size_t hi hota hai.

*/

#include <iostream>
using namespace std;

int main() {
    string s = "hello world";
    
    // find() ka return type `size_t` hota hai
    size_t pos = s.find("world");

    if (pos != string::npos) {
        cout << "Found at index: " << pos << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}


// Output:


Found at index: 6
Use in find()
Jab find() kisi substring ko locate karta hai, to ye uska index return karta hai (jo size_t type ka hota hai).
Agar substring nahi milti, to ye string::npos return karta hai (jo ek bada unsigned number hota hai).

Common Mistake (Comparing size_t with -1)
size_t pos = s.find("xyz");
if (pos == -1) {  // ❌ Galat approach
    cout << "Not found";
}
Correct Approach:

if (pos == string::npos) {  // ✅ Sahi approach
    cout << "Not found";
}

/*
Kyun? Kyunki size_t ek unsigned type hai, to -1 uske liye ek bada positive number ban jata hai, jo galat result de sakta hai.

Conclusion
size_t unsigned integer hota hai jo memory size aur indexing ke liye best suited hota hai.
STL functions jaise size(), find(), length() mostly size_t return karte hain.
string::npos ka comparison pos == string::npos se karna chahiye, -1 se nahi.

*/