#include <iostream>
using namespace std;

class calculator{
public:
    int a;
    int b;

    void add(){   // MEMBER FUNCTION hai isliye kuch parameters bhi entry nahi le rha
                // ghar ke hi to log hai easily accessible hai..
        cout<<a+b<<endl;
    }

    void subtract(){
        cout<<a-b<<endl;
    }

};


int main(){
    calculator calci; // object creation..  => classkaNaam ObjectKaNaam
    calci.a = 4;
    calci.b = 7;

    calci.add();
    calci.subtract();
}


// oops kehti hai ki: 
// data members ko private rakho
// member function ko public rakho

// value set karne ke liye setter ka use karunga
// value get karne ke liye getter ka use karunga
//
