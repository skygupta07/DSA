#include <iostream>
using namespace std;

int power(int a, int b){
    if (b==0){
        return 1;
    }
    else if (b==1){
        return a;
    }
    else{
        if (b%2==0){    //even base can be easily reduced to 1..
        return power(a,b/2) * power(a, b/2);    // dividing function
        } 
        else return power(a,b/2) * power(a,b/2) * a;
    }
}

int main(){
    int a,b;
    cout<<"enter base: ";
    cin>>a;
    cout<<"enter power: ";
    cin>>b;

    cout<<power(a,b);
}


