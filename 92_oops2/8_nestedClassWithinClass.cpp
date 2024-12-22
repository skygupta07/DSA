#include <iostream>
using namespace std;

class Guns{
    int ammo;
    int damage;
    int scope;

};

class player{
private:
    int health;
    int score;
    int age;
    Guns gun;

    class helmet{
    private: // data members
        int hp;
        int level;
    

    // class banane ke baad turant uske setter getter bana liya karo..
    // important: wo class jab tak khatam nahi hoti jab tak ki usssssss class ke getter setter function uske andarrrr hi included na ho..
    public:
    //helmet class ke setter fn..
    void setHp(int hp){  
        this->hp = hp;    // class wale hp mai mene jo input liya hai ussey daal do..
    }

    void setLevel (int level){
        this->level = level;
    }
    // helmet class ke getter fn..
    int getHp(){ 
        return hp;
    }
    int getLevel(){
        return level;
    }
    };  // helmet class definition ends

    // player ke setter getter to likho
    public:
    // setter fn
    void setAge(int age){
        this->age = age;
    }

    void setScore(int score){
        this->score = score;
    }

    void setHealth(int h){
        this->health = h;
    }
    // getter fn
    int getAge(){
         return age;
    }
    int getScore(){
        return score;
    }
    int getHealth(){
        return health;
    }
    
    // nested class within class hai isliye yaha ye fns sab use karne padenge..
    void setHelmet(int level){
        helmet* h = new helmet; //IMP

        // class helmet pointer then pointer ka naam barabar new keyword then class ka naam
        h->setLevel(level);
        
        //let's apply some condition to helmet level and its corresponding health..
        if (level==1){
            health = 60;
        }

        else if (level == 2){
            health = 70;
        }

        else if (level == 3){
            health = 80;
        }

        h->setHp(health);   //IMP

        // now health bhi ab condition ke according hi allot hogi...
    }

    


};








int main(){
    player a;
    a.setAge(45);
    a.setHealth(60);
    a.setScore(70);
    a.setHelmet(2);
   

    cout<<a.getAge()<<endl;
    cout<<a.getHealth()<<endl;
    cout<<a.getScore()<<endl;



}