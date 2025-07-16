#include <iostream>
#include <vector>
using namespace std;


int main(){

    cout<<endl;
    cout<<"star plus"<<endl;

    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){

            if (i==2 || j==2) cout<<"* ";
            else cout<<"  ";

        } 
        // line break after each row
        cout<<endl;
    }

    cout<<endl;
    cout<<"star cross"<<endl;

    for (int i=1; i<=5; i++){
        for (int j=1; j<=5; j++){

            // right diagonal case ...
            if (i==j) cout<<"* ";
            
            // left diagonal case
            else if (i+j == 6) cout<<"* ";
            else cout<<"  ";
        } 
        
        cout<<endl;
    } 

    cout<<endl;
    cout<<"floyd's triangle"<<endl; // maintaining the dhachaa...
    
    int num = 1;
    for (int i=1; i<=4; i++){
        for (int j=1; j<=i; j++){
            cout<<num<<" ";
            num++;
        } 
        cout<<endl;
    }

    cout<<endl;
    cout<<"binary triangle"<<endl;

    bool start = 1;
    for (int i=1; i<=4; i++){
        if (i%2 == 0) start = 0;
        else start = 1;
        for (int j=1; j<=i; j++){
            cout<<start<<" ";
            start = !start;
        } 
        cout<<endl;
    }


}