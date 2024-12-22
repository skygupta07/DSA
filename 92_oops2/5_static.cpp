#include <iostream>
using namespace std;

void print1(){
    int b = 10;
    cout<<b<<endl;
    b++;
}


void print2(){
    static int c = 7;
    cout<<c<<endl;
    c++;
}


int main(){
    print1();
    print1();
    print1();
    cout<<endl;

    print2();
    print2();
    print2();
}




























/*

the static keyword is used with a variable to make the memory of the variable static, 
once a static variable is declared its memory can't be changed...

















*/