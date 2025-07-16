#include <iostream>
#include <vector>
using namespace std;


int main(){

    cout<<"rectangle"<<endl;

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++) cout<<"* ";
        cout<<endl;
    }
    
    cout<<endl;
    cout<<"triangle"<<endl;
    
    for (int i=1; i<=4; i++){
        for (int j=1; j<=i; j++) cout<<"* ";
        cout<<endl;
    }

    cout<<endl;
    cout<<"triangle Reverse"<<endl;


    for (int i=1; i<=4; i++){
        for (int j=1; j<=5-i; j++) cout<<"* ";
        cout<<endl;
    }


    cout<<endl;
    cout<<"number Triangle"<<endl;

    for (int i=1; i<=4; i++){
        for (int j=1; j<=i; j++) cout<<j<<" ";
        cout<<endl;
    }

    cout<<endl;
    cout<<"odd number Triangle"<<endl;

    for (int i=1; i<=4; i++){
        for (int j=1; j<=i; j++) cout<<2*j - 1<<" ";
        cout<<endl;
    }

    cout<<endl;
    cout<<"alphabet square"<<endl;
    
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++) cout<<char(j+'A')<<" ";
        cout<<endl;
    }

}