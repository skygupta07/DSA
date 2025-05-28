#include<iostream>
using namespace std;

class player{
private:   // data members ko private rakho and usko execute karo by help of public: getter and setter.
    int health;
    int score;
    int age;    

public: // dekh jab getter setter fn bana hi rha hu then constructor ki no need..
// getter setter fn ye constructor banenge to sab class ke andar hi...
// accha data members aur data function sab class ka hi part hote hai..

    // setter fn with return type void..
    void setHealth(int health){
        this->health = health;
    }

    void setScore(int score){
        this->score = score;
    }
    void setAge(int age){
        this->age = age;
    }


    // getter functions
    int getHealth(){
        return this->health;
    }
    int getScore(){
        return score;   // first of all it will check whether the score variable is present
        // locally if present then return it from locally else go the class definition and
        // take value from there...
    }
    
    int getAge(){
        return this->age; // or return age;
                        // both are equivalent...
    }

    
    // ab likho saare setter function
};

// now player ko tum as a data type use kar sakte ho..
// 


int main(){
    player abd;   // object creation statically
    abd.setAge(45);
    
    cout<<abd.getAge();
    cout<<endl;

    abd.setHealth(50);
    abd.setScore(90);
    
    cout<<abd.getScore();
    cout<<endl;

    player p2 = abd;
    // aisa karne se player p2 me player abd ke saare features aagye but ha by call by value aae hai..
    // deep copy...
    
    p2.setAge(30);
    cout<<p2.getAge();
    cout<<endl;
    cout<<abd.getAge()<<endl;
}


// class bhi to ek data type hi hai bas issey ek user apne hissab se define karta hai 
// matlab mai class ko bhi to pass kar sakta hu function me => yes... 
// class ko function se return bhi la sakta hu...
// int addscore(player a, player b)  // addScore function do parameter le rha hai, 
                    // player a, player b.. the parameters itself are being defined
                    // under some class


// updation me there would not be any problem at all..
// normally class/structure is passed by value...                    