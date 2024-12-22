#include <iostream>
using namespace std;

class Bike{
public:
    static int noOfBikes;
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

    static void increaseNumberOfBikes(){
        noOfBikes++;
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
now naye object ke liye engineSize aur tyreSize har bar naya banega.... but aapka
number of Bikes same rahega...

-> static fn aapka kisi object ka nahi hota wo to guru aapke class ka hota hai...
static will only access static
static member aur static function sabke liye same rahega...
-> same for all objects ...it belongs to the class...can be accessed directly by className

:: ilaaka batane waala operator...


*/



















