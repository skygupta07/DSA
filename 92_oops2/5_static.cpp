#include <iostream>
using namespace std;

// print1() function: yeh har baar naye variable 'b' banata hai
void print1(){
    int b = 10;  // Normal local variable, har baar function call hone par naye memory location mein b = 10
    cout << b << endl;
    b++;         // b++ ka koi effect nahi hoga next call mein, kyunki b fir se 10 banega
}

// print2() function: yeh static variable use karta hai
void print2(){
    static int c = 7; // Static variable sirf ek baar initialize hota hai, fir uski value retain hoti hai across function calls
    cout << c << endl;
    c++;              // c ki value increment hoti rahegi aur retain hogi next function calls mein
}

int main(){
    // print1() teen baar call ho raha hai, lekin b hamesha 10 print karega
    print1(); // Output: 10
    print1(); // Output: 10
    print1(); // Output: 10

    cout << endl;

    // print2() teen baar call ho raha hai, aur c ki value har baar increment ho rahi hai
    print2(); // Output: 7
    print2(); // Output: 8
    print2(); // Output: 9
}

/*

OUTPUT:

10
10
10

7
8
9

*/

/*

- **Static keyword** ka use kisi variable ki memory ko function ke lifetime 
se zyada banaye rakhne ke liye hota hai.

- Jab bhi ek `static` variable banta hai function ke andar, 
wo sirf ek baar initialize hota hai.

- Iska matlab: agar function 100 baar bhi chale, 

to static variable ek hi memory location mein rehta hai aur uski value preserve hoti hai.

- Normal variable (like b in `print1`) har baar function ke call pe destroy aur phir se create hota hai. 
Isliye uski value reset ho jaati hai.


*/
