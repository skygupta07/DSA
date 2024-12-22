#include<iostream>
using namespace std;

class player{
private:  // imp
    int health;
    int score;
    int age;


public: // imp
    //setter fn.
    void sethealth(int h){
        this->health = h;
        // is current class ke health me h(health ki int value) daal do..
    }

    void setscore(int s){
        this->score = s;
    }
    void setage(int a){
        this->age = a;
    }


    // getter fn.
    int gethealth(){
        return health;
    }

    int getscore(){
        return score;
    }

    int getage(){
        return age;
    }
};


int main(){

    player akash;  // akash ab yaha object ki tarah treat hoga
    akash.setage(20);
    akash.sethealth(60);
    akash.setscore(50);

    
    player vishal;
    vishal.setage(10);
    vishal.sethealth(90);
    vishal.setscore(70);

    // dynamic memory allocation
    // pointer ka use, new keyword, 

    // bekar method M1

    // player* bob = new player;
    // player bobObject = *bob;
    // // dereference operator ka use karke bob ki value nikali

    // bobObject.setage(40);
    // cout<<bobObject.getage()<<endl;

    // agar aapke paas normal object hai to usko tum dot operator se access kar sakte ho..
    // but agar aapke paas pointer object hai to ussey aap this-> ka use karke access kare 
   //  directly. waha dot operator nahi chalega rather ki aap pehle pointer banaye then pointerObject banaye then execute karte..

    // inshort this-> operator is like broker for class members and assigning variables..


// simply har choote se choote kaam ke liye aap function bana liya karo....


    // good method M2
    player* bob = new player;
    bob->setage(45);
    cout<<bob->getage()<<endl;
 
}


