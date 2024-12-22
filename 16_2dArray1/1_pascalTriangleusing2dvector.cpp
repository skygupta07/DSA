#include <iostream> 
#include <vector>
using namespace std;
int main(){
    int m=5;   // number of rows of pascal triangle
    vector < vector <int> > v;  // ek 2d vector banaya v name se 
    // yaha mene starting mai hi vector ko initialise nahi kiya....matlab mere pe abhi 
    // freedom hai ki mai kitne bhi vector aur kisi bhi size ke vector ko push kar sakta hu..
    for (int i=1; i<=m; i++){
        vector <int> a(i);   // variable size ka vector banaya
                            // aur ussey apne 2d vector me pushback kiya 
                    // advantage of using 2d vector that we can pushback vector of variable sizes in a 2d vector
        v.push_back(a);

    }
    // generating values..

    for (int i=0; i<m; i++){
        for (int j=0; j<=i; j++){
            if (j==0 || j==i){
                v[i][j]=1;
            }
            else{
                v[i][j]= v[i-1][j]+v[i-1][j-1];   // theek upar wala plus upar wale ke bagal wala 
            }

        }
        
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<=i; j++){
            cout<<v[i][j]<<" ";

        }
        cout<<endl;
    }


}