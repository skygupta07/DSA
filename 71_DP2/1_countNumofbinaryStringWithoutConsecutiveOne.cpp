// given a number n, count the number of binary strings of length n, without consecutive ones
// using recursion

// this problem is same as fib(n) = fib(n-1) + fib(n-2)  where base case is:->
// when n=1 return 2
// when n=2 return 3
// when n=3 return 2+3 = 5

#include <iostream>
#include <vector>
using namespace std;

vector <int> dp;

int f(int n){
    if (n == 1) return 2;
    if (n == 2) return 3;

    if (dp[n] != -1) return dp[n];

    return dp[n] = f(n-1) + f(n-2);
}


int main(){
    int n;
    cin>>n;
    
    dp.clear();
    dp.resize(n+1, -1);
    cout<<f(n)<<endl;

}

// before solving a proplem try to think of different testcases involved and figure out some 
// pattern and solve question easily

/*
f(n) = f(n-1) + f(n-2) 
if (n=4) => strings of length 4 will be equal to length 3 ki strings ke last mai zero laga do 
and length 2 ki string ke aage 01 laga do...

if in your case you need to store atleast the given number of n states output then you 
need to create the vector of size (n+1) since vectors index starting with zero and you 
need to store the last state as well

*/

