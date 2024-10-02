#include<iostream>
using namespace std;

class Rectangle{
public:
    int l;
    int b;
 
    Rectangle(){ // default - no parameters needed
        l=1;
        b=2;  // matlab jab bhi koi Rectangle class ko use karega by default to 
        // constructor ke design ke karan usme ye values assign ho jaengi apne aap...
    }

    // constructor ke just neeche aapka destructor

    // tilde/colgate className    for destructor
    ~Rectangle(){ // here never a parameter is passed in destructor fn..
        cout<<"destructor fn is called.."<<endl;

    } // matlab jaise hi main function khatam hota hai then destructor fn is always called..
   
};


int main(){
    Rectangle r1;
    cout<<r1.l<<endl;
    
    Rectangle* r = new Rectangle();
    delete r;
   // you can use delete keyword only on pointer variable..
}

// access specifier
// 1. public: can be used easily anywhere
// 2. protected: can be used in class and derived class.
// 3. private: can be use in that class only..


