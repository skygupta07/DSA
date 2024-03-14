#include <iostream>
using namespace std;


void print(vector <int> v){
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

void bubbleSort(vector<int> &v){
     
    int n = v.size(); 
    for (int i=0; i<n-1; i++){
        bool flag = true;   // assuming array is already sorted
            // taki har loop me update hoke check hoti rahe value
        for (int j=0; j<n-1-i; j++){   // i aur ghata diya
            if (v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                flag = false;   // agar values swap karni pad rahi hai matlab array not sorted
            }
        }

        if (flag==true){  // means no swapping was done and array is sorted
            break;
        }
        
    }
}

int main(){
    int arr[] = {4,2,5,1,9,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);  
    print(v);
    cout<<endl;
    bubbleSort(v); 
    print(v);
}

// for more optimization
// j wale loop me i aur ghata diya 
// aur har loop ke iteration se pehle ye check kar sakta hu ki kahi mera vector already sorted to nahi hai
// agar pure array me iterate kara aur ek baar bhi swap nahi hota iska matlab alreay sorted tha 
//iske liye bool flag laga lo (no. of passes may reduce)
// break us loop ko khatam karta hai jiske andar hai wo

// best case: -> O(n)
// bubble sort is stable sort
// max swaps required to sort array of size 6 is = 6*5/2 =15;