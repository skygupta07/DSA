#include <bits/stdc++.h>
using namespace std;


int sum(int n){
    // base case
    if (n==0) return 0; 
    if (n==2) return 3;    // oh yes => ye case hit karne par I am returning something...
    return n + sum(n-1);
}


// dekh teri marzi hai tu jitne jyada base case explore kar le but it is
// compulsory ki base to likh hi sahi...



int main(){
    int ans = sum(3);
    cout<<ans<<endl;
}






