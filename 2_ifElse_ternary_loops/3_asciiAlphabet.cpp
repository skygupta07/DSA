#include <bits/stdc++.h>
using namespace std;


int main(){
    char ch;
    cout<<"enter the character: ";

    cin>>ch;

    /*
    ascii value

    0 to 9-> 48 to 57
    A to Z -> 65 to 90
    a to z -> 97 to 122
    

    typecasting is int ascii = int(ch)

    now replace ascii everywhere with the condition...
    
    */
    if ( ( (int(ch) >=65) && (int(ch) <=90) ) || ( (int(ch)>=97) && (int(ch)<=122) ) ){
        cout<<"yes it is a alphabet"<<endl;
    }
    
}

// if (ch >= "A")


// multiple if else statements ko bhi ek hi condition mai likha ....