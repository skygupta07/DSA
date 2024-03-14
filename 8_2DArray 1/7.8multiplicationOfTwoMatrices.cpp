#include <iostream>
using namespace std;
int main(){
    int a[2][3]={1,2,3,4,5,6};
    int b[3][2]={7,8,9,1,2,3};
    cout<<"matrix a: "<<endl;
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"matrix b: "<<endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    // calculating matrix multiplication..
    int c[2][2];
        // three loops required
    
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                c[i][j]=0;
                for (int k=0; k<3; k++){ // jo check karta hai multiplication criteria
                    c[i][j]+=a[i][k]*b[k][j];  // important here k varies while row and column remain same
        }

                }
                
    


    }
   // printing the final matrix
   cout<<"resultant multiplicative matrix is: "<<endl;
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }


}