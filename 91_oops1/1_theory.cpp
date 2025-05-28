/*
Procedural Programming vs Object-Oriented Programming (OOP)

✅ 1. Procedural Programming
Definition:

Programming paradigm based on functions and procedures. 
Code is written step-by-step like a recipe.


Key Features:
Focus is on functions and sequence of steps (procedure).
Data and functions are separate.
Follows top-down approach.
Not very suitable for large or complex applications.
Difficult to maintain or scale.


Example Languages: C, Pascal

Code Example (C-style):

int a, b;
void add() {
    printf("%d", a + b);
}


Drawbacks:
Poor code reusability
Global data is more vulnerable (low security)
Not suitable for real-world modeling



🧱 2. Object-Oriented Programming (OOP)

Definition:
Programming paradigm based on objects (instances of classes) which combine data and behavior.

Key Features:
Focus is on objects and data abstraction.
Combines data + methods in a single unit called class.
Follows bottom-up approach.
Excellent for scalability, maintainability, and code reusability.
Real-world modeling is easier.
Example Languages: C++, Java, Python


Code Example (C++-style):
class Calculator {
    int a, b;
public:
    Calculator(int x, int y) { a = x; b = y; }
    void add() { cout << a + b; }
};


CLASS is a user defined data type. it is basically a BLUEPRINT of the structure.

OBJECT is an instance (execution/parchai) of the class


factors->
1. data abstraction (backend server crucial all things hidden)
reason-> security, user interface

2. data encapsulation -> putting multiple data into a single data
for example player class contains itself is now a data type and contains other data
type like int ammo, int health, char name

3. inheritance -> child apne parents ki properties ko inherit karta hai..


4. polymorphism -> different functionality can be achieved from the same piece of code.
4a-> overloading
4b-> overriding


access modifiers :-> 
Public -> bahar se koi bhi access kar sakta hai...
 Private-> bahar se koi bhi access nahi kar sakta hai...
  Protected-> bahar se access to nahi but ha aap inherit to kar sakte ho..

-> variable inside class are called data members
-> functions inside class are called member functions 
 {ye jo tu setter getter sab likhta h wo sab member fns hi to h...}


-> class to kewal ek blueprint hota hai...data members ya member function ko to
OBJECT hi invoke karega


oops says ki for security reasons 
1. data members ko private rakho and ab aap thodey naye functions banao...
like setter and getter to set and get data member values..

2. member function ko public rakho...


*/