#include <iostream>
using namespace std;
int main(){
    int m = 3;
    int n = 4;
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int minr=0;
    int maxr=m-1;
    int minc=0;
    int maxc=n-1;

    // steps: right down left up 

    while (minr<=maxr and minc<=maxc){
        //right
        for (int j=minc; j<=maxc; j++){
            cout<<arr[minr][j]<<" ";
        }
        minr++;
        if (minr > maxr || minc > maxc ) break;
        //down
        for (int i=minr; i<=maxr; i++){
            cout<<arr[i][maxc];
        }
        maxc--;

        //left 
        if (minr > maxr || minc> maxc ) break;
        for (int j=maxc; j>=minc; j--){
            cout<<arr[maxr][j]<<" ";
        }
        maxr--;

        //up
        if (minr > maxr || minc> maxc ) break;
        for (int i=maxr; i>=minr; i--){
            cout<<arr[i][minc]<<" ";

        }
        minc++;
    }

}