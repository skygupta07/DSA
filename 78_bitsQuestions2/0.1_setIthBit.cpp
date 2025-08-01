#include <bits/stdc++.h>
using namespace std;


// jis number ko set karna tha just uske neeche 1 aa jaega... and then 
// phir uss banayi hui parat se OR kar dunga... to set the ith bit...

int setIthBit(int i, int x){
    x = x | (1 << i);
}



int main() {
    
    int i = 1;
    int x = 36;

    setIthBit(i, x);

    return 0;
}