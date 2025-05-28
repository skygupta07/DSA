#include <bits/stdc++.h>
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
        // is current class ke head me h(health ki int value) daal do..
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

    player akash;
    akash.setage(20);
    akash.sethealth(60);
    akash.setscore(50);

    cout<<akash.getage()<<endl;
    cout<<akash.gethealth()<<endl;
    cout<<akash.getscore()<<endl<<endl;

    player vishal;
    vishal.setage(10);
    vishal.sethealth(60);
    vishal.setscore(50);

    cout<<vishal.getage()<<endl;
    cout<<vishal.gethealth()<<endl;
    cout<<vishal.getscore()<<endl;

}