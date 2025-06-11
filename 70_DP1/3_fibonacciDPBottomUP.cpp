// fibDPBottomUP.cpp


#include <iostream>
#include<vector>
using namespace std;

vector <int> dp;

int fibo(int n){
    
    dp.clear();
    dp.resize(n+1 , -1);  // yaha dp array ko internally banaya

    dp[0] = 0;  // base cases
    dp[1] = 1;

    // ye cheej thodi notice karne wali h ki... recursive call n se 1 tak ki h to .. 
    // phir fbu ka loop 1 to n ka lagaya.... chalo ye rahat h ki recurrence relation exact hi copy karna h..
    
    for (int i=2; i<=n; i++){  // loop laga ke tumne simply dp ke har element ko fill kiya
        dp[i] = dp[i-1] + dp[i-2];  // iterative soln..
    }

    return dp[n];

    // there is no recursive call here simply you are filling your dp array
    // yaha function ke andar hi aapne dp ko initialise kiya and kucch element khud fill
    // kar diya then haath pakadwa ke aage walo se bhi karwa diya....

}



int main(){
    int n = 8;
    int ans = fibo(n);
    cout<<ans<<endl;
}


/*
we apply local optimism in greedy while dp soln focus on global optimum i.e. we take action
after considering all the cases

*/

