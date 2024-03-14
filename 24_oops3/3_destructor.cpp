#include <iostream>
using namespace std;

class Bike{
public:
    int tyreSize;
    int engineSize;

    Bike (){        // return type written only since constructor ka koi naam nahi hota
        cout<<"constructor is called"<<endl;
    } 
    // ye ekdum default constructor hai aur ha ye hamesha hi call hoga jab bhi 
    // object create hoga..  

    Bike(int wheel, int engineSize){
        this->tyreSize = wheel;
        this->engineSize = engineSize;
        cout<<"construcor"<<endl;
    }

    ~Bike(){
        cout<<"destructor is called.."<<endl;
    }
};

int main(){
    // object creation 
    Bike tvs(5,100);
    Bike honda(8,150);
    Bike hero(10,200);
    Bike yamaha(12,300);

    bool flag = true;
    if (flag == true){
        Bike bajaj(7,250);  // no one knows him out of this curly braces..
    }

    cout<<honda.engineSize<<endl;
    cout<<honda.tyreSize<<endl;
    
}





















/*

memory free karo bhai jab uska kaam ho gya..
-> destructor is called when object goes out of scope....matlab theek jaise hi uska ilaka 
khatam hoga uss object ke liye turant destructor call ho jaega...

memory free up ya delete karne ka code hum destructor mai likhte hai...





*/