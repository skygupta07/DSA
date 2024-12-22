#include<iostream>
using namespace std;

class player{
private:   // data members in private mode..
    int health;
    int score;
    string name;


public: // member functions ko public karo..

    //setter
    void setscore(int s){
        cout<<"score set kiya ja raha hai.";
        score = s;   
    }

    void sethealth(int h){
        health = h;
    }
    

    // getter

    int getscore(){
        return score;
    }

    int gethealth(){
        return health;
    }

};


int main(){
    player akash;
    akash.setscore(60);
    akash.sethealth(90);

    cout<<akash.gethealth();
    cout<<endl;
    cout<<akash.getscore();
}


// kul mila ke data members ka direct access nahi deke usko public function ka use karke
// then getter setter laga ke access karo..
