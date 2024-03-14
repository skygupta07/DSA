//you are given an integer, you can perform any one of the following operation on it some 
// number of times
// 1. reduce n to n-1;
// reduce n to n/2 , if n is divisible by 2
// reduce n to n/3, if n is divisible by 3....
// find out in how many steps you can reduce n to 1.one..

// greedy fails here because maximum gap lene(i.e. dividing by max. num) will not always work.... 


#include <iostream>
#include <vector>
using namespace std;



int steps(int x, int dp[]){
    if (x < 2) return 0;
    dp[2] = 1;
    dp[3] = 1;
    if (dp[x])
        return dp[x];
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (x % 2 == 0)
        a = steps(x / 2, dp);
    if (x % 3 == 0)
        b = steps(x / 3, dp);
    c = steps(x - 1, dp);
    dp[x] = 1 + min(a, min(b, c));
}


int main(){
    int step;
    int n = 17;
    cout<<f(n,0)<<endl;
    

}