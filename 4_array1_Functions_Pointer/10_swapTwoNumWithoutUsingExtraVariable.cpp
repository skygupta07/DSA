#include <iostream>
#include <vector>
using namespace std;

void mySwap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}




int main(){
    int a = 3;
    int b = 5;
    mySwap(a,b);
    cout<<a<<" "<<b<<endl;
}