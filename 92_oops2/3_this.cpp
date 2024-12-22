#include<iostream>
using namespace std;

class player{
private:   // data members ko private rakho and usko execute karo by help of public: getter and setter.
    int health;
    int score;
    int age;
    

public:
    // ab likho saare getter functions
    int getHealth(){
        return health;
    }
    int getScore(){
        return score;
    }
    
    int getAge(){
        return age;
    }

    
    // ab likho saare setter function

    void setHealth(int health){
        this->health = health;  // arrow operator lagate hi wo ab seedhe class ki
                                // definition ko dekhega and class ke health mai 
                                // value daal dega health ki
    }

    void setScore(int score){
        this->score = score;
    }
    void setAge(int age){
        this->age = age;
    }

    













};

// now player ko tum as a data type use kar sakte ho..
// accha data members aur data function sab class ka hi part hote hai..






int main(){
    player abd;   // object creation statically
    abd.setAge(45);
    cout<<abd.getAge();
    cout<<endl;

    abd.setHealth(50);
    abd.setScore(90);

    
    cout<<abd.getScore();
    cout<<endl;





}


// class bhi to ek data type hi hai me class ko bhi to pass kar sakta hu function me 
// class ko function se return bhi la sakta hu...
// int addscore(player a, player b)  // addScore function do parameter le rha hai, 
                    // player a, player b..

// to access the object dot is required IMP
// to access the pointer object arrow-> operator is required