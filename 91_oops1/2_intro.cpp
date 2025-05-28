#include <bits/stdc++.h>
using namespace std;


// class player{
// public:
//     int health;
//     int score;   // data members
//     string name;
    
//     void showhealth(){   // member function..
//         cout<<"health is: "<<health;
//     }
// };

// int main(){
//     player akash;
//     akash.health = 50;
//     akash.name = "ak";
//     akash.score = 90;

//     cout<<akash.score<<endl;
//     akash.showhealth();
//     cout<<endl;
// }


#include<iostream>
using namespace std;

class player{
private:  // imp
    int health;
    int score;
    int age;


public: // imp
    //setter fn.

    // basically member functions comprise of both getter and setter function
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
    player akash;  //very first work is to create object of the class.... 
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