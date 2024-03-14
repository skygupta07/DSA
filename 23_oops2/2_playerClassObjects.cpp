#include <iostream>
using namespace std;

class Player{
private:
    string name;    // data members
    int health;
    int ammo;
    bool alive;
public:
    //setter
    void setName(string s){
        name = s;
    }
    void setHealth(int h){
        health = h;
    }
    void setAmmo(int a){
        ammo = a;
    }
    void setIsAlive(bool condition){
        alive = condition;
        
    }

    // getter 
    string getName(){
        return name;
    }
    int getHealth(){
        return health;
    }
    int getAmmo(){
        return ammo;
    }
    bool getIsAlive(){
        if (alive) return true;
        else return false;  
    }

    //  member fn
    // f1 -> fn which returns the player with max health


};


Player maxHealthPlayer(Player a, Player b){
        if (a.getHealth() > b.getHealth()) return a;
        else return b;
}


int main(){
    Player abd; // AB Develiers -> object creation, statically
    Player msd; // Mahendra Singh Dhoni-> compile time, static memory Allocation

    Player *urvi = new Player; // runtime, dynamic memory Allocation
    // important.....

    abd.setAmmo(12);
    abd.setHealth(70);
    abd.setIsAlive(true);
    abd.setName("abcd"); // ab can do anything

    msd.setAmmo(15);
    msd.setHealth(85);
    msd.setIsAlive(false);
    msd.setName("thala");

    Player winner = maxHealthPlayer(abd, msd);
    cout<<"winner player name is: " << winner.getName() <<"\n";
    
    return 0;

}


