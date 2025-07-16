#include <iostream>
#include <vector>
using namespace std;
int main(){

    cout<<endl;
    cout<<"IMPORTANT star triangle flipped "<<endl;

    /*
    ek loop ke andar do loop lagenge....
    ek loop se hashes print honge .... and aapka ek loop se stars print hoga...
    principle of addition lagaya...wo waha khud set ho jayega bas tum standard loops chalao..
    */


    for (int i=1; i<=4; i++){
        for (int j=1; j<=4-i+1; j++) cout<<"  ";
        for (int j=1; j<=i; j++) cout<<"* ";
        cout<<endl;
    }

    // method 2 

    for (int i=1; i<=4; i++){
        for (int j=1; j<=4; j++){
            if (i+j >= 4+1) cout<<"* ";
            else cout<<"  ";
        }
        cout<<endl;
    }


    /*
    
    ###*
    ##**
    #***
    ****
    
    */

    cout<<endl;
    cout<<"Rhombus "<<endl;

    int r=5;
    int c=5;

    for (int i=1; i<=r; i++){
        // spaces ka loop 
        for (int j=1; j<=r-i+1; j++){
            cout<<"  ";
        }
        // star ka loop
        for (int j=1; j<=c; j++){
            cout<<"* ";
        }
        cout<<endl;
    }


    cout<<endl;
    cout<<"star Pyramid"<<endl;

    r=4;
    c=7;

    for (int i=1; i<=r; i++){
        // spaces ka loop 
        for (int j=1; j<=r-i; j++){
            cout<<"  ";
        }
        // star ka loop
        for (int j=1; j<=2*i - 1; j++){
            cout<<"* ";
        }
        cout<<endl;
    } 
}

