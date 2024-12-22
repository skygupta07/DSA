#include <iostream>
using namespace std;
int main(){
    string s;
    int arr[100];
    cout<<"enter the string: ";
    getline (cin, s);  // to take input a string ..
    int k=0;
    

    
    int n = s.length(); // to find length of string..
    for (int i=0; i<n; i++){
        int count = 0; // smart technique to declare the count variable in between so that for the next 
                        // value of i count gets reset to 0 again for the next element..

        for (int j=i; j<n; j++){
            if (s[i]==s[j]){
                count++;
                
            }
        }
        arr[k]=count;
        k++;
    }

    int max = arr[0];
    int n= sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n; i++){
        if (arr[i]>max){
            arr[i]=max;
        }
    }

    cout<<"most occuring character occurs "<<max <<"times. "<<endl;

}