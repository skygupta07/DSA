#include <bits/stdc++.h>

void generate(string s, int open, int close, int n){
    if (close == n){ // base case because mere dry run mai closing brackets hi baad mai
                                // fill huye hai.....
        cout<<s<<endl;
        return;
    }
    
    if (open<n) generate(s+'(', open+1 , close, n);  // opening bracket call
    if (close<open) generate(s+')',open,close+1,n); // add closing bracket iff 
                            // count of closing bracket is less than count of opening bracket...
}




int main(){
    generate("",0,0,3);
}


// recursive call mai extra parameters to bas likhte jao...
