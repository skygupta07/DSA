#include <iostream>
using namespace std;

int main(){
    int m,n,p,q;
    cout<<"enter the no. of rows of 1st matrix: ";
    cin>>m;
    cout<<"enter the no. of cols of 1st matrix: ";
    cin>>n;
    cout<<"enter the no. of rows of 2nd matrix: ";
    cin>>p;
    cout<<"enter the no. of cols of 2nd matrix: ";
    cin>>q;

    if (n==p){  //condition for possible matrix multiplication..
        int a[m][n];    // first input mastrix
        int b[p][q];    // second input matrix
        int c[m][q];    // resultant matrix
        cout<<"enter the elements of matrix a: "<<endl;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                cin>>a[i][j];
            }
        }        
        cout<<endl;

        
        cout<<"enter the elements of matrix b: "<<endl;
        for (int i=0; i<p; i++){
            for (int j=0; j<q; j++){
                cin>>b[i][j];
            }
        }
        cout<<endl;

        cout<<"printing matrix a: "<<endl;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"printing matrix b: "<<endl;
        
        for (int i=0; i<p; i++){
            for (int j=0; j<q; j++){
                cout<<b[i][j]<<" ";

            }
            cout<<endl;
        }
        // calculating the matrix c...  #important
        
        for (int i=0; i<m; i++){  // loop to matrix c ke liye hi chalega...
            for (int j=0; j<q; j++){
                c[i][j]=0;
                for (int k=0; k<n; k++){    // n=p wala ab role dikhaya
                    c[i][j]+=a[i][k]*b[k][j];  //imp

                }
            }
        }

        cout<<"printing the desired multiplicative matrix: "<<endl;
        for (int i=0; i<m; i++){
            for (int j=0; j<q; j++){
                cout<<c[i][j]<<" ";

            }
            cout<<endl;
        }
        


    }

    else{
        cout<<"matrix multiplication is not possible. "<<endl;

    }
}