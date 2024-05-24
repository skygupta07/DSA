#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, vector<int> &b, vector<int> &res) {
    int i = 0; // for vector a
    int j = 0; // for b
    int k = 0; // for tracking index of resultant...

    while (i<a.size() && j<b.size()){   // agar koi bhi ek array complete ho gayi
    // to loop ko tod do to avoid index out of bound error...
    
        if (a[i]<b[j]){
            res[k++]=a[i++];    // winner will be putted and incremented also
        }
        else{
            res[k]=b[j];
            k++;
            j++;
        }
    }

// agar aisa ho jae ki vector a ya vector b pehle hi khatam ho jae tab 
// to phir jis bhi vector ke kucch element bach rahe honge wo directly hi resultant vector me aa jaenge..

// for remaining element
// i index a ko paar kar gaya hoga tab check hogi condition...
    if(i==a.size()){
        while (j<b.size()){
            res[k]=b[j];
            k++;
            j++;
        }
    }


    if(j==b.size()){ // matlab b khatam ab to vector a game dikhayega..
        while (i<a.size()){
            res[k]=a[i];
            k++;
            i++;
        }
    }

    for (int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

}

int main(){
    int arr[]={1,2,5,8,16};
    int brr[]={3,4,7,10,15,18};

    int n1 = sizeof(arr)/sizeof(arr[0]);
    int n2 = sizeof(brr)/sizeof(brr[0]);

    

    vector <int> a(arr, arr+n1);
    // issey ek vector a name se ban gaya aur usme array arr ke saare element dal gaye..
    vector <int> b(brr, brr+n2);
    // vector isliye banaya taki merge() naam ke function me arr aur brr ka size na pass karna pade..
    vector <int> res(n1+n2);
    // simply vector declare karne ke liye to vector <int> vname(vsize);
    
    
   merge(a,b,res); 
   cout<<endl;
    
}

/*
1. vector <int> v(5);
v.push_back(1);
v.push_back(2);
v.push_back(5);

// 5 size ka vector ban jaega aur sab initially zero se initialise honge....
now if you are pushing back element then v = {0,0,0,0,0,1,2,5} will be pushed...
this the reason why we clear the vector if we mentioned the size.

1. agar vector mai push_back karna hai ginte ke element to size mat mention karo....
2. but agar vector ka index se khelna hai element update karte huye to aap size mention karlo


m2 vector<int> v;
v.push_back(1);
v.push_back(2);

ab yaha theek hai simply v = {1,2} fill hoga







*/