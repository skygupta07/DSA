#include <iostream>
using namespace std;
void display(vector <int> &a){  // function to display the array you can pass a or &a
    for (int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;  // void function can take input print output perform calculations
                    // just it don't return anything..
}

int main(){
    vector <int> v1;
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(9);
    v1.push_back(12);
    v1.push_back(20);
    v1.push_back(35);

    display(v1);  // function call karte waqt to jo bhi paramter daale the unko dhyan me rakhte hue
                    // sach me uss value ko pass karo..

    vector <int> v2(v1.size());
    for (int i=0; i<v2.size(); i++ ){
        //i + j = size-1
        int j= v1.size()-1-i;
        v2[i]= v1[j];
    }

    display(v2); // print vector in reverse order  
}
