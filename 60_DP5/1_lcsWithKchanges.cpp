#include <iostream>
#include <climits>
using namespace std;


/*
ll dp[2005][2005][8];   // 3d dp
ll kOrderLCS(int *a, int *b, int n, int m, int i, int j, int k){
    if (n==i || m==j) return 0;
    if (dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    ll res = 0;
    if (a[i] == b[j]){
        res = 1 + kOrderLCS(a,b,n,m,i+1,j+1,k);
    }else{
        if (k>0){
            res = 1 + kOrderLCS(a,b,n,m,i+1,j+1,k-1);
        }
        res = max(res , kOrderLCS(a,b,n,m,i+1,j,k));
        res = max(res, kOrderLCS(a,b,n,m,i,j+1,k));
    }
    dp[i][j][k] = res;
    return res;
}



int main(){

}

*/




