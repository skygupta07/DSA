// totalNumberOfDigitsInNumber.cpp

#include <bits/stdc++.h>
using namespace std;


int findDigitCount(int x){
    if (x == 0) return 1;
    
    int count = 0;
    while (x > 0){
        count++;
        x = x / 10;
    }
    return count;
}



int main(){
    int n = 2345678;
    string num = to_string(n);
    cout<<num.length()<<endl;
}