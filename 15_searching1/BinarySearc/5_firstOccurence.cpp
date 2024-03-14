// find the first occurence in array..
#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,2,2,3,3,3,5,5,5,5,8,8,9};
    int n=14; //size of array
    int x=3; // target element

    int lo = 0;
    int hi = n-1;
    bool flag= false;

    
    while (lo<=hi){
        int mid = (lo+hi)/2;
        if (arr[mid]==x){ // ab iske andar do cases aur dekhne hai.
                            // kyuki repetition hai..
            if (arr[mid-1]!=x){ // uske just pehle waala uske equal nahi aaya matlab yahi hai ans..
                flag=true;
                cout<<"first occuring index is: " <<mid<<endl;
                break;

            }
            else{ // arr[mid-1]=x  // agar uske just pehle waala bhi x ke equal aa gya to 
                    // phir hi ko dekho...
                 hi = mid-1;
            }
        }
    }

}

/*
given a sorted array of n elements and a target x. find the first occurence of x
in the array. if x does not exist return -1;


*/