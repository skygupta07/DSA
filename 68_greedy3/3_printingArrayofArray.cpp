#include <iostream>
#include <vector>
using namespace std;

int main(){
    int v[5][5];
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            v[i][j] = i + j;
        }
    }

    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cout<<i<<','<<j<<"  ";
        }
        cout<<endl<<endl;
    }


}