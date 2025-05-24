#include <iostream>
using namespace std;


int stair(int n){
    // ya to ek kadam ya do kadam allowed
    if (n==1) return 1; 
    else if (n==2) return 2; // base case...
    else return stair(n-1)+ stair(n-2);  // arrey yeh to same fibonacci ki tarah h..
}

int main(){
    int n;
    cout<<"enter the uppermost stair number: ";
    cin>>n;
    cout<<"number of ways to climb is: " << stair(n) <<endl;
}