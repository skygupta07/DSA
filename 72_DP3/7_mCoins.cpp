#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k,l,m;
    // m -> no. of games
    cin>>k>>l>>m;

    vector <bool> dp(1000005,0);
    dp[1] = 1;
    dp[k] = 1;
    dp[l] = 1;  // 1 means winning state...

    // bottom up approach
    for (int i=2; i<=1000000; i++){
        if (i==k || i==l) continue; // base case already computed...
        dp[i] = !(dp[i-1] and ((i-k >=1) ? dp[i-k] : 1) and ((i-l >= 1) ? dp[i-l] : 1));

        // agar mai kucch kar lu saare options explore karne par bhi win win win hi state 
        // mil rahi hai saamne waale ko then i will definitely be loosing with that number of 
        // coins left to me...

        // agar AND ki condition ko neutral rakhna ho constraints maintain karne ke liye to 
        // 1 rakho...

    }

    for (int i=0; i<m; i++){
        int n;
        cin>>n;
        if (dp[n]==1){
            // n -> winning state
            // those who started will win ..
            cout<<"A";
        }
        else{
            cout<<"B";
        }
    }



}



/*

Asen and Boyan are playing the following game. They choose two different positive integers
K and L, and start the game with a tower of N coins. Asen always plays first, 
Boyan – second, after that – Asen again, then Boyan, and so on. The boy in turn can 
take 1, K or L coins from the tower. The winner is the boy, who takes the last coin 
(or coins). After a long, long playing, Asen realizes that there are cases in which he 
could win, no matter how Boyan plays. And in all other cases 
Boyan being careful can win, no matter how Asen plays.

The input describes m games.

The first line of the standard input contains the integers K, L and m,
 1 < K < L < 10, 3 < m < 50. The second line contains m integers
  N1, N2, …, Nm, 1 ≤ Ni ≤ 1 000 000, i = 1, 2, …., m, representing the number of coins 
in each of the m towers



So, before the start of the game Asen is eager to know what game case they have.
Write a program coins which help Asen to predict the game result for given K, L and N


=> just write a fn which will tell that whether we will lose or win accordingly at which
stage we fell, like how many coins are we left with....
*/