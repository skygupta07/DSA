#include <iostream>
using namespace std;
void permutation(string &str, int i){   // original string passed by reference
    if (i == str.size()-1){  // base case
        cout<<str<<"\n";
        return;
    }

    for(int idx = i; idx < str.size(); idx++){
        swap(str[idx] , str[i]);    // work
        permutation(str , i+1);     // fn call 
        swap(str[idx] , str[i]);  // revert work ->again swapped after fn call for backtracking
    }
}


int main(){
    string str = "abc";
    permutation(str, 0);
    return 0;
}



// but this will not work for repetition of words...
// i.e. only for distinct words
/*
here no need to create output strings instead swap in the original string and see permutation



*/












// backtrack karte time apne original state me revert back karte jao...

// apni string ko hi by reference pass karenge... otherwise pehle call by value mai bahut jyada
// space lag rha tha ab hum output string nahi banayenge.... 