#include <bits/stdc++.h>

// void fun(){
//     cout<<"ak"<<endl;
//     fun();
// }

void fun(int n){
    if (n==0) return;  // return encounter hote hi function khatam ho jaega..
    cout<<"akash"<<endl;
    fun(n-1);
}


int main(){
    fun(5);

}

// 1. Recursion matlab badi problem ko subproblem me todo 
// and base case laga simply execute kar do..


