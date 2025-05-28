#include <bits/stdc++.h>
using namespace std;

class Bike {
public:
    int tyreSize;
    int engineSize;

    // Default constructor -> jab object create hoga aur parameters na diye gaye ho tab ye call hoga
    Bike() {  
        cout << "Default constructor is called" << endl;
    }

    // Parametrized constructor -> jab object banate time values diye jaate hain
    Bike(int wheel, int engineSize) {
        this->tyreSize = wheel;   // `this` pointer is used to refer to the current object
        this->engineSize = engineSize;
        cout << "Parameterized constructor is called" << endl;
    }

    // Destructor -> jab object apni scope se bahar chala jaata hai tab ye automatically call hota hai
    ~Bike() {
        cout << "Destructor is called.. Memory cleanup happening!" << endl;
    }
};

int main() {
    // Objects creation -> har baar parametrized constructor call hoga
    Bike tvs(5, 100);
    Bike honda(8, 150);
    Bike hero(10, 200);
    Bike yamaha(12, 300);

    // flag check karke ek aur object create ho raha hai
    bool flag = true;
    
    if (flag == true) {
        // Yaha pe bajaj object create ho raha hai, jo sirf is scope ke andar rahega
        Bike bajaj(7, 250);  // Destructor isko turant cleanup karega jab curly braces close honge
    }  // Bajaj ka destructor yahi pe call ho jaayega kyunki yeh scope ke bahar ja raha hai

    // Honda object ke members print ho rahe hain
    cout << honda.engineSize << endl;
    cout << honda.tyreSize << endl;

    // Yaha end pe yamaha, honda, hero, tvs ke destructors apni scope ke khatam hote hi call honge
    return 0;
}
