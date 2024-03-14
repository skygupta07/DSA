#include <iostream>
using namespace std;

class Fruit{
public:
    int cost;
    int number;
    
    Fruit(){ // constructor ka use print karne ke liye kiya waah..
        cout<<"in the Fruit class Parent class"<<endl;
    }

};
class Mango: public Fruit{
public:
    Mango(){
        cout<<"in the child class Mango class"<<endl;

    }

// child class: parent class


};





int main(){
    Mango();
// mene main fn me kewal child class ko call kiya but since child class is inherited from parent class
// so first parent class is called then child class..

}