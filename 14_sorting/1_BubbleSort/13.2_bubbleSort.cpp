#include <iostream>
using namespace std;


void print(vector <int> v){
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

void bubbleSort(vector<int> &v){  // if I by mistake pass here vector<int> v  only then 
                            // copy of vector would be passed so no changes occur.
                    // so always pass vector by reference
    int n = v.size(); 
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1; j++){  // inner loop bhi aapka n-1 chalaya last element ko consider
                        // kiya to uske aage wo kis se compare karta!!
            if (v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}
// TC = O(n^2);  or n-i-1 karke O(n*(n-1))/2 == O(n^2/2)
// SC = O(1) // because me original hi vector ko modify kar rha hu koi nayi vector thodi bna rha hu
// dekh beech me agar ek condition check karke apne paases ko kam kar rha hu to wo acchi baat hai

int main(){
    int arr[] = {4,2,5,1,9,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);  // creating vector because i dont want to pass size also
    
    print(v);
    cout<<endl;
    bubbleSort(v); 
    print(v);
}