#include <iostream>
using namespace std;

// source row, source column , ending row , ending col
int maze(int sr, int sc, int er, int ec){
    if (sr==er && sc==ec) return 1;
    if (sr>er || sc>ec) return 0;
    int rightways = maze(sr, sc+1, er, ec);
    int downways = maze(sr+1, sc , er ,ec);
    int totalways = rightways + downways;
    return totalways;
}

void printpath(int sr, int sc, int er, int ec, string s){
    if (sr>er || sc>ec) return;
    if (sr==er && sc==ec) cout<<s<<endl;  // har method se pahuchne ka ways string me store karega..
    printpath(sr, sc+1, er, ec,s+"R");
    printpath(sr+1, sc , er ,ec, s+"D"); 
}


int main(){
    // maze path:
    // number of ways to reach the destination from the beginning...
    // allowed steps are: right and down only..


    cout<<"number of ways to go from (1,1) to destination is: " << maze(1,1,3,3) <<endl;

    cout<<"path followed is: "<<endl;
    printpath(1,1,3,3,"");
                            // empty string passed to store the path..
}


// simply concatenating one string to another by plus sign..