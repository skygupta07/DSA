#include<iostream>
using namespace std;

class student{
public:
    string name;
    int rollno;
    int marks;

    // constructor
    student(string n, int r, int m){ // accha mene this keyword ko avoid karne ke liye hi yaha name different kiye hai...
        name = n;   // equivalent to this->name = n;
        rollno = r;
        marks = m;
    }
};





void change(student s){
    s.name = "vishal";
}

void change2(student &s){ // passed by reference, so value got changed..
    s.name = "vishal";
}





int main(){
    //      name , rollno, marks
    student ak("akash", 45, 94);
    // cout<<ak.marks<<endl;
    // cout<<ak.name<<endl;
    // change(ak);

    // cout<<ak.name<<endl; // value didn't change since passed by value
    // change2(ak);
    // cout<<ak.name<<endl;



    student* ptr = &ak;
    // jaise int,char,float ka pointer waise hi student ka pointer..
    ptr->rollno = 70;  // old generation method..to change value.
    cout<<ak.rollno<<endl;
}


// vector bhi pass by value hota hai by default, accha tabhi usme & lagana padta hai for pass by reference...
// accha ab samjha linked list me wo sab kyu pointers ke through bhej rha tha taki sab jagah easily same changes reflect ho
// and is easy to implement..

// dekho vectors dekhne me theek hai magar time space complexity utni theek nahi hai..
// ek baar size khatam hone ke baad vector ek array banata now ab double size ki....
