#include <iostream>
using namespace std;
int main(){
    int a[2][3]={1,3,5,
                 7,2,4};
   

    cout<<"displaying the matrix a..."<<endl;
    for (int i=0; i<2; i++){    // no of rows
        for (int j=0; j<3; j++){    // no. of cols
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    
    cout<<"dispaying the transpose matrix..."<<endl;
    for (int j=0; j<3; j++){    // loop ab transpose matrix ke according chalao
                                // i.e. bahar no. of columns then andar no of rows original array ka
        for (int i=0; i<2; i++){
            cout<<a[i][j]<<" ";

        }
        cout<<endl;
    }


}


// accha waha same hi matrix ya 2d vector mai change karna tha.....
// isliye reference se bheja tha...