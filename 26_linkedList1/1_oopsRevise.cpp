#include <bits/stdc++.h>
using namespace std;


class Student{
public: 
    string name;
    int rollNum;
    float marks;

    // constructor
    Student(string n, int r, float m){
        (*this).name = n;   // or you can write name = n , or you can write   this->name = n;
        this->rollNum = r;
        this->marks = m;
    }
};

void changeCallByVal(Student x){
    x.name = "skyByVal";
}

void changeCallByRef(Student &x){
    x.name = "skyByRef";
}


int main(){
    // creating object 
    Student s1("Akash" , 39, 94.4);
    cout<<s1.marks<<"\n";

    cout<<s1.name<<"\n";
    changeCallByVal(s1);   
    cout<<s1.name<<"\n";

    changeCallByRef(s1);   
    cout<<s1.name<<"\n";

    // life kitni hard ho jaati agar hamare paas ye (->) operator nahi hota..
    // let's see...

    // creating new object
    Student s2("bob",34,87);
    // int*    integer ka pointer
    // float*   float ka pointer
    Student* ptr = &s2;

    // now accessing the data members of objects using pointers...
    (*ptr).marks = 66;  // equivalent to ptr->marks = 66;    matlab aapka (  -> === *().  )

    cout<<s2.marks<<"\n";
}



/*
array aapka bydefault pass by Reference hota hai..
but vector bydefalut pass by value hota hai... ha bhai tab hi uske aage &(and) 
laga ke hum pass by reference karte hai...


*/


/*
accha yaha to class mai simply int wagera rakha tha ..and then finally baad mai 
ptr ka use karke values modify karli..
but ll ke case mai to pura pointers ka hi game rehta hai to waha kaise kare??

    to phir hum yaha dynamically memory allot karenge...
    ListNode* temp = new ListNode(34);

    ab iss temp ke paas sab kucch access karne ki sakti aa chuki hai...

*/