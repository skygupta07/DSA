#include <bits/stdc++.h>
using namespace std;






int main(){
    int n = 8;  // numerator
    int d = 3;  // denominator

    int flor = n/d;
    cout<<flor<<endl;       //2

    int cel = ceil(static_cast <double> (n)/d);

    cout<<cel<<endl;        //3

}