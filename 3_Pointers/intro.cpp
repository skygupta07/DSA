#include<iostream>
using namespace std;

void change(int* ptr){
    *ptr = 5;  // *ptr is equivalent to x here
    // ptr ek pointer variable hai jo address ko store kar rha hai...
    // *ptr ek int variable hai jo ki uss address par padi value ko store karta hai...
}

int main(){
    int x = 4;
    cout<<x<<endl;
    change(&x);
    cout<<x<<endl;
}