#include <iostream>
#include <unordered_set>
using namespace std;
void permutation(string &str, int i){
    if (i == str.size()-1){  // base case
        cout<<str<<"\n";
        return;
    }

    unordered_set <char> s;
    for(int idx = i; idx < str.size(); idx++){
        if (s.count(str[idx])) continue;    // if already present then continue
        s.insert(str[idx]); // insert into set s if not present
        swap(str[idx] , str[i]);
        permutation(str , i+1);
        swap(str[idx] , str[i]);  // again swapped after fn call for backtracking
    }
}


int main(){
    string str = "abc";
    permutation(str, 0);
    return 0;
}



// but this will not work for repetition of words...
// backtracking use: 1. avoid faltu call (prone)
            //       2. revert the state to original after fn call step (reversal)












// backtrack karte time apne original state me revert back karte jao...
// string ko byreference pass karenge... otherwise pehle call by value mai bahut jyada
// space lag rha tha ab hum output string nahi banayenge....

// unordered set se trace bhi karte rahenge ki kaun kaun si call hogayi hai aur kaun si baaki hai
