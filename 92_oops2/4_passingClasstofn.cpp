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

int addscore(player a, player b){
    // function me mene players as parameter pass kiya

    // dekh raha hai class ka magic, hum yaha int a, int b likhte the otherwise..
    // matlab player as a data type ki tarah treat ho rha hai..
    int totalscore = a.getscore()+ b.getscore();
    return totalscore;

}

// agar me function me player(class wala) pass kar sakta hu to me aisa function bhi to bana
// sakta hu jo player return kare....

player maxScorePlayer(player a, player b){
    if (a.getscore() > b.getscore()) return a;
    else return b;
}

int main(){

    player akash;  // akash ab yaha object ki tarah treat hoga
    akash.setage(20);
    akash.sethealth(60);
    akash.setscore(50);

    cout<<akash.getage()<<endl;
    cout<<akash.gethealth()<<endl;
    cout<<akash.getscore()<<endl<<endl;

    player vishal;
    vishal.setage(10);
    vishal.sethealth(90);
    vishal.setscore(70);

    cout<<vishal.getage()<<endl;
    cout<<vishal.gethealth()<<endl;
    cout<<vishal.getscore()<<endl;

    cout<<addscore(akash,vishal)<<endl;   //120


    // cout<MaxScorePlayer(akash,vishal); yeh invalid syntax hoga 
    // kyuki tum aise class ko directly cout nahi kar sakte pehle usko object me store karo then print karo by using getter..

    player topper = maxScorePlayer(akash, vishal);
    cout<<topper.getscore()<<endl;


}