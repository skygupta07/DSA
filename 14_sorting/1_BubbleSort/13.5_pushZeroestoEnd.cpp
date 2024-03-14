// push zeroes to end while maintaining the relative order of other elements (Bubble sort use)

#include <iostream>
using namespace std;

void print(vector <int> v){
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

void bubbleZeroToEnd(vector<int> &v){
     
    int n = v.size(); 
    for (int i=0; i<n-1; i++){
        bool flag = true;   // assuming array is already sorted
            // taki har loop me update hoke check hoti rahe value
        for (int j=0; j<n-1-i; j++){   // i aur ghata diya
            if (v[j]==0){  // ONLY ONE CHANGE from bubble sort
                swap(v[j],v[j+1]);
                flag = false;   // agar values swap karni pad rahi hai matlab array not sorted

            }
        }
        if (flag==true){  // means no swapping was done and array is sorted
            break;
        }
    }
}




// without optimised wala bhi laga sakta tha



int main(){
    int arr[]={5,0,1,2,0,0,4,0,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    
    print(v);
    cout<<endl;
    bubbleZeroToEnd(v);
    
    print(v);
}

