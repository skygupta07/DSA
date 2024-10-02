#include<iostream>
using namespace std;

class Guns{
public:
    int ammo;
    int damage;
    int scope;
};

class Player{
private:  // member fns
    int health;
    int score;
    int age;
    Guns gun;   // yaha use kiya upar defined data type (class) ko

public: // imp
    //setter fn.
    void setHealth(int h){
        this->health = h;
        // is current class ke health me h(health ki int value) daal do..
    }

    void setScore(int s){
        this->score = s;
    }

    void setAge(int a){
        this->age = a;
    }
    
    // getter fn.
    int getHealth(){
        return health;
    }

    int getScore(){
        return score;
    }

    int getAge(){
        return age;
    }

    void setGun(Guns g){  // imp
        this->gun = g;  // halaki directly to gun iss class mai bhi nahi hai ...
                        // but chuki gun ko inherit kara hai...means all the property
                        // will get inherited..
    }

    Guns getGun(){  
        return gun;
    }

};


int main(){

    Player akash;  // akash ab yaha object ki tarah treat hoga
    akash.setAge(20);
    akash.setHealth(60);
    akash.setScore(50);

    Player vishal;
    vishal.setAge(10);
    vishal.setHealth(90);
    vishal.setScore(70);

    Guns ak47;
    ak47.ammo = 45;
    ak47.damage = 70;
    ak47.scope = 5;

    akash.setGun(ak47);  //imp
    akash.getGun();
    
    // since yaha par mene class Guns banayi but ussey mene player class ke andar rakh diya 
    // matlab main head to player hi rahega even jab value get set ki baat aaegi to bhi..

    Guns awm;
    awm.ammo = 45;
    awm.damage = 70;
    awm.scope = 5;

    vishal.setGun(awm);
    vishal.getGun();
}

// class ka naam start with capital letter
// member fn wagera mai use camel case writing...