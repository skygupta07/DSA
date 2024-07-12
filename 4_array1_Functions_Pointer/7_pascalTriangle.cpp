#include <iostream>
#include <vector>
using namespace std;


int fact(int n){
    if (n==0) return 1;
    int ans = 1;
    for (int i=n; i>=1; i--) ans *= i;   // ha ha jo left side mai initialise kiya hota hai wahi variable use
                                        // karte hai loop mai.... 
    return ans; 
}

int combi(int n, int r){
    return fact(n)/(fact(r)*fact(n-r)); // but we are calculating the repetitive factorial again 
                                            // and again....
}


int main(){
    cout<<"enter n: ";
    int n;
    cin>>n;

    for (int i=0; i<=n; i++){
        cout<<combi(n,i)<<" ";
    }
    cout<<endl;
}





/*

0c0

1c0 1c1

2c0 2c1 2c2 

3c0 3c1 3c2 3c3 

4c0 4c1 4c2 4c3 4c4



ncr = nfact/rfact*(n-r)fact

*/