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
    

};



int main(){
    Bike tvs;   // object creation
    Bike honda(8,150);

    cout<<honda.engineSize<<endl;
    cout<<honda.tyreSize<<endl;
}




