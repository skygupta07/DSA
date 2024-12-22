#include <iostream>
using namespace std;

// after call
void print (int n){
   if (n==0) return;
   print (n-1);
   cout<<n<<endl; // wapas aate waqt execute
}

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    print(n);
}