// IMPORTANT concept of vectors, recursion, sorting, merging arrays..

#include <bits/stdc++.h>
using namespace std;


void print(vector<int> v){
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

void merge(vector<int> &a, vector<int> &b, vector<int> &res) {

    // function to merge two sorted arrays..
    // vectors are passed by reference always...
    int i = 0; // for vector a
    int j = 0; // for b
    int k = 0; // for tracking index of resultant...

    while (i<a.size() && j<b.size()){
        if (a[i]<b[j]){
            res[k++]=a[i++];
        }
        else{
            res[k]=b[j];
            k++;
            j++;
        }
    }
// two pointer bethaya and jo bhi unme se chotta hoga ussey include kar lena...
// agar aisa ho jae ki vector a ya vector b pehle hi khatam ho jae tab 
// to phir jis bhi vector ke kucch element bach rahe honge wo directly hi resultant vector me aa jaenge..


    if(i==a.size()){   // i.e. i is at end of vector a.. a khatam hogaya but b me abhi element hai..
        while (j<b.size()){  //(size-1) index tak hi to rahega...
            res[k]=b[j];
            k++;
            j++;
        }
    }

    if(j==b.size()){ // matlab b khatam ab to vector a game dikhayega..
        while (i<a.size()){
            res[k++]=a[i++];
        }
    }

    // for (int i=0; i<res.size(); i++){
    //     cout<<res[i]<<" ";
    // }

}

// int main(){
//     int arr[]={1,2,5,8,16};
//     int brr[]={3,4,7,10,15,18};

//     int n1 = sizeof(arr)/sizeof(arr[0]);
//     int n2 = sizeof(brr)/sizeof(brr[0]);

    

//     vector <int> a(arr, arr+n1);
//     // issey ek vector a name se ban gaya aur usme array arr ke saare element dal gaye..
//     vector <int> b(brr, brr+n2);
//     // vector isliye banaya taki merge() naam ke function me arr aur brr ka size na pass karna pade..
//     vector <int> res(n1+n2);
//     // simply vector declare karne ke liye to vector <int> vname(vsize);
    
    
//    merge(a,b,res); 
//    cout<<endl;

// }

void mergesort(vector<int> &v){  // bhaisaab ab samjha vector me address bhejna jaruri kyu hai
// vectors are passed by reference..
// aur ha vector bhi isliye hi banaya tha taki function me pass karte waqt kewal vector hi pass karna ho
// saath me ab size na pass karna pade
    
    int n = v.size(); // is function me use karne ke liye to size ko dubara nikalna hi padega
    if (n == 1) return;  // base case -> important.... kyuki yaha recursion ki call lag rahi h
    // jab 1 size ka array aa jaega then usko further break karne ki koi need nahi
    // since single size array is already sorted

    int n1 = n/2;
    int n2 = n-n/2;
    
    // step 1.
    vector <int> a(n1), b(n2); // divided vectors declaration
    // now filling elements into it..
    
    for (int i=0; i<n1; i++){ // vector a aur b bana 
        a[i]=v[i];
    }

    for (int j=0; j<n2; j++){
        b[j]=v[j+n1];  // j+n1 because aage ke bachhe v ke elements hi to daalega b me..
    }
     
     // step 2. recursion magic..
     mergesort(a); // imp
     mergesort(b);
     

     //step 3. merge the small small steps
     merge(a,b,v); // a aor b vector ko merge kar do vector v me..

     a.clear();
     b.clear();  // to reduce space complexity

}


int main(){
    int arr[]={8,3,2,4,1,10,12,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // pehle array banate hai then vector me array ko copy paste marte hai taqi wo baar baar push_back()
    // wala operation na karna pade.. aur arr.size() wala bhi kaam nikalwa sake...

    vector <int> v(arr, arr+n);  // copying array element into vector...

    print(v);
    cout<<endl;

    mergesort(v);  // fn call

    print(v);
    cout<<endl;
}

// algorithm of Merge Sort
// 1. divide and conquer: divide the vector into two pieces..(i.e. make two vector of size: n/2, n-n/2)
// 2. magic: sort the smaller divided vectors using recursion..(base case)
// 3, merge Two sorted vector..

// time complexity: O(nlogn) i.e. good
// merge sort is stable sort
// space complexity: O(nlogn) kyuki har baar aap naya vector bana rahe of n + n/2 + n/4

// to improve s.c. we can clear the vector after merging them
