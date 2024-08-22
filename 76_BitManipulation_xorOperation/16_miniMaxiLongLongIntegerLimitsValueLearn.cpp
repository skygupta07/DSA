#include <bits/stdc++.h>
using namespace std;


int main(){
    int mini = INT_MIN;
    cout<<mini<<"\n";   // -2147483648

    int maxi = INT_MAX;
    cout<<maxi<<"\n";   // 2147483647   -> max matlab ek kam tak hi store kar payenge..


    int alpha = INT_MAX;
    int doubleAlpha = 2*alpha;
    cout<<doubleAlpha<<"\n";    // -2   interesting -> yahi sab to overflow ho raha tha to ...
                                // wrong answer aa raha tha.....

    int beta = INT_MIN;
    int doubleBeta = 2*beta;
    cout<<doubleBeta<<"\n"; // aur minus mai na jaake simply zero hi print kar diya..

    long gamma = INT_MAX;
    long twiceGamma = 2*gamma;
    cout<<twiceGamma<<"\n"; // 4294967294


    long long delta = LONG_MAX;     // 9223372036854775807
    cout<<delta<<"\n";  
    long long twiceDelta = 2*delta;
    cout<<twiceDelta<<"\n";

    long long zeta = __LONG_LONG_MAX__; //9223372036854775807
    cout<<zeta<<"\n";

}