#include <bits/stdc++.h> 
using namespace std;

class Rectangle{
public:
    int l;
    int b;

    // constructor ka naam same as class name
    // types: default , parameterised , copy constructor (dpc) karwate hai ghar aur constructor mai
    // ek class ke andar there can be more than one constructor..
        // The technique of having two (or more) constructors in a class is known as
        //  constructor overloading - {asked by Geetanjali Mam}

    // depending on the name or syntax corresponding constructor will be chosen..
   
   
    Rectangle(){ // default - no parameters needed
       
    }

    Rectangle(int x, int y){ // parameterised -> best
        l= x+2; // this->l = x+2
        b = y+2;
    }

    Rectangle(Rectangle &r){ // copy constructor
        l = r.l;    // hamari class wale length l mai aap bahar se aaye huye 
                    // Rectangle r ki length daal do
        b = r.b;
    }
};


int main(){
    Rectangle r1;
    cout<<r1.l<<" "; // since yaha par mene koi bhi value initialise nahi ki and length l ko print 
                    // karna chaha so l ki value wo automatic hi constructor se le lega jo ki 
                    // mene initialise hi nahi kiye values => garbage value le lega

    Rectangle r2(7,3);
    cout<<r2.l<<" ";

    Rectangle r3(r2);
    cout<<r2.b<<" ";

}


/*
class mai constructor mandatory

constructor -> hidden function -> initialisation -> object creation

// by default rehta hi hai...
but you can make your own 


similar to function() => but constructor ka koi return type nahi hota and iska name
same as the class name..

-> jab jab object create hoga constructor ko call lagegi.
-> constructor ki help se hum koi value initialise bhi kar sakte hai...


*/


