#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    bool flag = true;   // true means prime...
    for (int i=2; i<=n-1; i++){
        if (n%i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}



int main(){
    int n;
    cout<<"enter number: "<<endl;
    cin>>n;

    if (n==1) cout<<"1 is neither prime nor composite number"<<endl;

    if (isPrime(n)) cout<<"number is prime"<<endl;
    else cout<<"number is not prime"<<endl;
}

/*
jaise hi break statement execute huyi .... loop ko kar do khatam tata bye bye...
ab uske neeche ka chalega hi nahi uss wale loop ki saari execution ke liye.....


*/