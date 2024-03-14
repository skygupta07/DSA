#include <iostream>
using namespace std;
int factorial(int n);
int permutation(int n, int r);
int main(){
 int n,r;
 cout<<"enter n & r: "; 
 cin>>n>>r;
 cout<<"npr equals= "<<permutation(n,r);
return 0;

}

int factorial(int n){
    int fact=1;
    for (int i=1; i<=n; i++){
        fact = fact*i;

    }
    return fact;
}

int permutation (int n, int r){
    int per = factorial(n)/factorial(n-r);
    return per;
}