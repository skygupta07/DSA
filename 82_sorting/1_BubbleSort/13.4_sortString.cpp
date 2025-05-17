// Q-> sort string afer removing char less than x
#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string &str){
     
    int n = str.length(); 
    for (int i=0; i<n-1; i++){
        bool flag = true;   // assuming array is already sorted
            // taki har loop me update hoke check hoti rahe value
        for (int j=0; j<n-1-i; j++){   // i aur ghata diya
            if (str[j]>str[j+1]){
                swap(str[j],str[j+1]);
                flag = false;   // agar values swap karni pad rahi hai matlab array not sorted

            }
        }
        if (flag==true){  // means no swapping was done and array is sorted
            break;
        }
    }
}


int main(){
    string s = "XTYVBASXYZERXY";
    string str;
    int n = s.length();

    // removing char less than x
    for (int i=0; i<n; i++){
        if (s[i] >= 'X'){ // imp to put a character(ek akshar) in single quote
            str.push_back(s[i]);
        }
    }
    // sorting string str
    bubbleSort(str);
    // reversing 
    
    reverse(str.begin(), str.end());
    cout<<str;

}

// if else statement aapka character value ko compare allow karta hai a>A

